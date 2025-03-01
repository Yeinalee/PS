#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;

void dfs(int node, int n)
{
    deque<int> q;
    vector<bool> visited(n + 1, 0);
    q.push_front(node);
    visited[node] = 1;
    cout << node << ' ';

    while (!q.empty())
    {
        int now = q.front();
        q.pop_front();
        if (!visited[now])
        {
            visited[now] = 1;
            cout << now << ' ';
        }

        for (int i = graph[now].size() - 1; i >= 0; i--)
        {
            if (!visited[graph[now][i]])
                q.push_front(graph[now][i]);
        }
    }
    cout << '\n';
}

void bfs(int node, int n)
{
    deque<int> q;
    vector<bool> visited(n + 1, 0);
    q.push_front(node);
    visited[node] = 1;
    cout << node << ' ';

    while (!q.empty())
    {
        int now = q.front();
        q.pop_front();

        for (int next : graph[now])
        {
            if (!visited[next])
            {
                q.push_back(next);
                visited[next] = 1;
                cout << next << ' ';
            }
        }
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, r, a, b;
    cin >> n >> m >> r;
    graph.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i < n + 1; i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(r, n);
    bfs(r, n);

    return 0;
}