#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int n, m;

void bfs(vector<vector<vector<int>>> &map)
{
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    queue<tuple<int, int, bool>> q; //(x, y, break_wall)
    map[0][0][0] = 1;
    q.push({0, 0, 0});

    while (!q.empty())
    {
        int cx = get<0>(q.front());
        int cy = get<1>(q.front());
        bool break_wall = get<2>(q.front());
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
                if (map[nx][ny][break_wall] == 0 && map[nx][ny][0] == 0) // 빈 공간인 경우
                {
                    map[nx][ny][break_wall] = map[cx][cy][break_wall] + 1;
                    q.push({nx, ny, break_wall});
                }
                else if (map[nx][ny][1] == 0 && map[nx][ny][break_wall] == -1 && !break_wall) // 벽인 경우, 아직 부수지 않았다면
                {
                    map[nx][ny][1] = map[cx][cy][0] + 1;
                    q.push({nx, ny, 1});
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
    cin >> n >> m;
    vector<vector<vector<int>>> map(n, vector<vector<int>>(m, vector<int>(2, 0)));
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '1')
                map[i][j][0] = -1;
        }
    }

    bfs(map);
    return 0;
}
