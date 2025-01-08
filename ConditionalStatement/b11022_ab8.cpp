#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << "Case #" << i + 1 << ": " << a << " + " << b << " = " << a + b << endl;
    }
}
