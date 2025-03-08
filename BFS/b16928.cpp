#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<int> visited(101, -1);
vector<pair<int, int>> stair;
vector<pair<int, int>> snake;
vector<int> dx = {1, 2, 3, 4, 5, 6};

int bfs()
{
    queue<int> q;
    q.push(1);
    visited[1] = 0;

    while (!q.empty())
    {
        int cx = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nx = cx + dx[i];

            for (int i = 0; i < n; i++)
            {
                if (nx == stair[i].first)
                    nx = stair[i].second;
            }

            for (int i = 0; i < m; i++)
            {
                if (nx == snake[i].first)
                    nx = snake[i].second;
            }

            if (nx <= 100 && visited[nx] == -1)
            {
                if (nx == 100)
                    return visited[cx] + 1;
                q.push(nx);
                visited[nx] = visited[cx] + 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        stair.push_back({x, y});
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        snake.push_back({x, y});
    }
    cout << bfs() << '\n';
    return 0;
}