#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<bool>> visited;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void bfs()
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (map[nx][ny] == 1 && !visited[nx][ny])
                {
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                    map[nx][ny] = map[cx][cy] + 1;
                }
            }
        }
    }

    cout << map[n - 1][m - 1] << '\n';
}

int main()
{
    cin >> n >> m;
    string s;
    map.resize(n);
    visited.resize(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (char c : s)
        {
            map[i].push_back(c == '0' ? 0 : 1);
        }
    }
    bfs();
    return 0;
}