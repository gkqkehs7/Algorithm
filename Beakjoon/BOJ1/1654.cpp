#include <iostream>
#include <algorithm>
using namespace std;

long long arr[10001] = { 0, };
int k, n;
long long answer = 0;
void binary_search(long long start, long long end) {

    if(start > end) return;
    long long mid = (start + end) / 2;

    long long temp = 0;
    for(int i=0; i<k; i++) {
       temp += arr[i] / mid;
    }
    // cout << "start: " << start << " end:" << end << "\n";
    // cout << "temp: " << temp << "\n";
    if(temp >= n) {
        if(mid > answer) {
            answer = mid;
            binary_search(mid + 1, end);
        }
    } else if(temp < n) {
        binary_search(start, mid - 1);
    }
}
int main() {
    
    cin >> k >> n;
    for(int i=0; i<k; i++) {
        long long input;
        cin >> input;
        arr[i] = input;
    }
    sort(arr, arr+k);

    binary_search(1, arr[k-1]);
    cout << answer;
    
}