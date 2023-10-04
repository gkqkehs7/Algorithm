#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int tree[101];

int get_parent(int child) {
    if(tree[child] == -1) {
        return child;
    }

    return tree[child] = get_parent(tree[child]);
}

void merge(int child1, int child2) {
    int parent1 = get_parent(child1);
    int parent2 = get_parent(child2);

    if(parent1 == parent2) return;

    if(parent1 < parent2) {
        tree[parent1] = parent2;
    } else {
        tree[parent2] = parent1;
    }
}

bool compareByThirdValue(vector<int>& a, vector<int>& b) {
    // 두 벡터의 세 번째 값으로 비교
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {

    for(int i=0; i<101; i++) {
        tree[i] = -1;
    }


    sort(costs.begin(), costs.end(), compareByThirdValue);

    int answer = 0;
    for(int i=0; i<costs.size(); i++) {
        int start = costs[i][0];
        int end = costs[i][1];
        int cost = costs[i][2];
       
        if(get_parent(start) != get_parent(end)) {
            merge(start, end);
            answer += cost;
        }
        
    }

    return answer;
}