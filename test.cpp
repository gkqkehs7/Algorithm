#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[100001];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr + n);
    int start = 0;
    int end = n - 1;

    int ans = 2000000001;
    while(start != end) {
        int sub = abs(arr[start] - arr[end]);
        if(sub > m) {
            if(abs(arr[start++] - arr[end]) > abs(arr[start] - arr[end--])) {
                
            };
        } else if(sub == n) {
            ans = 0;
            break;
        }
    }

    cout << ans;
}