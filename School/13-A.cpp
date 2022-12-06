#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int visited[1001]{ false };
vector<pair<int, int>> graph[1001];

void dfs(int now) {
	cout << now << "\n";
	visited[now] = true;

	for (int i = 0; i < graph[now].size(); i++) {
		if (visited[graph[now][i].second] == false) {
			dfs(graph[now][i].second);
		}
	}
}

int main() {

	int T;
	cin >> T;

	while (T--) {
		int N, M;

		cin >> N >> M;

		int* hei = new int[N];
		vector<pair<int, int>> s;

		for (int i = 0; i < N; i++) {
			int input;
			cin >> input;
			hei[i] = input;
			s.push_back({ input , i });
		}
		sort(s.begin(), s.end());


		for (int i = 0; i < M; i++) {
			int input1, input2;

			cin >> input1 >> input2;

			graph[input1].push_back({ hei[input2], input2 });
			graph[input2].push_back({ hei[input1], input1 });
		}

		for (int i = 0; i < N; i++) {
			sort(graph[i].begin(), graph[i].end());
		}

		for (int i = 0; i < s.size(); i++) {
			if (visited[s[i].second] == false) {
				dfs(s[i].second);
			}
		}

		for (int i = 0; i < 1001; i++) {
			visited[i] = false;
			graph[i].clear();
		}
		

	}

}
