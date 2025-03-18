#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int n, m;

void bfs(vector<vector<int>> &map)
{
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(2, -1)));
    queue<tuple<int, int, int>> q; //(x, y, 부수기 여부)
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    q.push({0, 0, 0});
    visited[0][0][0] = 1;

    while (!q.empty())
    {
        int cx = get<0>(q.front());
        int cy = get<1>(q.front());
        int wall_b = get<2>(q.front());
        q.pop();

        if (cx == n - 1 && cy == m - 1)
        {
            cout << visited[cx][cy][wall_b] << '\n';
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                // 벽인 경우
                if (map[nx][ny] == 1 && wall_b == 0 && visited[nx][ny][1] == -1)
                {
                    visited[nx][ny][1] = visited[cx][cy][0] + 1;
                    q.push({nx, ny, 1});
                }

                // 벽이 아닌 경우
                else if (map[nx][ny] == 0 && visited[nx][ny][wall_b] == -1)
                {
                    visited[nx][ny][wall_b] = visited[cx][cy][wall_b] + 1;
                    q.push({nx, ny, wall_b});
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
    vector<vector<int>> map(n, vector<int>(m, 0));
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }
    bfs(map);
    return 0;
}