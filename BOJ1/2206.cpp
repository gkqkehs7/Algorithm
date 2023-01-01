#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[1001][1001] = { 0, };
int dx[4] = {0, 1, 0 ,-1};
int dy[4] = {1, 0 ,-1 , 0};


int min_answer = 99999999;
bool can_go = false;
bool visited[1001][1001] = { false, };
int dp[1001][1001] = { 0, };
queue<pair<int, int>> q;


// 1000 000
int main() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			map[i][j] = s[j] - '0';
			if (s[j] - '0' == 1) {
				v.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int change_x = v[i].first;
		int change_y = v[i].second;
		
		map[change_x][change_y] = 0;

		q.push({ 0 ,0 });
		visited[0][0] = true;

	
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
	

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < n && ny < m && nx >= 0 && ny >= 0 && visited[nx][ny] == false && map[nx][ny] == 0) {
					visited[nx][ny] = true;
					q.push({ nx , ny });
					dp[nx][ny] = dp[x][y] + 1;
				}
			}
		}
		
		if (dp[n - 1][m - 1] != 0) {
			if (dp[n - 1][m - 1] < min_answer) {
				can_go = true;
				min_answer = dp[n - 1][m - 1];
			}
		}

		// cout << dp[n - 1][m - 1] << "\n";
		map[change_x][change_y] = 1;

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				dp[j][k] = 0;
				visited[j][k] = false;
			}
		}

		
	}
	
	if (can_go) {
		cout << min_answer  + 1;
	}
	else {
		cout << -1;
	}
 	
}