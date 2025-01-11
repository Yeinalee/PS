#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int ans = 0;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ')
        {
            ans++;
        }
    }

    cout << ans << '\n';
}