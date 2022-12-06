#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	int T;
	cin >> T;

	for(int t=0; t<T; t++) {
		string sin;
		cin >> sin;

		stack<int> s;
		s.push(-1);
		
		int *dp = new int[sin.length()+1];
		for (int i = 0; i < sin.length()+1; i++) {
			dp[i] = 0;
		}
		int max_len = 0;

		for (int i = 0; i < sin.length(); i++) {
			if (sin[i] == 'C') {
				s.push(i);
			}
			else if (sin[i] == 'T') {

				if (s.top() != -1) {
					int temp = s.top();
					s.pop();

					int len = i - temp + 1;
					len += dp[temp - 1];

					if (len > max_len) {
						max_len = len;
					}
					dp[i] = len;
				}
				
			}
			
		}

		cout << max_len << "\n";
	}
}