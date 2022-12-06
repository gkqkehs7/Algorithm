#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string s;
		cin >> s;

		long long* arr = new long long[s.length()];

		int count = 0;
		for (int i = s.length() -1 ; i >= 0; i--) {
			arr[count] = s[i] - '0';
			count++;
		}

		bool up = false;
		long long result = 0;
		for (int i = 0; i < count; i++) {
			int temp = arr[i];
			if (up) temp += 1;

			if (temp < 5) {
				result += temp;
				up = false;
			}
			else if (temp > 5) {
				result += 10 - temp;
				up = true;
			}

			else if (temp == 5) {
				if (arr[i + 1] >= 5) {
					result += 10 - temp;
					up = true;
				}
				else if (arr[i + 1] < 5) {
					result += temp;
					up = false;
				}
			}
		}

		if (up) {
			if (arr[count - 1] != 4) {
				result += 1;
			}
		}

		cout << result << "\n";
	}
}