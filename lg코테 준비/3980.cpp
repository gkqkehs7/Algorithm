#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int result = 0;
int arr[11][11] = { 0, };
bool visited[11];

void dfs(int cnt, int sum) {

    if(cnt == 11) {
        result = max(result, sum);
		return;
    }

    for (int i = 0; i < 11; i++) {
		if (arr[cnt][i] == 0)
			continue;
		if (visited[i] == false) {
			visited[i] = true;
			dfs(cnt + 1, sum + arr[cnt][i]);
			visited[i] = false;
		}
	}
}

int main() {
    int t;
	cin >> t;

	while (t--) {
		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 11; j++)
				cin >> arr[i][j];

		memset(visited, 0, sizeof(visited));
		result = 0;
		dfs(0, 0);
		cout << result << "\n";
	}
}