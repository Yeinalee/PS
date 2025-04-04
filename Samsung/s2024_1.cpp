#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
int n, m, sr, sc, er, ec;
vector<pair<int, int>> path;
vector<vector<int>> map;
vector<tuple<int, int, bool, bool>> warrior; // 위치(x, y), 돌, 죽음
vector<vector<int>> scope;

// 전사 이동
// 출력: 전사의 이동 거리 / 전사의 위치 갱신
int move_warrior(int &cx, int &cy)
{
    int total = 0;
    for (int i = 0; i < m; i++)
    {
        // cout << get<0>(warrior[i]) << get<1>(warrior[i]) << '\n';
        if (get<3>(warrior[i]) || get<2>(warrior[i]))
            continue;

        int wx = get<0>(warrior[i]);
        int wy = get<1>(warrior[i]);

        vector<pair<int, int>> move_op;
        if (wx > cx)
            move_op.push_back({-1, 0});
        if (wx < cx)
            move_op.push_back({1, 0});
        if (wy > cy)
            move_op.push_back({0, -1});
        if (wy < cy)
            move_op.push_back({0, 1});

        for (pair<int, int> move : move_op)
        {
            int nx = wx + move.first;
            int ny = wy + move.second;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || scope[nx][ny] == 2)
                continue;

            total++;
            get<0>(warrior[i]) = nx;
            get<1>(warrior[i]) = ny;
            break;
        }
        // cout << get<0>(warrior[i]) << get<1>(warrior[i]) << '\n';
        wx = get<0>(warrior[i]);
        wy = get<1>(warrior[i]);

        vector<pair<int, int>> move_op2;
        if (wy > cy)
            move_op2.push_back({0, -1});
        if (wy < cy)
            move_op2.push_back({0, 1});
        if (wx > cx)
            move_op2.push_back({-1, 0});
        if (wx < cx)
            move_op2.push_back({1, 0});

        for (pair<int, int> move : move_op2)
        {
            int nx = wx + move.first;
            int ny = wy + move.second;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || scope[nx][ny] == 2)
                continue;

            total++;
            get<0>(warrior[i]) = nx;
            get<1>(warrior[i]) = ny;
            break;
        }
        // cout << get<0>(warrior[i]) << get<1>(warrior[i]) << "\n\n\n";
    }
    return total;
}

int cnt_stone_war(int &cx, int &cy, int dir)
{
    int cnt = 0, ddir1, ddir2;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    if (dir == 0 || dir == 1)
    {
        ddir1 = 2;
        ddir2 = 3;
    }
    else
    {
        ddir1 = 0;
        ddir2 = 1;
    }
    scope.assign(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        if (get<3>(warrior[i])) // 죽은 전사
            continue;
        scope[get<0>(warrior[i])][get<1>(warrior[i])] = 1;
        get<2>(warrior[i]) = 0; // 모두 돌이 아님으로 초기화
    }

    // 직선 방향
    int nx = cx;
    int ny = cy;
    while (true)
    {
        nx += dx[dir];
        ny += dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            break;
        if (scope[nx][ny] == 1) // 전사를 만나는 경우
        {
            scope[nx][ny] = 2;
            for (int i = 0; i < m; i++)
            {
                if (get<0>(warrior[i]) == nx && get<1>(warrior[i]) == ny)
                {
                    get<2>(warrior[i]) = 1; // 돌
                    cnt++;
                }
            }
            break;
        }
        scope[nx][ny] = 2;
    }

    // 대각선 방향
    for (int i = 0; i < 2; i++)
    {
        nx = cx;
        ny = cy;
        int ddir = (i == 0) ? ddir1 : ddir2;

        while (true)
        {
            nx += dx[dir] + dx[ddir];
            ny += dy[dir] + dy[ddir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || scope[nx][ny] == 3)
                break;

            int step = 0;
            while (true)
            {
                int nxt = nx + dx[dir] * step;
                int nyt = ny + dy[dir] * step;

                if (nxt < 0 || nxt >= n || nyt < 0 || nyt >= n || scope[nxt][nyt] == 3)
                    break;

                // 전사를 만나는 경우
                if (scope[nxt][nyt] == 1)
                {
                    scope[nxt][nyt] = 2;
                    // 전사 -> 돌
                    for (int j = 0; j < m; j++)
                    {
                        if (get<0>(warrior[j]) == nxt && get<1>(warrior[j]) == nyt)
                        {
                            get<2>(warrior[j]) = 1;
                            cnt++;
                        }
                    }

                    // 전사 뒤 대각선 방향
                    int nnxt = nxt, nnyt = nyt;
                    while (true)
                    {
                        nnxt += dx[dir] + dx[ddir];
                        nnyt += dy[dir] + dy[ddir];
                        if (nnxt < 0 || nnxt >= n || nnyt < 0 || nnyt >= n)
                            break;

                        scope[nnxt][nnyt] = 3;
                    }
                    break;
                }
                scope[nxt][nyt] = 2;
                step++;
            }
        }
    }
    return cnt;
}

