#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
vector<bool> decimal(10000, 1);

string bfs(int a, int b)
{
    if (a == b)
        return "0";

    vector<bool> visited(10000, 0);
    queue<pair<int, int>> q;
    q.push({a, 0});
    visited[a] = 1;

    while (!q.empty())
    {
        int now = q.front().first;
        int dep = q.front().second;
        q.pop();
        string numStr = to_string(now);
        for (int i = 0; i < 4; i++)
        {
            char original = numStr[i];
            for (char digit = '0'; digit <= '9'; digit++)
            {
                if (i == 0 && digit == '0')
                    continue;
                if (numStr[i] == digit)
                    continue;

                numStr[i] = digit;
                int next = stoi(numStr);

                if (next == b)
                    return to_string(dep + 1);
                if (!visited[next] && decimal[next])
                {
                    q.push({next, dep + 1});
                    visited[next] = 1;
                }
            }
            numStr[i] = original;
        }
    }
    return "Impossible";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, a, b;
    cin >> t;

    for (int i = 2; i * i < 10000; i++)
    {
        if (decimal[i])
            for (int j = i * i; j < 10000; j += i)
                decimal[j] = 0;
    }

    while (t--)
    {
        cin >> a >> b;
        cout << bfs(a, b) << '\n';
    }
    return 0;
}