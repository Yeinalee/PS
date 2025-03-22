#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int n, m, k;

void bfs(vector<vector<vector<int>>> &map)
{
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    map[0][0][0] = 1;

    while (!q.empty())
    {
        int cx = get<0>(q.front());
        int cy = get<1>(q.front());
        int break_wall = get<2>(q.front());
        q.pop();

        if (cx == n - 1 && cy == m - 1)
        {
            cout << map[cx][cy][break_wall] << '\n';
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (map[nx][ny][0] == 0 && map[nx][ny][break_wall] == 0) // 벽이 아닌 곳
                {
                    map[nx][ny][break_wall] = map[cx][cy][break_wall] + 1;
                    q.push({nx, ny, break_wall});
                }
                else if (map[nx][ny][0] == -1 && break_wall < k && map[nx][ny][break_wall + 1] == 0) // 벽인 곳
                {
                    map[nx][ny][break_wall + 1] = map[cx][cy][break_wall] + 1;
                    q.push({nx, ny, break_wall + 1});
                }
            }
        }
    }

    cout << -1 << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    vector<vector<vector<int>>> map(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '1')
            {
                map[i][j][0] = -1;
            }
        }
    }

    bfs(map);
    return 0;
}