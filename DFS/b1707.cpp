#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int v;
vector<vector<int>> map;
vector<int> visited;

bool dfs(int k)
{
    stack<int> st;
    st.push(k);
    visited[k] = 1;

    while (!st.empty())
    {
        int now = st.top();
        st.pop();

        for (int i = 0; i < map[now].size(); i++)
        {
            int next = map[now][i];
            if (visited[now] == 1)
            {
                if (visited[next] == 1)
                    return false;
                else
                {
                    if (visited[next] == 0)
                    {
                        st.push(next);
                        visited[next] = 2;
                    }
                }
            }
            else if (visited[now] == 2)
            {
                if (visited[next] == 2)
                    return false;
                else
                {
                    if (visited[next] == 0)
                    {
                        st.push(next);
                        visited[next] = 1;
                    }
                }
            }
        }
    }

    return true;
}

bool sol()
{
    for (int i = 1; i < v + 1; i++)
    {
        if (!visited[i])
            if (!dfs(i))
                return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k, e, x, y;
    cin >> k;
    while (k--)
    {
        cin >> v >> e;
        map.assign(v + 1, vector<int>());
        visited.assign(v + 1, 0);
        for (int i = 0; i < e; i++)
        {
            cin >> x >> y;
            map[x].push_back(y);
            map[y].push_back(x);
        }
        cout << (sol() ? "YES" : "NO") << '\n';
    }
    return 0;
}