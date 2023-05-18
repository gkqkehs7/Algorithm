#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    return b < a;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a_num, b_num;

        cin >> a_num >> b_num;
        int a[20001];
        int b[20001];

        for(int i=0; i<a_num; i++) {
            cin >> a[i];
        }

        for(int i=0; i<b_num; i++) {
            cin >> b[i];
        }
        sort(a, a + a_num, compare);
        sort(b, b + b_num, compare);

        int ans = 0;
        int j_start = 0;

        for(int i=0; i < a_num; i++) {
           for(int j=j_start; j < b_num; j++) {
                if(a[i] > b[j]) {
                    ans++;
                } else {
                    j_start = j;
                }
           } 
        }

        cout << ans << "\n";
    }
}