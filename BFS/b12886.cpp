#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int A, B, C, sum;

bool bfs()
{
    if (sum % 3 != 0)
        return false;

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(1501, vector<bool>(1501, 0));

    int a = min({A, B, C});
    int b = max({min(A, B), min(B, C), min(A, C)});
    int c = max({A, B, C});

    q.push({a, b});
    visited[a][b] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int z = sum - x - y;
        q.pop();

        if (x == y && y == z)
            return true;

        int stones[3] = {x, y, z};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (stones[i] < stones[j])
                {
                    int new_stones[3] = {stones[0], stones[1], stones[2]};
                    new_stones[i] *= 2;
                    new_stones[j] -= stones[i];

                    sort(new_stones, new_stones + 3);

                    int nx = new_stones[0], ny = new_stones[1];
                    if (!visited[nx][ny])
                    {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> A >> B >> C;
    sum = A + B + C;
    cout << (bfs() ? 1 : 0) << '\n';
    return 0;
}
