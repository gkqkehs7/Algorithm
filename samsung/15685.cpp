#include <iostream>
#include <vector>
using namespace std;


struct Dragon {
	int x;
	int y;
	int d;
	int g;
};

vector<Dragon> dragons;
int map[101][101] = { 0 };

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0 , 1 };


void Init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			map[i][j] = 0;
		}
	}
}

void get_paths(vector<int>& paths, int now, int generation) {

	int num = now;

	while (now < generation) {
		int size = paths.size();
		for (int i = 0; i < size; i++) {
			if (i < num) {
				int next = paths[i];
				paths.push_back((next + 2) % 4);
			}
			else {
				int next = paths[i];
				paths.push_back(next);
			}
		}
		now++;
		num = num * 2;
	}
	
}

void draw_dragon(vector<int> paths, int x, int y) {
	int nx = x;
	int ny = y;
	map[ny][nx] = 1;

	for (int i = 0; i < paths.size(); i++) {
		int path = paths[i];
		nx = nx + dx[path];
		ny = ny + dy[path];
		map[ny][nx] = 1;
	}
}

int check_box() {
	int count = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 &&  map[i][j + 1] == 1 && map[i + 1][j + 1] == 1) {
				count++;
			}
		}
	}

	return count;
}

int main() {
	int n;
	cin >> n;

	Init();


	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		Dragon dragon = { x, y, d, g };
		dragons.push_back(dragon);
	}

	for (int i = 0; i < n; i++) {
		int x = dragons[i].x;
		int y = dragons[i].y;
		int direction = dragons[i].d;
		int generation = dragons[i].g;

		if (generation == 0) {
			map[y][x] = 1;
			map[y + dy[direction]][x + dx[direction]] = 1;
			continue;
		} 

		vector<int> paths;
		if (direction == 0) {
			paths.push_back(0);
			paths.push_back(1);
			get_paths(paths, 1, generation);
		} else if (direction == 1) {
			paths.push_back(1);
			paths.push_back(2);
			get_paths(paths, 1, generation);
		} else if (direction == 2) {
			paths.push_back(2);
			paths.push_back(3);
			get_paths(paths, 1, generation);
		} else if (direction == 3) {
			paths.push_back(3);
			paths.push_back(0);
			get_paths(paths, 1, generation);
		}

		draw_dragon(paths, x, y);
	}

	int answer =  check_box();

	cout << answer;
	
}