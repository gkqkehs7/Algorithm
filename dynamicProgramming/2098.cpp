#include <iostream>
#include <vector>
#define MAX 1000000000
using namespace std;

int n;

int arr[5] = { 1, 2, 3, 4, 5 };
bool visited[5] = { false, false, false, false, false };
vector<pair<int, int>> graph[18];


vector<int> v;

void dfs(int now) {

    if(v.size() == 5) {
        return;
    }

    for(int i=0; i<graph[now].size(); i++) {
        int next = graph[now][i].first;
        int cost = graph[now][i].second;

        if(visited[next] == false && cost != 0) {
            visited[next] = true;
            v.push_back(next);

            dfs(next);      
            v.pop_back();
            visited[next] = false;
        }
        
    }
}

int main() {
    
   
}