#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int n, m, f;
struct adnorm
{
    int ri;
    int ci;
    int di;
    int vi;
};
vector<vector<int>> map;
vector<vector<int>> time_map;
vector<adnorm> ad;

// 시간의 벽 -> 탈출
pair<int, int> time_wall(int wex, int wey)
{
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    pair<int, int> go_wall;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int l = 0; l < 4; l++)
            {
                if (map[wex - i + dx[l]][wey - j + dy[l]] == 0)
                {
                    go_wall = {wex - i, wey - j};
                }
            }
        }
    }

    int dgox = m - 1 - (wex - go_wall.first) + m;
    int dgoy = m - 1 - (wey - go_wall.second) + m;
    int ddgoy, ddgox;
    if (dgoy == 2 * m - 1)
    {
        ddgoy = dgoy + m;
    }
    else if (dgoy == m)
    {
        ddgoy = dgoy - m;
    }
    // cout << dgox << ' ' << dgoy << ' ' << ddgoy << '\n';
    if (time_map[dgox][ddgoy] == 0)
    {
        return {dgox, ddgoy};
    }

    if (dgoy == 2 * m - 1)
    {
        ddgox = dgox + m;
    }
    else if (dgox == m)
    {
        ddgox = dgox - m;
    }
    if (time_map[ddgox][dgoy] == 0)
    {
        return {ddgox, dgoy};
    }
}
// 미지의 공간 -> 탈출

// 시간 이상 현상 확산 -> map에 장애물로
void spread_ad(int d)
{
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    for (int i = 0; i < f; i++)
    {
        if (!ad[i].vi % d)
        {
            ad[i].ri += dx[ad[i].di];
            ad[i].ci += dy[ad[i].di];

            map[ad[i].ri][ad[i].ci] = 1; // 장애물
        }
    }
}

int bfs_wall(int &cx, int &cy, pair<int, int> &go_wall)
{
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int size = m * 3;
    queue<pair<int, int>> q;
    q.push({cx, cy});
    time_map[cx][cy] = 10;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (cx == go_wall.first && cy == go_wall.second)
            return time_map[cx][cy] - 10;

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= size || ny < 0 || ny >= size || time_map[nx][ny] == 1)
                continue;

            // 1
            if (nx == 2 && ny < 3)
            {
                nx = ny;
                ny = 3;
            }
            else if (ny == 2 && nx < 3)
            {
                ny = nx;
                nx = 3;
            }

            // 2
            if (nx == 2 && ny > 5)
            {
                nx = 3 * n - 1 - ny;
                ny = 5;
            }
            else if (ny == 6 && nx < 3)
            {
                ny = 3 * n - 1 - nx;
                nx = 3;
            }

            // 3
            if (nx == 6 && ny < 3)
            {
                nx = ny + 6;
                ny = 3;
            }
            else if (ny == 2 && nx > 5)
            {
                ny = 8 - nx;
                nx = 5;
            }

            // 4
            if (nx == 6 && ny > 5)
            {
                nx = ny;
                ny = 5;
            }
            else if (ny == 2 && nx > 5)
            {
                ny = nx;
                nx = 5;
            }
            if (time_map[nx][ny] == 0)
            {
                cout << nx << ny << '\n';
                time_map[nx][ny] = time_map[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> f;
    map.assign(n, vector<int>(n, 0));
    time_map.assign(m * 3, vector<int>(m * 3, -1));

    // 미지의 공간 입력
    int wex, wey;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 3)
            {
                wex = i;
                wey = j;
            }
        }
    }

    // 동
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> time_map[m + (m - 1 - j)][2 * m + i]; // 90도 반시계 방향 회전
        }
    }

    // 서
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> time_map[m + j][m - 1 - i]; // 90도 시계 방향 회전
        }
    }

    // 남
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> time_map[2 * m + i][m + j];
        }
    }

    // 북
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> time_map[i][m + j];
        }
    }

    // 위
    int cx, cy;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> time_map[m + i][m + j];
            if (time_map[m + i][m + j] == 2)
            {
                cx = m + i;
                cy = m + j;
            }
        }
    }

    for (int i = 0; i < f; i++)
    {
        adnorm adnormx;
        cin >> adnormx.ri >> adnormx.ci >> adnormx.di >> adnormx.vi;
        ad.push_back(adnormx);
    }

    // for (int i = 0; i < m * 3; i++)
    // {
    //     for (int j = 0; j < m * 3; j++)
    //         cout << time_map[i][j];
    //     cout << '\n';
    // }
    // 시간의 벽에서 이동

    pair<int, int> go_wall = time_wall(wex, wey);
    // cout << go_wall.first << go_wall.second << '\n';

    int answer = bfs_wall(cx, cy, go_wall);
    if (answer == -1)
    {
        cout << -1 << '\n';
        return 0;
    }
    cout << answer << '\n'; // 18

    for (int i = 1; i <= answer; i++)
    {
        spread_ad(i);
    }

    return 0;
}