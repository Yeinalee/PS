#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visited;
vector<int> dx = {-1, 1, 0, 0}; // 행 이동
vector<int> dy = {0, 0, -1, 1}; // 열 이동
int n;

int bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    int count = 1;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (map[nx][ny] == 1 && !visited[nx][ny])
                {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> complex;

    cin >> n;
    visited.resize(n, vector<bool>(n, 0));
    map.resize(n);

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (char c : line)
            map[i].push_back(c - '0');
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1 && !visited[i][j])
                complex.push_back(bfs(i, j));
        }
    }

    sort(complex.begin(), complex.end());

    cout << complex.size() << '\n';
    for (int x : complex)
        cout << x << '\n';

    return 0;
}