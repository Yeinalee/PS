#include <iostream>
#include <vector>
using namespace std;
int n, diff = 2000;
vector<int> used(20, 0);

int getdiff(vector<vector<int>> &s)
{
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (used[i]) // a팀
        {
            for (int j = 0; j < n; j++)
                if (used[j])
                    a += s[i][j];
        }
        else // b팀
        {
            for (int j = 0; j < n; j++)
                if (!used[j])
                    b += s[i][j];
        }
    }
    return a - b > 0 ? a - b : b - a;
}

void answer(vector<vector<int>> &s, int num)
{
    if (n / 2 == num)
    {
        int ans = getdiff(s);
        if (diff > ans)
            diff = ans;
    }
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            used[i]++;
            answer(s, num + 1);
            used[i]--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x;
    cin >> n;
    vector<vector<int>> s(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            s[i][j] = x;
        }
    }
    answer(s, 0);
    cout << diff << '\n';
    return 0;
}