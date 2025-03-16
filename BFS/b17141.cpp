#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, ans = 100;
vector<pair<int, int>> virus;
vector<vector<int>> map;

void bfs(vector<pair<int, int>> &v)
{
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<int>> this_v(n, vector<int>(n, -2)); // 바이러스 0, 벽 -1, 빈 공간 -2
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
    {
        this_v[v[i].first][v[i].second] = 0;
        q.push({v[i].first, v[i].second});
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1)
                this_v[i][j] = -1;
        }
    }

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && this_v[nx][ny] == -2)
            {
                this_v[nx][ny] = this_v[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
    int max_t = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (this_v[i][j] == -2)
                return;
            max_t = max(max_t, this_v[i][j]);
        }
    }
    ans = min(ans, max_t);
}

void loc_virus(int start, vector<pair<int, int>> v, int cnt)
{
    if (cnt == m) // m개의 바이러스 설치 완료
    {
        bfs(v);
        return;
    }

    for (int i = start; i < virus.size(); i++)
    {
        v.push_back(virus[i]);
        loc_virus(i + 1, v, cnt + 1);
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    map.assign(n, vector<int>(n, 0));
    int x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            if (x == 1)
            {
                map[i][j] = 1;
            }
            else if (x == 2)
            {
                map[i][j] = 2;
                virus.push_back({i, j});
            }
        }
    }
    vector<pair<int, int>> v;
    loc_virus(0, v, 0);
    cout << (ans == 100 ? -1 : ans) << '\n';
    return 0;
}