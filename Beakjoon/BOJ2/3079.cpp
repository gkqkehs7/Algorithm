#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<long long> judge;
int n, m;

int main() {
    
    cin >> n >> m;
    judge.resize(n);
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        judge[i] = input;
    }

    sort(judge.begin(), judge.end());
    long long start = 0;
    long long end = m * judge[n-1];
    long long ans = m * judge[n-1];

    while(start <= end) {
        long long mid = (start + end) / 2;
        long long sum = 0;
        
        for(int i=0; i<n; i++) {
            sum += mid / judge[i];
        }
        if(sum >= m) {
            ans = min(ans, mid);
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
   
    cout << ans;
}