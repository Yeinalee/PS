#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;

int bfs(vector<vector<int>> &map, queue<pair<int, int>> q)
{
    vector<int> dx = {-1, 1, 0, 0, -1, -1, 1, 1};
    vector<int> dy = {0, 0, -1, 1, -1, 1, -1, 1};
    int max_dist = 0;
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (map[nx][ny] == -1)
                {
                    map[nx][ny] = map[cx][cy] + 1;
                    max_dist = max(max_dist, map[nx][ny] - 1);
                    q.push({nx, ny});
                }
            }
        }
    }
    return max_dist;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x, max_d = 0;

    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m, -1));
    queue<pair<int, int>> shark;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            if (x)
            {
                shark.push({i, j});
                map[i][j] = x;
            }
        }
    }
    cout << bfs(map, shark) << '\n';
    return 0;
}