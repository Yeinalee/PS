#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool word(string a, string b)
{
    if (a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}
int main()
{
    int n;
    string st;
    vector<string> s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> st;
        bool isDuplicate = false;
        for (int j = 0; j < s.size(); j++)
        {
            if (st == s[j])
            {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate)
            s.push_back(st);
    }
    sort(s.begin(), s.end(), word);

    for (const string &word : s)
        cout << word << '\n';
    return 0;
}