#include <iostream>
#include <vector>
#include <map>
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
    map<string, int> word_count;
    while (n--)
    {
        cin >> s;
        if (s.length() >= m)
        {
            word_count[s]++;
        }
    }
    vector<pair<string, int>> word(word_count.begin(), word_count.end());
    sort(word.begin(), word.end(), order);
    for (int i = 0; i < word.size(); i++)
    {
        cout << word[i].first << '\n';
    }
}