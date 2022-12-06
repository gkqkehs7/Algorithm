#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N, p, q, x;
long long result;
vector<int> v1;
vector<int> v2;
bool visited[10] = { false };
int answer = 0;

void Permutation() {
	if (N == v2.size()) {
		
		
		for (int i = 0; i < v2.size(); i++) {
			result += v2[i] * pow(x, i);
		}
		int mod = result % 1013;

		if (mod >= p && mod <= q) {
			answer++;
		}
		
		result = 0;
		return;
	}

	for (int i = 0; i < v1.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			v2.push_back(v1[i]);
			Permutation();
			v2.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			int input;
			cin >> input;
			v1.push_back(input);
		}

		cin >> p >> q >> x;
		Permutation();
	
		cout << answer << "\n";

		v1.clear();
		v2.clear();
		for (int i = 0; i < 10; i++) {
			visited[i] = false;
		}

		result = 0;
		answer = 0;

	}

}