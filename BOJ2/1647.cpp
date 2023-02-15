#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int tree[100001];
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
    int v, e;
    cin >> v >> e;

    for(int i=0; i<e; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        graph.push_back({ cost, from, to });
    }
    sort(graph.begin(), graph.end());

    // for(int i=0; i<graph.size(); i++) {
    //     cout << get<0>(graph[i]) << " " << get<1>(graph[i]) << " " << get<2>(graph[i]) << "\n";
    // }

    for(int i=0; i<100001; i++) tree[i] = i;

    int ans = 0;
    int max_cost = 0;
    for(int i=0; i<graph.size(); i++) {
        int cost = get<0>(graph[i]);
        int node1 = get<1>(graph[i]);
        int node2 = get<2>(graph[i]);
        
        if(get_parent(node1) != get_parent(node2)) {
            merge(node1, node2);

            max_cost = max(cost, max_cost);
            ans += cost;
        }
    }

    // for(int i=1; i<v; i++) {
    //     cout << tree[i] << " ";
    // }

    cout << ans - max_cost;
}