#include <iostream>
using namespace std;
int height, target, s, up, down;
int dp[1000001];
bool cango = false;

void dfs(int depth, int now) {
    if(now == target) {
        cango = true;
        return;
    }
    
    if(now + up <= height) {
        if(depth + 1 < dp[now+up]) {
            dp[now+up] = depth + 1;
            dfs(depth + 1, now + up);       
        }   
    }
    if(now - down >= 1) {
        if(depth +1 < dp[now-down]) {
            dp[now-down] = depth + 1;
            dfs(depth + 1, now - down); 
        }
    }
}

int main() {

    cin >> height >> s >> target >> up >> down;

    for(int i=0; i<1000001; i++) {
        dp[i] = 99999999;
    }
    dp[s] = 0;
    dfs(0, s);

    if(cango) {
        cout << dp[target];
    } else {
        cout << "use the stairs";
    }
    
}