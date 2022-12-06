#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	int T;
	cin >> T;

	for(int t=0; t<T; t++) {
		int M, N;
		cin >> M >> N;

		multiset<int> s;

		for (int i = 0; i < M; i++) {
			int input;
			cin >> input;
			s.insert(input);
		}

		for (int i = 0; i < N; i++) {
			string input1, input2;
			cin >> input1 >> input2;

			if (input2 == "min") {
				s.erase(s.begin());
			}
			else if (input2 == "max") {
				multiset<int>::iterator iter;
				iter = s.end();
				iter--;

				s.erase(iter);
			}
			else {
				int temp = stoi(input2);
				s.insert(temp);
			}
		}

		multiset<int>::iterator iter;
		iter = s.end();
		iter--;

		cout << *s.begin() << " " << *iter << "\n";
	}
}