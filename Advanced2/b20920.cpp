#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool order(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
    {
        if (a.first.length() == b.first.length())
        {
            return a.first < b.first;
        }
        return a.first.length() > b.first.length();
    }
    return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    vector<pair<string, int>> word;
    while (n--)
    {
        cin >> s;
        bool dup = false;
        if (s.length() < m)
            continue;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i].first == s)
            {
                dup = true;
                word[i].second++;
                break;
            }
        }
        if (!dup)
            word.push_back({s, 1});
    }
    sort(word.begin(), word.end(), order);
    for (int i = 0; i < word.size(); i++)
    {
        cout << word[i].first << '\n';
    }
}