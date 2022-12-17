#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		
		multiset<pair<int, int>> v;

		int* castle = new int[n];
		int* answer = new int[n];

		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			castle[i] = input;
			answer[i] = 0;
		}

		answer[0] = -1;
		v.insert({ castle[0], 1 });

		for (int i = 1; i < n; i++) {

			multiset<pair<int, int>>::iterator iter;
			iter = v.insert({ castle[i], i + 1 });

			if(iter == v.begin()) {
				answer[i] = -1;
			} else {
				iter--;
				answer[i] = iter->second;
			}
		}

		for (int i = 0; i < n; i++) {
			cout << answer[i] << " ";
		}

		cout << "\n";
	}
	
}