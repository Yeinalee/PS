#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, answer = 0;
    string s;
    unordered_set<string> bear;
    cin >> n;
    while (n--)
    {
        cin >> s;
        bool dup = false;
        if (s == "ENTER")
        {
            bear.clear();
        }
        else
        {
            if (bear.find(s) == bear.end())
            {
                answer++;
                bear.insert(s);
            }
        }
    }
    cout << answer << '\n';
}