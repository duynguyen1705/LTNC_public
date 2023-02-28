#include<iostream>
#include<ctime>
using namespace std;

struct pixel{
char before = 'X';
bool isBomb = false;
int numOfBomb;
};

struct index{
int x;
int y;
};

int dx[] = {-1,0,1,-1,1,-1,0,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

int choose();
void printFigure(pixel ** matrix, int w, int h);
index initIndex();
void chooseBomb(pixel ** matrix, int w, int h, int guessBomb);
void update(pixel ** matrix, int w, int h, index Index);
int main()
{
    int Weight = choose();
    int Height = choose();
    int guessBomb;
    do{
        guessBomb = choose();
    }while(guessBomb >= Weight*Height);

    pixel** Matrix = new pixel* [Weight + 1];
    for (int i = 0; i < Weight + 1; i++)
        Matrix[i] = new pixel [Height];
    chooseBomb(Matrix, Weight, Height, guessBomb);

    index Index;

    do
    {
        printFigure(Matrix, Weight, Height);
        Index = initIndex();
        update(Matrix, Weight, Height, Index);
    }while(Index.x > Weight || Index.y > Height || Matrix[Index.x][Index.y].isBomb == false);

    if (Matrix[Index.x][Index.y].isBomb == true) cout << "ohh! You lose";

    return 0;
}

int choose()
{
    int n;
    cin >> n;
    return n;
}

index initIndex()
{
    index n;
    cin >> n.x >> n.y;
    return n;
}

int countBombAround(pixel** matrix, int x, int y)
{
    int count = 0;
    for (int i = 0; i < 8; i++){
        if (matrix[x+dx[i]][y+dy[i]].isBomb == true) count++;
    }
    return count;
}
void chooseBomb(pixel** matrix, int w, int h, int guessBomb)
{
    int countBomb = 0;
    while (countBomb < guessBomb)
    {
        srand(time(0));
        int x = rand() % w + 1;
        int y = rand() % h + 1;
        matrix[x][y].isBomb = true;
        countBomb++;
    }

    for (int i = 1; i <= w; i++)
        for (int j = 1; j < h; j++)
            matrix[i][j].numOfBomb = countBombAround(matrix, i, j);
}
void update(pixel** matrix, int w, int h, index Index)
{
    matrix[Index.x][Index.y].before = char(matrix[Index.x][Index.y].numOfBomb + 48);
}
void printFigure(pixel** matrix, int w, int h)
{
    for (int i = 1; i <= w; i++){
        for (int j = 1; j <= h; j++)
            cout << matrix[i][j].before << " ";
        cout << endl;
    }
}
