#include <iostream>
#include <stack>
using namespace std;

int dp[100001] = { 0, };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    stack<int> s;
    int ans = 0;
    

    // 처음엔 높이의 개수가 건물의 개수라고 생각함
    
    //    xx
    //  xxxxxx
    //  xxxxxx
    //  xxxxxx  -> 2개

    //  xx xx  
    //  xxxxxxxxx
    //  xxxxxxxxxxx -> 3개
    // 이런경우가 안됨 -> 이전 건물보다 높아지는 경우에 새로 세어야한다.
   
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;

        // x좌표는 필요없고 y좌표만 다룸
        if(y == 0) { // 건물의 끝
            while(!s.empty()) {
                s.pop();
                ans++;
            }
        } else {
            if(!s.empty()) {
                if(s.top() < y) { // 이전 건물보다 높아지는 경우는 새롭게 추가
                    s.push(y);
                } else if (s.top() > y) { // 이전 건물보다 낮은 경우 자신보다 같거나 높은 건물들을 모두 pop하며 개수 세기
                    while(!s.empty() && s.top() >= y) {
                        if(s.top() != y) {
                            ans++;
                        }
                        s.pop();
                    } 
                    s.push(y);
                }
            } else {
                s.push(y); 
            }
        }
    }

    while(!s.empty()) {
        s.pop();
        ans++;
    }


    cout << ans;
}