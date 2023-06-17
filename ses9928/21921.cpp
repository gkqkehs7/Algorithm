#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    
    int visitors[250001];
    for(int i=1; i<=n; i++) cin >> visitors[i];

    int sum = 0;
    for(int i=1; i<=x; i++) {
        sum += visitors[i];
    }
    int count = 1;
    int max_value = sum;


    for(int i=1; i<=n; i++) {

        if(i + x > n) break;

        sum = sum - visitors[i] + visitors[i + x];
    
        if(sum > max_value) {
            max_value = sum;
            count = 1;
        } else if(sum == max_value) {
            count++;
        } 

    }

    if(max_value == 0) {
        cout << "SAD";
    } else {
        cout << max_value << "\n" << count;
    }
}