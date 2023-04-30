#include <iostream>
#include <stack>
#include <string>

using namespace std;

string s;
int a,t,g,c = 0;

void dfs(int depth, int a, int t, int g, int c) {

    int now = s[depth];

    if(now == 'a') {
        dfs(depth, a+1, t, g, c);
    } else if(now == 't') {
        if(a == 0) {
            ans++;
        } else {
            dfs(depth, a-1, t, g, c);
        }
    } else if(now == 'g') {
        dfs(depth, a, t, g + 1, c);
    } else if(now == 'c') {
        if(g == 0) {
            ans++;
        } else {
            dfs(depth, a, t, g - 1, c);
        }
    }

    // g를지우기
}

int main() {

    cin >> s;

    

    int ans = 0;
    for(int i=0; i<s.length(); i++) {
        char now = s[i];

        if(now == 'a') {
            a++;
        } else if(now == 't') {
            if(a == 0) {
                ans++;
            } else {
                a--;
            }
        } else if(now == 'g') {
            g++;
        } else if(now == 'c') {
            if(g == 0) {
                ans++;
            } else {
                g--;
            }
        }
    }

    cout << s.length() - ans - a - g;
}