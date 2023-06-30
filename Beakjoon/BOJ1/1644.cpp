#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int check[4000001]; 
vector<int> sosu;

int main() {
    int n;
    cin >> n;

    for(int i=0; i<4000001; i++) {
        check[i] = 0;
    }

    for(int i=2; i * i <= n; i++) {
        if(check[i] == 0) {
            for(int j= i + i; j <= n; j += i) {
                check[j] = 1;
            }
        }
    }

    int start = 0, end = 0;
    int sum = 0;
    int count = 0;

    for(int i=2; i<=n; i++) {
        if(!check[i]) {
            sosu.push_back(i);
        }
    }


    while(start <= end) {
        if(sum > n) {
            sum -= sosu[start];
            start++;
        } else if(sum < n) {
            if(end >= sosu.size()) break;
            sum += sosu[end];
            end++;
        } else {
           count++; 
        
           if(end >= sosu.size()) break;
           sum += sosu[end];
           end++;
        }
    }

    cout << count;
}