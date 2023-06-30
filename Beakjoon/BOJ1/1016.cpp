#include <iostream>
#include <cmath>
using namespace std;

int arr[1000001];
int main() {

    long long a,b;
    cin >> a >> b;

    for(int i=0; i< 1000001; i++) arr[i] = 1;

    for(long long i = 2; i<=sqrt(b); i++) {
        long long div = pow(i,2); 
       
        // while(1) {
        //     if(start % div == 0) break;
        //     else start++;
        // }
    
        long long start = a / div;
        if(a % div != 0) start++;
                         
        for(long long j = start * div; j <= b; j += div) {
            arr[j-a] = 0;
        }
     
    }

    int count = 0;
    for(int i=0; i<b-a + 1; i++) {
        if(arr[i] == 1) count++;
    }
    cout << count;
}