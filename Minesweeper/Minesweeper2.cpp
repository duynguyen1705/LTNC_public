#include<iostream>
#include<stdio.h>
#include<ctime>

using namespace std;

const int MAX_WIDTH  = 11;
const int MAX_HEIGHT = 11;
char Map[MAX_WIDTH][MAX_HEIGHT];
void setMap();
int mapBomb[MAX_WIDTH][MAX_HEIGHT];
int w, h;
int guessBomb;
int emptyP;
int Step = 0;
#define DIRECTION 8
int dx[DIRECTION] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[DIRECTION] = {-1, 0, 1, -1, 1, -1, 0, 1};
void chooseBomb();
void printMap();
void updateMap(int x, int y);
void printBomb();
void playGame();
void replay();
int visited[11][11];
void clearScreen();

int main()
{
    playGame();
    replay();
    return 0;
}

void playGame()
{
    srand(time(0));
    setMap();

    do{
    cout << "Choose your map you want to play (H, W)(H<10 and W<10): ";
    cin >> w >> h;
    }while(w > 10 || h > 10);

    do{
        cout <<"Choose number of bombs you want to guess(<10): ";
        cin >> guessBomb;
    }while(guessBomb > 10);

    emptyP = w*h - guessBomb;
    chooseBomb();

    int x, y;

    do{
        clearScreen();
        printMap();
        cout << endl << "What pix you want to open(x, y): ";
        cin >> x >> y;
        updateMap(x, y);
        if (mapBomb[x][y] == -1 || Step == emptyP) {clearScreen(); printBomb(); break;}
    }while(mapBomb[x][y] != -1 || x > 10 || y > 10 || Step < emptyP);

    if (mapBomb[x][y] == -1) cout << "YOU'RE DEAD";
    if (Step == emptyP) cout << "You win";
    cout << endl;
}

void countBombAround(int x, int y)
{
    if (mapBomb[x][y] == -1) return;
    int countB = 0;
    for (int i = 0; i < DIRECTION; i++)
        if (mapBomb[x+dx[i]][y+dy[i]] == -1) countB++;
    mapBomb[x][y] = countB;
}
void chooseBomb()
{
    int countBomb = 0;
    while(countBomb < guessBomb)
    {
        int x = rand() % w + 1;
        int y = rand() % h + 1;
        if(mapBomb[x][y] != -1)
        {
            mapBomb[x][y] = -1;
            countBomb++;
        }
    }
    for (int i = 1; i <= w; i++)
        for (int j = 1; j <= h; j++)
            countBombAround(i, j);
}

void printMap()
{
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= h; j++)
            cout << Map[i][j] << " ";
        cout << endl;
    }
}

void printBomb()
{
   for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= h; j++)
            cout << mapBomb[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void updateMap(int x, int y)
{
    Map[x][y] = char(48+mapBomb[x][y]);
    Step++;
    visited[x][y] = 1;
    if (mapBomb[x][y] > 0) return;
    for (int i = 0; i < DIRECTION; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx >= 1 && nx <= w && ny >= 1 && ny <= w && visited[nx][ny] == 0) updateMap(nx, ny);
    }
}

void setMap()
{
    for (int i = 0; i < MAX_WIDTH; i++)
    for (int j = 0; j < MAX_HEIGHT; j++)
    {
        Map[i][j] = '*';
        mapBomb[i][j] = 0;
        visited[i][j] = 0;
    }
}

void replay()
{
    char x;
    do
    {
        cout << "Do you want to play again(Y/N): ";
        cin >> x;
    }while(x != 'Y' && x!= 'N');
    if(x == 'Y') playGame();
    else cout << "Have fun! See you again!!!";
}

void clearScreen()
{
    const int PATCH_LINES = 30;
	for (int i = 0; i < PATCH_LINES; i++) 
        cout << endl;
}
