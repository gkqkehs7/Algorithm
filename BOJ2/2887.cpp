#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
using namespace std;

int tree[100001];
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;
vector<tuple<int, int, int>> graph;


int get_parent(int child) {
    if(tree[child] == child) {
        return child;
    }

    return tree[child] = get_parent(tree[child]);
}

void merge(int child1, int child2) {
    int parent1 = get_parent(child1);
    int parent2 = get_parent(child2);

    if(parent1 == parent2) return;
    tree[parent2] = parent1;
}


int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int x, y, z;

        cin >> x >> y >> z;
        X.push_back({ x,i });
		Y.push_back({ y,i });
		Z.push_back({ z,i });
    }
    for(int i=0; i<100001; i++) tree[i] = i;

    sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

    for (int i = 0; i < n - 1; i++) {
		graph.push_back({ X[i + 1].first - X[i].first , X[i].second, X[i + 1].second });
		graph.push_back({ Y[i + 1].first - Y[i].first , Y[i].second, Y[i + 1].second });
		graph.push_back({ Z[i + 1].first - Z[i].first , Y[i].second, Y[i + 1].second });
	}

    sort(graph.begin(), graph.end());

    long long ans = 0;
    for(int i=0; i<graph.size(); i++) {
        int cost = get<0>(graph[i]);
        int node1 = get<1>(graph[i]);
        int node2 = get<2>(graph[i]);
        
        if(get_parent(node1) != get_parent(node2)) {
            merge(node1, node2);
            ans += cost;
        }
    }

    cout << ans;
}