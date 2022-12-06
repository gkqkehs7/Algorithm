#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n, d;
		cin >> n >> d;

		int* calrories = new int[n];
		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			calrories[i] = input;
		}

		int calrory[201] = { 0, };
		for (int i = 0; i < d; i++) {
			calrory[calrories[i]]++;
		}

		int warning = 0;
		for (int i = d; i < n; i++) {
			int median = 0;
			int first = 0;
			int second = 0;

			if (d % 2 == 0) {
				int count = d / 2;
				for (int j = 0; j < 201; j++) {
					if (calrory[j] != 0) {
						count = count - calrory[j];
						if (count <= 0) {
							first = j;
							break;
						}
					}
				}

				count = d / 2 + 1;
				for (int j = 0; j < 201; j++) {
					if (calrory[j] != 0) {
						count = count - calrory[j];
						if (count <= 0) {
							second = j;
							break;
						}
					}
				}

				median = first + second;
			}

			else {
				int count = d / 2 + 1;
				for (int j = 0; j < 201; j++) {
					if (calrory[j] != 0) {
						count = count - calrory[j];
						if (count <= 0) {
							median = j;
							break;
						}
					}
				}

				median *= 2;
			}

			if (median <= calrories[i]) {
				warning++;
			}

			calrory[calrories[i - d]]--;
			calrory[calrories[i]]++;
		}
		cout << warning << "\n";
	}
}