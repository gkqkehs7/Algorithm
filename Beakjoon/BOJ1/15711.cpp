#include <iostream>
#include <cmath>
#include <vector>

int check[2000001] = { 1, 1, 0 };
using namespace std;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i=2; i<= sqrt(2000000); i++) {
        if(!check[i]) {
            for(int j= i+i; j <= 2000000; j += i) {
                check[j] = 1;
            }
        }
    }

    for(int i=2; i <= sqrt(2000000); i++) {
        if(!check[i]) {
            v.push_back(i);
        }
    }

    int T;
    cin >> T;

    for(int i=0; i<T; i++) {
        long long a, b;
        cin >> a >> b;

        long long ab = a + b;
        long long target = ab - 2;
        bool attach = true;
        
        if(ab < 4) {
            attach = false;
        } else {
            if(ab % 2 != 0) {
               if(target <= 2000000) {
                    if(check[target]) {
                        attach = false;
                    } 
               } else {
                   for(int j=0; j<v.size(); j++) {
                    if(target % v[j] == 0) {
                        attach = false;
                        break;
                    }
                   }
        
               }
            }
        }

        if(attach) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }

       
    }
}