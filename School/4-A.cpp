#include <iostream>

using namespace std;
int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n, k;
		cin >> n >> k;

		int* arr1 = new int[n];
		int* arr2 = new int[n];
		for(int i=0; i<n; i++) {
			int input;
			cin >> input;
			arr1[i] = input;
		}

		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			arr2[i] = input;
		}

		int dp[100001] = { 0, };

		for (int i = 0; i < n; i++) {
			dp[arr2[i] / arr1[i]] += arr1[i];
		}

		int result = 0;
		for (int i = 100000; i >= 0; i--) {
			if (dp[i] > 0) {
				
				if (k >= dp[i]) {
					result += dp[i] * i;
					k -= dp[i];
				}
				else {
					result += k * i;
					break;
				}
			}
		}

		cout << result << "\n";
	}

}