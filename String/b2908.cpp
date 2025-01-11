#include <iostream>
#include <string>
using namespace std;

// 문자열을 뒤집는 함수
string reverse(string str)
{
    string rev;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        rev += str[i];
        // rev[j++] = str[i] 안됨
    }
    return rev;
}

int main(int argc, const char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    a = reverse(a);
    b = reverse(b);
    if (a > b)
        cout << a << '\n';
    else
        cout << b << '\n';
    return 0;
}