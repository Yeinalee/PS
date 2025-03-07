#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int k, a, b, c, d;
vector<int> dx = {-2, -1, 1, 2, -2, -1, 1, 2};
vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs()
{
    queue<pair<int, int>> q;
    vector<vector<int>> visited(k, vector<int>(k, -1));

    if (a == c && b == d)
        return 0;

    q.push({a, b});
    visited[a][b] = 0;
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < k && ny >= 0 && ny < k)
            {
                if (visited[nx][ny] == -1)
                {
                    q.push({nx, ny});
                    visited[nx][ny] = visited[cx][cy] + 1;
                }
            }
        }
    }
    return visited[c][d];
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> k;
        cin >> a >> b;
        cin >> c >> d;
        cout << bfs() << '\n';
    }
    return 0;
}