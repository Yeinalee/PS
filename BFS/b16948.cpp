#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, r1, c1, r2, c2;

void bfs(vector<vector<int>> &map)
{
    vector<int> dx = {-2, -2, 0, 0, 2, 2};
    vector<int> dy = {-1, 1, -2, 2, -1, 1};
    queue<pair<int, int>> q;
    q.push({r1, c1});

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (!map[nx][ny])
                {
                    map[nx][ny] = map[cx][cy] + 1;
                    q.push({nx, ny});
                    if (nx == r2 && ny == c2)
                    {
                        cout << map[r2][c2] << '\n';
                        return;
                    }
                }
            }
        }
    }

    cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> r1 >> c1 >> r2 >> c2;
    vector<vector<int>> map(n, vector<int>(n, 0));
    bfs(map);
    return 0;
}