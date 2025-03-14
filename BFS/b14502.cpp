#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, max_safe = 0;
vector<pair<int, int>> initial_virus;

// 안전 구역 개수, map 얕은 복사
void cnt_safe(vector<vector<int>> &map)
{
    int safe = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
                safe++;
        }
    }
    max_safe = max(safe, max_safe);
    return;
}

// 벽에 세워졌을 때 바이러스가 퍼지는 경우, map 깊은 복사
void bfs(vector<vector<int>> map)
{
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    queue<pair<int, int>> q;
    for (pair<int, int> s : initial_virus)
        q.push(s);

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 0)
            {
                map[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
    cnt_safe(map);
    return;
}

// Brute Force로 벽 3개씩 세우기
void wall(int cnt, vector<vector<int>> &map)
{
    if (cnt == 3)
    {
        bfs(map);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                map[i][j] = 1;
                wall(cnt + 1, map);
                map[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m, 0));
    int x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            map[i][j] = x;
            if (x == 2)
                initial_virus.push_back({i, j});
        }
    }
    wall(0, map);
    cout << max_safe << '\n';
    return 0;
}