#include <iostream>
#include <string>
#include <stack>

using namespace std;
int main() {
	int T;
	cin >> T;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int t = 0; t < T; t++) {
		string cal;
		cin >> cal;

		stack<int> s;

		for (int i = 0; i < cal.length(); i++) {
			if (cal[i] == '+') {
				int first = s.top();
				s.pop();
				int second = s.top();
				s.pop();
				s.push(first + second);
			}
			else if (cal[i] == '-') {
				int first = s.top();
				s.pop();
				int second = s.top();
				s.pop();
				s.push(second - first);
			}
			else if (cal[i] == '*') {
				int first = s.top();
				s.pop();
				int second = s.top();
				s.pop();
				s.push(first * second);
			}
			else {
				s.push(cal[i] - '0');
			}
		}

		cout << s.top() << "\n";
	}
}