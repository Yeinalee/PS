#include <iostream>
#include <string>
using namespace std;

// 문자를 다이얼 전화기에서 걸리는 시간으로 바꿔주는 함수
int dial(char s)
{
    int t;
    if (s >= 'P' && s <= 'S')
        t = 8;
    else if (s >= 'T' && s <= 'V')
        t = 9;
    else if (s >= 'W' && s <= 'Z')
        t = 10;
    else
        t = (s - 'A') / 3 + 3;
    return t;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int ans = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        ans += dial(s[i]);
    }
    cout << ans << '\n';
    return 0;
}