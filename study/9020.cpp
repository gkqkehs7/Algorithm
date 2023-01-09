#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int arr[10001] = { 0, };
int check[10001] = { 1, 1, 0 };
vector<int> v;
int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        arr[i] = input;
    }

    for(int i=0; i < 10001; i++) {
        if(check[i] == 0) {
            for(int j=i+i; j<10001; j += i) {
                check[j] = 1;
            }
        }
    }


    for(int i=0; i<n; i++) {
        int target = arr[i];
        int first = 0;
        int second = 0;
        int diff = 10000;
        for(int j=2; j<target/ 2 + 1; j++) {

            if(check[j] == 0 && check[target-j] == 0) {

                if(abs(target - 2 * j < diff)) {
                    first = j;
                    second = target - j;
                }
            }
        }

        cout << first << " " << second << "\n";
    }

    
}