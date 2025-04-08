#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m, h, k;
vector<vector<int>> map;
struct catcher
{
    int x;
    int y;
    int d;
};
catcher c = {n / 2, n / 2, 3}; // 술레 위치, 방향

// 도망자 이동
void move_runner()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 도망자
            int d = map[i][j];
            if (d >= 0 && d <= 3)
            {
                // 술레와 거리가 4이상이면 움직이지 않음
                if (abs(c.x - i) + abs(c.y - j) >= 4)
                    continue;

                // 왼쪽
                if (d == 0)
                {
                    if (j == 0 && c.x != i && c.y != 1) // 경계
                    {
                        map[i][j] = -1;
                        map[i][1] = 1; // 오른쪽 방향으로 이동
                    }
                    else if (c.x != i && c.y != j - 1)
                    {
                        map[i][j] = -1;
                        map[i][j - 1] = 0; // 왼쪽으로 이동
                    }
                }

                // 오른쪽
                else if (d == 1)
                {
                    if (j == n - 1 && c.x != i && c.y != n - 1) // 경계
                    {
                        map[i][j] = -1;
                        map[i][n - 2] = 0; // 왼쪽 방향으로 이동
                    }
                    else if (c.x != i && c.y != j - 1)
                    {
                        map[i][j] = -1;
                        map[i][j + 1] = 0; // 오른쪽으로 이동
                    }
                }

                // 아래쪽
                else if (d == 2)
                {
                    if (i == n - 1 && c.x != n - 2 && c.y != j) // 경계
                    {
                        map[i][j] = -1;
                        map[n - 2][j] = 3; // 위쪽 방향으로 이동
                    }
                    else if (c.x != i + 1 && c.y != j)
                    {
                        map[i][j] = -1;
                        map[i + 1][j] = 2; // 아래으로 이동
                    }
                }

                // 위쪽
                else if (d == 3)
                {
                    if (i == 0 && c.x != 1 && c.y != j) // 경계
                    {
                        map[i][j] = -1;
                        map[1][j] = 2; // 아래쪽 방향으로 이동
                    }
                    else if (c.x != i - 1 && c.y != j)
                    {
                        map[i][j] = -1;
                        map[i - 1][j] = 3; // 위쪽로 이동
                    }
                }
            }
        }
    }
}

// 술레 이동
void move_catcher()
{
}

// 도망자 잡기
int kill_runner()
{
}

void sol()
{
    int score = 0;

    for (int i = 1; i <= k; i++)
    {
        move_runner();
        move_catcher();
        int n = kill_runner();
        score += n * i;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> h >> k;
    map.assign(n, vector<int>(n, -1));
    map[n / 2][n / 2] = 5; // 술레

    int x, y, d;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> d;
        map[x][y] = d;
    }

    for (int i = 0; i < h; i++)
    {
        cin >> x >> y;
        map[x][y] = 4;
    }

    sol();

    return 0;
}