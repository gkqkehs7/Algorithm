#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int shark_size = 2;
int map[21][21];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1 ,0 };
int dp[21][21];
int answer = 0;

struct Fish {
	int x;
	int y;
	int distance;
};

struct Move {
	int x;
	int y;
	int distance;
};

void Init() {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			dp[i][j] = 99999;
		}
	}
}

bool check_validate_path(int x, int y) {
	if (x >= n || x < 0 || y >= n || y < 0) {
		return false;
	}
	return true;
}

int cango(int x, int y, int desti_x, int desti_y) {
	Init();

	queue<Move> q;
	q.push({ x, y, 0 });

	while (!q.empty()) {
		int now_x = q.front().x;
		int now_y = q.front().y;
		int distance = q.front().distance;
		// cout << now_x << " " << now_y << "\n";
		q.pop();

		if (now_x == desti_x && now_y == desti_y) {
			return distance;
		}

		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];

			if (check_validate_path(next_x, next_y) && map[next_x][next_y] <= shark_size && distance + 1 < dp[next_x][next_y]) {
				dp[next_x][next_y] = distance + 1;
				q.push({ next_x, next_y, distance + 1 });
			}
		}
	}

	return -1;
}



vector<Fish> can_eat_fishes(int x, int y) {
	vector<Fish> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
		
			// 먹을 수 있는 후보들
			if (map[i][j] > 0 && map[i][j] < shark_size) {
				int distance = cango(x, y, i, j);
				if (distance != -1) {
					v.push_back({ i , j , distance });
				}
			}
		}
	}
	return v;
}

bool compare(Fish a, Fish b) {
	if (a.distance == b.distance) {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		return a.x < b.x;
	}
	
	return a.distance < b.distance;
}

void print_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	cin >> n;

	int x = 0;
	int y = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;

			if (input == 9) {
				x = i;
				y = j;
			}
			else {
				map[i][j] = input;
			}
		}
	}

	int eat = 0;
	while (true) {
		vector< Fish> fishes = can_eat_fishes(x, y);

		if (fishes.size() == 0) {
			cout << answer;
			break;
		}

		sort(fishes.begin(), fishes.end(), compare);

		x = fishes[0].x;
		y = fishes[0].y;
		answer += fishes[0].distance;
		
		// cout << x << " " << y << " " << fishes[0].distance << "\n";
		map[x][y] = 0;
		eat++;
		
		if (eat == shark_size) {
			shark_size++;
			eat = 0;
		}
		// print_map();

		// cout << "until: " << answer << "\n";
	}


}