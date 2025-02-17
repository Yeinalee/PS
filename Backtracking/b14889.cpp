#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, diff = 2000;
vector<int> team;
vector<vector<int>> s;

int getdiff()
{
    int a = 0, b = 0;
    vector<int> teamA, teamB;

    for (int i = 0; i < n; i++)
    {
        if (find(team.begin(), team.end(), i) != team.end()) // a팀
        {
            teamA.push_back(i);
        }
        else // b팀
        {
            teamB.push_back(i);
        }
    }

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            a += s[teamA[i]][teamA[j]];
            b += s[teamB[i]][teamB[j]];
        }
    }
    return a - b > 0 ? a - b : b - a;
}

void answer(int idx)
{
    if (team.size() == n / 2)
    {
        diff = min(diff, getdiff());
        return;
    }

    for (int i = idx; i < n; i++)
    {
        team.push_back(i);
        answer(i + 1);
        team.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x;
    cin >> n;
    s.assign(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> s[i][j];

    answer(0);
    cout << diff << '\n';
    return 0;
}