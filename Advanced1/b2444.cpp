#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n; // 5
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < n - i; j++)
            cout << ' ';
        for (int j = 0; j < 2 * i - 1; j++)
            cout << '*';
        cout << '\n';
    }

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < n - i; j++)
            cout << ' ';
        for (int j = 0; j < 2 * i - 1; j++)
            cout << '*';
        cout << '\n';
    }

    return 0;
}