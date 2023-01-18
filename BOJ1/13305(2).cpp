#include <iostream>
using namespace std;
int dis[100001] = { 0, };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i<n-1; i++) {
        int input;
        cin >> input;
        dis[i] = input;
    }

    int min_price = 1000000001;
    long long sum = 0;
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;

        if(input < min_price) {
            min_price = input;
        } 
        sum += (long long)min_price * dis[i];
    }

    cout << sum;
}