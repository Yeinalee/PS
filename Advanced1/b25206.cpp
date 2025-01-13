#include <iostream>

using namespace std;
float tofloat(string gpa)
{
    if (gpa == "A+")
        return 4.5;
    if (gpa == "A0")
        return 4.0;
    if (gpa == "B+")
        return 3.5;
    if (gpa == "B0")
        return 3.0;
    if (gpa == "C+")
        return 2.5;
    if (gpa == "C0")
        return 2.0;
    if (gpa == "D+")
        return 1.5;
    if (gpa == "D0")
        return 1.0;
    if (gpa == "F")
        return 0;
}

int main()
{
    float total = 0, totalcredit = 0, credit;
    string sub, gpa;
    int p = 0;
    for (int i = 0; i < 20; i++)
    {
        cin >> sub >> credit >> gpa;
        if (gpa != "P")
        {
            total += (credit * tofloat(gpa));
            totalcredit += credit;
        }
    }
    cout << total / totalcredit << '\n';
    return 0;
}