#include <iostream>

using namespace std;
int dp_zero[41];
int dp_one[41];

int fibonacci_zero (int n) {
    if(n == 0) {
        return 1;
    } else if(n == 1) {
        return 0;
    } else {
        if(dp_zero[n] != 0) {
            return dp_zero[n];
        } else {
            dp_zero[n] = fibonacci_zero(n-1) + fibonacci_zero(n-2);
            return dp_zero[n];
        }
    }
}

int fibonacci_one (int n) {
    if(n < 1) {
        return 0;
    }

    if(n == 1) {
        return 1;
    } else {
        if(dp_one[n] != 0) {
            return dp_one[n];
        } else {
            dp_one[n] = fibonacci_one(n-1) + fibonacci_one(n-2);
            return dp_one[n];
        }
    }
}


int main() {
    int T;
    cin >> T;

    for(int i=0; i<41;i ++) {
        dp_zero[i] = 0;
        dp_one[i] = 0;
    }
    dp_zero[0] = 1;
    dp_one[1] = 1;
    fibonacci_zero(40);
    fibonacci_one(40);

    while(T--) {
        int input;
        cin >> input;
        cout << dp_zero[input] << " " << dp_one[input] << "\n";
    }
}