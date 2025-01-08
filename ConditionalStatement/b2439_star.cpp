#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < n - i; j++)
            cout << ' ';
        for (int k = 0; k < i; k++)
            cout << '*';
        cout << endl;
    }
    return 0;
}