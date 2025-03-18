#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void move_map(vector<vector<int>> &map)
{
    for (int i = 7; i >= 0; i--)
    {
        for (int j = 0; j < 8; j++)
        {
            if (map[i][j] == -1)
            {
                map[i][j] = 0;
                if (i + 1 < 8)
                    map[i + 1][j] = -1;
            }
        }
    }
}

void bfs(vector<vector<int>> &map)
{
    vector<int> dx = {0, -1, 1, 0, 0, -1, -1, 1, 1};
    vector<int> dy = {0, 0, 0, -1, 1, -1, 1, -1, 1};
    queue<pair<int, int>> q;
    q.push({7, 0});
    map[7][0] = 1;

    while (!q.empty())
    {
        int sz = q.size();
        for (int k = 0; k < sz; k++)
        {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            if (map[cx][cy] == -1)
                continue;

            for (int i = 0; i < 9; i++)
            {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (nx == 0 && ny == 7)
                {
                    cout << 1 << '\n';
                    return;
                }
                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && map[nx][ny] != -1)
                {
                    q.push({nx, ny});
                }
            }
        }
        move_map(map);
    }
    cout << 0 << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<vector<int>> map(8, vector<int>(8, 0));
    char x;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> x;
            if (x == '#')
            {
                map[i][j] = -1;
            }
        }
    }
    bfs(map);
    return 0;
}