#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n, m, k;
		cin >> n >> m >> k;

		int* height = new int[n];
		vector<vector<int>> v(n);
		bool* visited = new bool[n];
		int* togo = new int[k];
		int* dp = new int[n];
		int hanyang = 0;
		int hanyang_min = 1000000000;
		queue<int> q;

		for (int i = 0; i < n; i++) {
			visited[i] = false;
			dp[i] = 0;
		}

		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			if (input < hanyang_min) {
				hanyang_min = input;
				hanyang = i;
			}
			height[i] = input;
		}

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		for (int i = 0; i < k; i++) {
			int input;
			cin >> input;
			togo[i] = input;
		}
		
		q.push(hanyang);
		visited[hanyang] = true;
		
		while (q.size() != 0) {
			int cur = q.front();
			q.pop();
			
			for (int i = 0; i < v[cur].size(); i++) {
				int next = v[cur][i];
				if(visited[next] == false) {
					q.push(next);
					visited[next] = true;
					dp[next] = dp[cur] + 1;
				}
			}
		}

		
		for(int i=0; i<k; i++) {
			if(togo[i] == hanyang) {
				cout << 0 << "\n";
			} else if(togo[i] >= n) {
				cout << -1 << "\n";
			} else if(dp[togo[i]] == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << dp[togo[i]] << "\n";
			}
			
		}
	}
}
