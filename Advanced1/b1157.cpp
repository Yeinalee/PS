#include <iostream>
#include <string>
#include <vector>
using namespace std;

char max(vector<int> v)
{
    int inx = 0;
    bool same = false;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[inx] < v[i])
        {
            inx = i;
            same = false;
        }
        else if (v[inx] == v[i])
        {
            same = true;
        }
    }
    if (same)
        return '?';
    else
        return inx + 'A';
}

int main()
{
    vector<int> v(26, 0);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            v[s[i] - 'a']++;
        else
            v[s[i] - 'A']++;
    }
    cout << max(v) << '\n';
    return 0;
}