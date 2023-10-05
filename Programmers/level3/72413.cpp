#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
int dp[201][201];

// s -> 출발 / a -> a 도착지점 / b ->b 도착지점
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    for(int i=0; i<201; i++) {
        for(int j=0; j<201; j++) {
            if(i == j) {
                dp[i][j] = 0;
                continue;
            } 
            dp[i][j] = 200000000;
        }
    }

    for(int i=0; i<fares.size(); i++) {
        int start = fares[i][0];
        int end = fares[i][1];
        int cost = fares[i][2];
        
        dp[start][end] = cost;
        dp[end][start] = cost;
    }
    
    for(int k=0; k<201; k++) {
        for(int i=0; i<201; i++) {
            for(int j=0; j<201; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }


    int answer = dp[s][a] + dp[s][b];

    for(int i=1; i<=n; i++) {
        answer = min(answer, dp[s][i] + dp[i][a] + dp[i][b]);
    }
    cout << answer;

    return answer;
}