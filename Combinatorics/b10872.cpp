#include <iostream>
using namespace std;
int main()
{
    int n, answer = 1;
    cin >> n;
    for (int i = 2; i <= n; i++)
        answer *= i;
    cout << answer << '\n';
}