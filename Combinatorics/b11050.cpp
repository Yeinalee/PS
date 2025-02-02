#include <iostream>
using namespace std;
int main()
{
    int n, k, answer = 1; // 6 2
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        answer *= (n - i);
        answer /= (i + 1);
    }
    cout << answer << '\n';
}