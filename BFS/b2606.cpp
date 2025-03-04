#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

int bfs()
{
    int answer = 0;
    queue<int> q;
    visited[1] = 1;
    q.push(1);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int next : graph[now])
        {
            if (!visited[next])
            {
                answer++;
                q.push(next);
                visited[next] = 1;
            }
        }
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    graph.resize(n + 1);
    visited.resize(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << bfs() << '\n';

    return 0;
}