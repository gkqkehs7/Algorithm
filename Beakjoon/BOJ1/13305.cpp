#include <iostream>
using namespace std;
int dis[100001] = { 0, };
int price[100001] = { 0, };

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n-1; i++) {
        int input;
        cin >> input;
        dis[i] = input;
    }

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        price[i] = input;
    }

    int min_price = 1000000001;
    long long sum = 0;
    for(int i=0; i<n-1; i++) {
        if(price[i] < min_price) {
            min_price = price[i];
        }

        sum += min_price * dis[i];
    }

    cout << sum;
}