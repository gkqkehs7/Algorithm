#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* numbers = new int[n];
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        numbers[i] = input;
    }

    int count = 0;
    for(int i=0; i<n; i++) {
        bool sosu = true;
        int num = numbers[i];
        int last = num / 2;

        if(num == 1) continue;
        else if (num == 2) {
            count++;
            continue;
        }
        for(int j=2; j<last + 1; j++) {
            if(num % j == 0) {
                sosu = false;
                break;
            }
        }

        if(sosu) {
            count++;
        }
    }

    cout << count;
}