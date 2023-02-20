#include<iostream>
#include<cstring>

using namespace std;

int m, n;
int matrix[1000][1000];
bool check_visited[1000][1000];
int dx[] = {-1, 0, 1, 0}; // các hướng lên, phải xuống trái
int dy[] = {0, 1, 0, -1};
bool found = false;

void foundTheWay(int x, int y)
{
    check_visited[x][y] = true; // đánh dấu
    if (x == m - 1 && y == n - 1){
        found = true;
        matrix[x][y] = 2;
        return;
    }
    for (int i = 0; i < 4; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && !check_visited[new_x][new_y] && matrix[new_x][new_y] == 0){
            foundTheWay(new_x, new_y);
            if (found){
                matrix[x][y] = 2;
                return; // tìm được thì thoát ra
            }
        }
    }

}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    memset(check_visited, 0, sizeof check_visited);
    foundTheWay(0, 0);

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}
