#include <iostream>
using namespace std;

int main()
{
    int a, b, c, temp;
    cin >> a >> b >> c;
    // 가장 큰 값을 a로
    if (c > a && c > b)
    {
        temp = a;
        a = c;
        c = temp;
    }
    else if (b > a && b > c)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if (b + c > a)
        cout << a + b + c << '\n';
    else
        cout << (b + c) * 2 - 1 << '\n';
}