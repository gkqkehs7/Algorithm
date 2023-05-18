#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        int arr[1000001];

        for(int i=0; i<n; i++) cin >> arr[i];

        int left = 0;
        int right = n - 1;
        int min = 2000002;
        int ans = 0;
        sort(arr, arr + n);

        while(left != right) {
        
            int left_val = arr[left];
            int right_val = arr[right];
            int temp = left_val + right_val;

            if(temp < k) {
                left++;

                if(abs(temp - k) < min) {
                    min = abs(temp - k);
                    ans = 1;
                } else if(abs(temp - k) == min) {
                    ans++;
                } 
            } else if(temp > k) {
                right--;

                if(abs(temp - k) < min) {
                    min = abs(temp - k);
                    ans = 1;
                } else if(abs(temp - k) == min) {
                    ans++;
                } 
            } else if(temp == k) {
                if(min == 0) {
                    ans++;
                } else {
                    min = 0;
                }
            }
        }

        cout << ans << "\n";
    }
}