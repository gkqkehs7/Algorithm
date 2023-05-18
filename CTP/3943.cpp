#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

    int n;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        int max_val = input;

        while(input != 1) {
            max_val = max(max_val, input);

            if(input % 2 == 0) {
                input = input / 2;
            } else {
                input = input * 3 + 1;
            }
        }
        
        cout << max_val << "\n";
        
    }
}