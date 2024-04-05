#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Tree {
	int x;
	int y;
	int age;
};

int n, m, k;
int map[11][11];
int food[11][11];
vector<Tree> trees;
vector<Tree> died_trees;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0 ,1 };

bool check(int x, int y) {
	if (x >= n || x < 0 || y >= n || y < 0) {
		return false;
	}

	return true;
}

bool compare(Tree a, Tree b) {
	return a.age < b.age;
}

void sort_trees() {
	sort(trees.begin(), trees.end(), compare);
}

int count_live_trees() {
	int count = 0;
	for (int i = 0; i < trees.size(); i++) {
		Tree tree = trees[i];
		int age = tree.age;

		if (age != 99999) {
			count++;
		}
	}
	return count;

}
void spring() {
	for (int i = 0; i < trees.size(); i++) {
		Tree tree = trees[i];

		int x = tree.x;
		int y = tree.y;
		int age = tree.age;
	
		if (map[x][y] >= age) {
			map[x][y] -= age;
			trees[i].age += 1;
		}
		else { // 죽은 경우
		
			trees[i].age = 99999; // 죽임
			died_trees.push_back({ x, y, age });
		}
	}
}

void summer() {
	for (int i = 0; i < died_trees.size(); i++) {

		Tree died_tree = died_trees[i];

		int x = died_tree.x;
		int y = died_tree.y;
		int age = died_tree.age;

		int bab = age / 2;

		map[x][y] += bab;
	}
	died_trees.clear();
}

void fall() {
	int count = 0;
	for (int i = 0; i < trees.size(); i++) {
		Tree tree = trees[i];

		int x = tree.x;
		int y = tree.y;
		int age = tree.age;


		if (tree.age % 5 == 0 && age != 99999) {
			for (int j = 0; j < 8; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
			
				if (check(nx, ny)) {
					count++;
					trees.push_back({ nx, ny, 1 });
				}
			}
		}
	}

	cout << count << "tree plused\n";
}

void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] += food[i][j];
		}
	}
}




void print_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}


void season() {
	for (int i = 0; i < k; i++) {
		sort_trees();
		
		cout << "spring\n";
		spring();
		print_map();
		cout << "summer\n";
		summer();
		print_map();
		cout << "fall\n";
		fall();
		print_map();
		cout << "winter\n";
		winter();
		print_map();
		cout << "live tree: " << count_live_trees() << "\n";
	}
}

int main() {
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int input;
			cin >> input;
	
			map[i-1][j-1] = 5;
			food[i-1][j-1] = input;
		}
	}


	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;

		Tree tree = { x, y, z };
		trees.push_back(tree);
	}

	season();

	cout << count_live_trees();
}