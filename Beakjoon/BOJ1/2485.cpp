#include <iostream>
#include <algorithm>
using namespace std;

int get_gcd(int a, int b) {
    if (a < b) {
        int temp = b;
        b = a;
        a = temp;
    }

    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main() {
    int n;
    cin >> n;

    int* tree = new int[n];
    for(int i=0; i<n; i++) {
        int input; 
        cin >> input;
        tree[i] = input;
    }

    sort(tree, tree+n);

    int *stride = new int[n];
    for(int i=1; i<n; i++) {
        stride[i-1] = tree[i] - tree[i-1];
    }

    int gcd = get_gcd(stride[0], stride[1]);
    for(int i=2; i<n-1; i++) {
       gcd = get_gcd(gcd, stride[i]);
    }

    int answer = 0;
    for(int i=0; i<n - 1; i++) {
        answer += stride[i]/gcd - 1;
    }
    
    cout << answer;


} 