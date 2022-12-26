#include <iostream>
#include <cmath>

using namespace std;
int check[1000000] = { 0 };

int main() {
    check[0] = check[1] = 1;

    for(int i=2; i * i <= 1000000; i++) {
        if(check[i] == 0) {
            for(int j= i + i; j <= 1000000; j += i) {
                check[j] = 1;
            }
        }
    }

    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    while(1) {
        int n;
        cin >> n;

        if(n == 0) {
            break;
        }

        int start = 3;
        int end = n-3;
        bool find = false;

        while(start <= end) {
            if(check[start] == 0 && check[end] == 0) {
                if((start + end) == n) {
                    find = true;
                    break;
                }
            }
            end -= 2;
            start += 2;
        }

        if(find) {
            cout << n << " = " << start << " + " << end << "\n";
        } else {
            cout << "Goldbach's conjecture is wrong." << "\n";
        }
    
    }
} 