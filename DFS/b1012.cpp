#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<bool>> map;
vector<vector<bool>> visited;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void dfs(int i, int j)
{
    vector<pair<int, int>> q;
    q.push_back({i, j});
    visited[i][j] = 1;

    while (!q.empty())
    {
        int x = q.back().first;
        int y = q.back().second;
        q.pop_back();
        for (int a = 0; a < 4; a++)
        {
            int nx = x + dx[a];
            int ny = y + dy[a];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                if (visited[nx][ny] == 0 && map[nx][ny] == 1)
                {
                    visited[nx][ny] = 1;
                    q.push_back({nx, ny});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, k, a, b, cnt;
    cin >> t;
    while (t--)
    {
        cin >> m >> n >> k;
        map.assign(m, vector<bool>(n, 0));
        visited.assign(m, vector<bool>(n, 0));

        while (k--)
        {
            cnt = 0;
            cin >> a >> b;
            map[a][b] = 1;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == 0 && map[i][j] == 1)
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}