#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char *argv[])
{
    string s;
    cin >> s;
    int ans = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != s[s.size() - i - 1])
        {
            ans = 0;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}