// 메두사의 시야각
// 메두사의 위치(cx, cy, 전사)
// 출력: 돌로 변하는 전사의 수
int med_stone(int cx, int cy)
{
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int max_count = 0;
    int max_dir = 0;

    for (int i = 0; i < 4; i++)
    {
        int nmp = cnt_stone_war(cx, cy, i);
        if (nmp > max_count)
        {
            max_count = nmp;
            max_dir = i;
        }
        // cout << i << nmp << '\n';
    }
    cnt_stone_war(cx, cy, max_dir);
    return max_count;
}

// 메두사의 이동 경로 구하기
void bfs()
{
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(n, {-1, -1}));
    queue<pair<int, int>> q;
    bool found = false;
    q.push({sr, sc});
    visited[sr][sc] = 1;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (cx == er && cy == ec)
        {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (map[nx][ny] == 0 && visited[nx][ny] == 0)
                {
                    visited[nx][ny] = visited[cx][cy] + 1;
                    parent[nx][ny] = {cx, cy};
                    q.push({nx, ny});
                }
            }
        }
    }

    if (!found)
        return;
    else
    {
        int px = er;
        int py = ec;

        while (!(px == sr && py == sc))
        {
            path.push_back({px, py});
            pair<int, int> prev = parent[px][py];
            if (prev.first == -1 && prev.second == -1)
            {
                path.clear();
                return;
            }
            px = prev.first;
            py = prev.second;
        }
        reverse(path.begin(), path.end());
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<tuple<int, int, int>> answer;
    int x, y;
    cin >> n >> m;
    cin >> sr >> sc >> er >> ec;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        warrior.push_back({x, y, 0, 0});
    }

    map.assign(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            map[i][j] = x;
        }
    }

    // 메두사 최적 경로 구하기
    bfs();

    if (path.empty())
    {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < path.size() - 1; i++)
    {
        int med = 0;
        // 메두사가 이동한 곳에 전사 -> 죽음
        for (int j = 0; j < m; j++)
        {
            if (path[i].first == get<0>(warrior[j]) && path[i].second == get<1>(warrior[j]))
            {
                get<3>(warrior[j]) = 1;
                med++;
            }
        }

        int die = 0;
        int stone = med_stone(path[i].first, path[i].second);  // 전사 돌 여부
        int len = move_warrior(path[i].first, path[i].second); // 전사 이동
        for (int j = 0; j < m; j++)
        {
            if (path[i].first == get<0>(warrior[j]) && path[i].second == get<1>(warrior[j]))
            {
                die++;
                get<3>(warrior[j]) = 1;
            }
        }
        answer.push_back({len, stone, die - med});
        // cout << len << ' ' << stone << ' ' << die << '\n';
    }

    for (int i = 0; i < answer.size(); i++)
        cout << get<0>(answer[i]) << ' ' << get<1>(answer[i]) << ' ' << get<2>(answer[i]) << '\n';

    cout << 0 << '\n';
    return 0;
}