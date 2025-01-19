#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// void quickSort(vector<int> &data, int left, int right)
// {
//     if (left >= right)
//         return;

//     int pivot = data[(left + right) / 2];
//     int i = left;
//     int j = right;
//     while (i <= j)
//     {
//         while (data[i] < pivot)
//             i++;
//         while (data[j] > pivot)
//             j--;

//         if (i <= j)
//         {
//             swap(data[i], data[j]);
//             i++;
//             j--;
//         }
//     }
//     if (left < j)
//         quickSort(data, left, j);
//     if (i < right)
//         quickSort(data, i, right);
// }

int main()
{
    int n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    for (int num : v)
        cout << num << '\n';
    return 0;
}