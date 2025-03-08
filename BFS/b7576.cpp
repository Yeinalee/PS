#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, n;
vector<vector<int>> map;
queue<pair<int, int>> ripe;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int bfs()
{
    while (!ripe.empty())
    {
        int cx = ripe.front().first;
        int cy = ripe.front().second;
        ripe.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (map[nx][ny] == 0)
                {
                    ripe.push({nx, ny});
                    map[nx][ny] = map[cx][cy] + 1;
                }
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
                return -1;
            if (max < map[i][j])
                max = map[i][j];
        }
    }
    return max - 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x;
    cin >> m >> n;
    map.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            if (x == 1)
                ripe.push({i, j});
            map[i][j] = x;
        }
    }
    cout << bfs() << '\n';
    return 0;
}