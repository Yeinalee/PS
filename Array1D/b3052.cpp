#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y;
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        bool exist = false;
        cin >> x;
        y = x % 42;
        for (int j = 0; j < v.size(); j++)
        {
            if (y == v[j])
                exist = true;
        }
        if (!exist)
            v.push_back(y);
    }
    cout << v.size() << endl;
}