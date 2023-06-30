#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int count = 0;
    for(int i=n; i<m + 1; i++) {

        bool sosu = true;
        int num = i;
        int last = sqrt(num);

        if(num == 1) continue;
        else if (num == 2) {
            cout << num << "\n";
            continue;
        } else {
            for(int j=2; j<last + 1; j++) {
                if(num % j == 0) {
                    sosu = false;
                    break;
                }
            }
        }
    
        if(sosu) {
            cout << num << "\n";
        }
    }
}