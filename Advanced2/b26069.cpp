#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    int n;
    string a, b;
    unordered_set<string> dance;
    cin >> n;
    dance.insert("ChongChong");
    while (n--)
    {
        cin >> a >> b;
        if (dance.find(a) != dance.end()) // a가 춤추고 있으면 b 추가
            dance.insert(b);
        if (dance.find(b) != dance.end()) // b가 춤추고 있으면 a 추가
            dance.insert(a);
    }
    cout << dance.size() << '\n';
}