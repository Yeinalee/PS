#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, answer = 0;
    string s;
    vector<string> bear;
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
            for (auto name : bear)
            {
                if (name == s)
                    dup = true;
            }
            if (!dup)
            {
                answer++;
                bear.push_back(s);
            }
        }
    }
    cout << answer << '\n';
}