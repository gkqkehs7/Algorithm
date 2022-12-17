#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		long long n;
		cin >> n;

		int k = 0;
		while (n != 0) {
			n = n / 2;
			k++;
		}
		
		k--;

		long long one_count = 0;
		long long zero_count = 0;
		long long same = 0;

		for (int i = 0; i < k; i++) {
			same += i * pow(2, i);
		}
		same = same / 2;

		for (int i = 0; i < k; i++) {
			one_count += pow(2, i);
		}
		one_count += same;
		one_count += 1;

		zero_count += same;
		zero_count += k;

		cout << zero_count << " " << one_count << "\n";

	}
}