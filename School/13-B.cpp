#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, m, q;
		cin >> n >> m >> q;
		int cost[251][251];
		vector<pair<int, int>> answer;

		for (int i = 0; i < 251; i++) {
			for (int j = 0; j < 251; j++) {
				if (i == j) cost[i][j] = 0;
				else {
					cost[i][j] = 10001 * 250 * 250;
				}
			}

		}

		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;

			cost[u][v] = w;
			cost[v][u] = w;
		}

		for (int i = 0; i < q; i++) {
			int u, v;
			cin >> u >> v;

			answer.push_back({ u,v });
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
				}
			}
		}


		for (int i = 0; i < q; i++) {
			cout << cost[answer[i].first][answer[i].second] << "\n";
		}

	}
}