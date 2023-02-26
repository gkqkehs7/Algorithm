#include <iostream>
#include <vector>

using namespace std;
int dp[17][17];
vector<pair<int, int>> graph[18];

int main() {
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int cost;
            cin >> cost;
            graph[i].push_back({ j, cost });
        }
    }
}