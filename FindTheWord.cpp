#include<bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main()
{
    int m, n;

    cin >> m >> n;

    string matrix[m];

    for(int i = 0; i < m; i++)
        cin >> matrix[i];

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
    string s;
    cin >> s;
    bool check = false;
    for (int i = 0; i < (int)s.length(); i++)
        if (s[i] < 'a' || s[i] > 'z')
        {
            cout << "input error" << endl;
            check = true;
            break;
        }
    int len = s.length();
    int start_x = 0, start_y = 0, end_x = 0, end_y = 0;
    for (start_y = 0; start_y < m; start_y++)
        for (start_x = 0; start_x < n; start_x++)
        {
            end_x = start_x;
            end_y = start_y;
            string res = "";
            for (int i = 0; i < 8; i++)
            {
                end_x = start_x;
                end_y = start_y;
                for (int j = 0; j < len; j++)
                {
                    res = res + matrix[end_y][end_x];
                    if((int)res.length() == len) break;
                    end_x += dx[i];
                    if(end_x >= n || end_x < 0) end_x = abs(abs(end_x)-n);
                    end_y += dy[i];
                    if(end_y >= m || end_y < 0) end_y = abs(abs(end_y)-m);
                }
            //cout << res << endl;
                if (res == s)
                {
                    cout << start_y + 1 << " " << start_x + 1 << " " << end_y + 1 << " " << end_x + 1 << endl;
                    check = true;
                }
                res = "";
            }
        }
    if (!check) cout << "not found" << endl;
    }
}

