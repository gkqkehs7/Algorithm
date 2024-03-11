#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int start;
    int end;
    int cost;
};

vector<Node> graph;
int tree[10001];

int find_parent(int child) {
    if(tree[child] == -1) return child;
    return tree[child] = find_parent(tree[child]);
}

void merge(int child1, int child2) {
    int child1_parent = find_parent(child1);
    int child2_parent = find_parent(child2);
    
    if(child1_parent == child2_parent) return;

    if(child1_parent > child2_parent) {
        tree[child1_parent] = child2_parent;
    } else {
        tree[child2_parent] = child1_parent;
    }
}

bool compareNodes(const Node& a, const Node& b) {
    return a.cost > b.cost;
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i<10001; i++) tree[i] = -1;

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        Node new_node;
        new_node.start = a;
        new_node.end = b;
        new_node.cost = c;

        graph.push_back(new_node);
    }

    int start, end;
    cin >> start >> end;

    sort(graph.begin(), graph.end(), compareNodes);

    for(int i=0; i<m; i++) {
        int child1 = graph[i].start;
        int child2 = graph[i].end;

        merge(child1, child2);

        if(find_parent(start) == find_parent(end)) {
            cout << graph[i].cost;
            break;
        }
    }

    return 0;
}