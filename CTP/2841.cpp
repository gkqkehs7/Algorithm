#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> v[7];

int main() {
    int n, p;
    cin >> n >> p;

    for(int i=0; i<n; i++) {
        int line, p;
        cin >> line >> p;
        v[line].push_back(p);
    }

    int ans = 0;
    for(int i=1; i<7; i++) {
        stack<int> s;

        for(int j=0; j<v[i].size(); j++) {
            int next = v[i][j];

            int temp = 0;
            if(!s.empty()) {
                if(s.top() > next) {
                    while(!s.empty() && s.top() > next) {  
                        s.pop();
                        ans++;
                    }
                    if(s.size() == 0) {
                        s.push(next);
                        ans++;
                    } else if(s.top() != next) {
                        s.push(next);
                        ans++;
                    }
                } else if(s.top() < next) {
                    s.push(next);
                    ans++;
                } else if(s.top() == next) {
                    continue;
                }
            } else {
                s.push(next);
                ans++;
            }
        
        }
        
    }

    cout << ans;
}