#include <iostream>

using namespace std;

int arr[11] = { 0, };

int main() {
    int n, k;
    cin >> n >> k;

    int count = 0;
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;

        if(input <= k) {
            arr[i] = input;
            count++;
        }  
    }

    int temp = k;
    int answer = 0;
    for(int i=count-1; i >= 0; i--) {
       
        answer += temp / arr[i];
        temp = temp % arr[i];

        if(temp == 0) break;
        
    }

    cout << answer;
}