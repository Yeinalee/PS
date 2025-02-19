#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, answer = 0;
    cin >> n;
    vector<int> seq(n), up(n,1), down(n,1);
    
    for(int i=0;i<n;i++)
        cin >> seq[i];

    // 증가하는 부분 수열 계산
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++) {
            if(seq[i] > seq[j]) {
                up[i] = max(up[i], up[j] + 1);
            }
        }
    }

    // 감소하는 부분 수열 계산
    for(int i=n-2;i>=0;i--) {
        for(int j=n-1;j>i;j--) {
            if(seq[i] > seq[j]) {
                down[i] = max(down[i], down[j] + 1);
            }
        }
    }


    for(int i=0;i<n;i++) {
        answer = max(answer, up[i] + down[i] - 1);
    }


    cout << answer <<'\n';
    
    return 0;
}
