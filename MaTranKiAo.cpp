#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int init();
void solve (int size);

int main()
{
    int n = init();

    solve (n);

    return 0;

}

int init()
{
    int num;
    cin >> num;
    return num;
}

void solve (int size)
{
    int Matrix[size][size];
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            Matrix[i][j] = 0;
        }
    }
    int k = 1;
    Matrix[0][size / 2] = k;
    int i = 0;
    int j = 1;
    while(k < size * size)
    {
        if (Matrix[(i - 1 + size) % size][(j + 1) % size] == 0){
            k++;
            Matrix[(i - 1 + size) % size][(j + 1) % size] = k;
            i = (i - 1 + size) % size;
            j = (j + 1) % size;
        }
        else{
            k++;
            Matrix[i + 1][j] = k;
            i++;
        }
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++)
            cout << Matrix[i][j] << " ";
        cout << endl;
    }
}


