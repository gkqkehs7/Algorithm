// 약수의 최솟값 x 최댓값을 곱하면 원래 수가 된다

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int *arr = new int[n];

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        arr[i] = input;
    }
    sort(arr, arr+n);

    cout << arr[0] * arr[n-1] << "\n";

}