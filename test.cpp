#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> result;
int visited[5] = { false, };
int size = 5;

void dfs(int idx, int depth) {
	if(depth == 3) {
		for(int i=0; i<size; i++) {
			if(visited[i]) {
				cout << i << " ";
			}
		}
		cout << "\n";
		return;
	}

	for(int i=idx; i<size; i++) {
		if(visited[i] == true) continue;

		visited[i] = true;
		dfs(i, depth + 1);
		visited[i] = false;
	}
}

int main() {

	dfs(0, 0);
}