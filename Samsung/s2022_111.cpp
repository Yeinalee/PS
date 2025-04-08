#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m, h, k;
vector<pair<int, int>> tree;
struct person
{
    int x;
    int y;
    int d;
    bool die;
};
person catcher;
vector<person> runner;

// 도망자 이동
void move_runner()
{
    for (int i = 0; i < m; i++)
    {
        int x = runner[i].x;
        int y = runner[i].y;
        int d = runner[i].d;

        // 술레와 거리가 4이상이면 움직이지 않음
        if (abs(catcher.x - x) + abs(catcher.y - y) >= 4)
            continue;

        // 왼쪽
        if (d == 0)
        {
            if (y == 0 && catcher.x != x && catcher.y != 1) // 경계
            {
                runner[i].y = 1;
                runner[i].d = 1; // 오른쪽으로 방향 전환
            }
            else if (catcher.x != x && catcher.y != y - 1)
            {
                runner[i].y--; // 왼쪽으로 이동
            }
        }

        // 오른쪽
        else if (d == 1)
        {
            if (y == n - 1 && catcher.x != x && catcher.y != n - 2) // 경계
            {
                runner[i].y = n - 2;
                runner[i].d = 0; // 왼쪽으로 방향 전환
            }
            else if (catcher.x != x && catcher.y != y + 1)
            {
                runner[i].y++; // 오른쪽으로 이동
            }
        }

        // 아래쪽
        else if (d == 2)
        {
            if (x == n - 1 && catcher.x != n - 2 && catcher.y != y) // 경계
            {
                runner[i].x = n - 2;
                runner[i].d = 3; // 위쪽 방향으로 이동
            }
            else if (catcher.x != i + 1 && catcher.y != y)
            {
                runner[i].x++; // 아래으로 이동
            }
        }

        // 위쪽
        else if (d == 3)
        {
            if (x == 0 && catcher.x != 1 && catcher.y != y) // 경계
            {
                runner[i].x = 1;
                runner[i].d = 2; // 아래쪽 방향으로 전환
            }
            else if (catcher.x != x - 1 && catcher.y != y)
            {
                runner[i].x--; // 위쪽로 이동
            }
        }
    }
}

int len_catcher = 0;
int len_lim = 1;
int mod = 0;
bool is_first = true;
// 술레 이동
void move_catcher()
{
    int x = catcher.x;
    int y = catcher.y;
    int d = catcher.d;

    // 방향 전환
    if (len_catcher == len_lim)
    {
        if (is_first)
        {
            is_first = false;
            len_catcher = 0;
        }
        else
        {
            is_first = true;
            len_catcher = 0;
            len_lim++;
        }
        // 안 -> 밖
        if (mod == 0)
        {
            if (d < 3)
                d++;
            else
                d = 0;
        }

        // 밖 -> 안
        if (mod == 1)
        {
            if (d > 0)
                d--;
            else
                d = 3;
        }
    }

    // 직진
    if (len_catcher < len_lim)
    {
        len_catcher++;
        if (d == 0)
            catcher.x--;
        else if (d == 1)
            catcher.y++;
        else if (d == 2)
            catcher.x++;
        else if (d == 3)
            catcher.y--;
    }

    if (catcher.x == 0 && catcher.y == 0)
    {
        mod = 1;
        catcher.d = 2;
    }

    if (catcher.x == n / 2 && catcher.y == n / 2)
    {
        mod = 0;
        catcher.d = 0;
    }
}

// 도망자 잡기
int kill_runner()
{
    int n = 0;
    vector<int> view;
    // 위
    if (catcher.d == 0)
    {
        for (int i = 0; i < 3; i++)
        {
            if (catcher.x - i >= 0)
                view.push_back(catcher.x - i);
        }
    }

    // 아래
    else if (catcher.d == 2)
    {
        for (int i = 0; i < 3; i++)
        {
            if (catcher.x + i < n)
                view.push_back(catcher.x + i);
        }
    }

    // 오른쪽
    else if (catcher.d == 1)
    {
        for (int i = 0; i < 3; i++)
        {
            if (catcher.y + i < n)
                view.push_back(catcher.y + i);
        }
    }

    // 왼쪽
    else if (catcher.d == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            if (catcher.y - i >= 0)
                view.push_back(catcher.y - i);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (runner[i].die)
            continue;

        // 위 아래
        if (catcher.d == 0 && catcher.d == 2)
        {
            for (int j = 0; view.size(); j++)
            {
                // 술레의 시야에 들어온 경우
                if (runner[i].x == view[j] && runner[i].y == catcher.y)
                {
                    bool tree_hide = false;
                    // 나무에 가려질 경우 고려
                    for (int l = 0; l < tree.size(); l++)
                    {
                        if (runner[i].x == tree[l].first && runner[i].y == tree[l].second)
                        {
                            tree_hide = true;
                            break;
                        }
                    }

                    if (!tree_hide)
                    {
                        runner[i].die = true;
                        n++;
                    }
                }
            }
        }

        // 오른쪽 왼쪽
        else
        {
            for (int j = 0; view.size(); j++)
            {
                // 술레의 시야에 들어온 경우
                if (runner[i].y == view[j] && runner[i].x == catcher.x)
                {
                    bool tree_hide = false;
                    // 나무에 가려질 경우 고려
                    for (int l = 0; l < tree.size(); l++)
                    {
                        if (runner[i].x == tree[l].first && runner[i].y == tree[l].second)
                        {
                            tree_hide = true;
                            break;
                        }
                    }

                    if (!tree_hide)
                    {
                        runner[i].die = true;
                        n++;
                    }
                }
            }
        }
    }
    return n;
}

void sol()
{
    int score = 0;

    for (int i = 1; i <= k; i++)
    {
        move_runner();
        move_catcher();
        cout << catcher.x << catcher.y << '\n';
        int n = kill_runner();
        cout << n << '\n';
        score += n * i;
    }

    cout << score << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> h >> k;
    catcher = {n / 2, n / 2, 0, 0};

    int x, y, d;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> d;
        runner.push_back({x, y, d, 0});
    }

    for (int i = 0; i < h; i++)
    {
        cin >> x >> y;
        tree.push_back({x, y});
    }

    sol();

    return 0;
}