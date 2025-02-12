#include <iostream>
#include <vector>
using namespace std;

int k;
int num = 0;
bool found = false;

void merge(vector<int> &A, int p, int q, int r)
{
    int i = p;
    int j = q + 1;
    vector<int> temp;
    while (i <= q && j <= r)
    {
        if (A[i] < A[j])
            temp.push_back(A[i++]);
        else
            temp.push_back(A[j++]);
    }
    while (i <= q)
        temp.push_back(A[i++]);
    while (j <= r)
        temp.push_back(A[j++]);

    i = p;
    int t = 0;
    while (i <= r)
    {
        A[i++] = temp[t++];
        num++;
        if (k == num)
        {
            cout << A[i - 1] << '\n';
            found = true;
            return;
        }
    }
}

void mergeSort(vector<int> &A, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    vector<int> A;
    cin >> n >> k;
    while (n--)
    {
        cin >> x;
        A.push_back(x);
    }
    mergeSort(A, 0, A.size() - 1);
    if (!found)
        cout << -1 << '\n';
    return 0;
}