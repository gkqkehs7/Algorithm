#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int num[500001];
int main() {
    int n, k;

    cin >> n >> k;

    string str;

    cin >> str;

    stack<int> s;

    for(int i=0; i<n; i++) {
        num[i] = str[i] - '0';
    }

    s.push(num[0]);

    for(int i=1; i<n; i++) {
        int now = num[i];

        while(k > 0 && s.size() > 0 && s.top() < now) {
            k = k - 1;
            s.pop();
        }

        s.push(now);
    }
    
    while(k > 0) {
        s.pop();
        k--;
    }

    vector<int> v;
    while(s.size() > 0) {
        v.push_back(s.top());
        s.pop();
    }
    
    for(int i=v.size() - 1; i >= 0; i--){
        cout << v[i];
    }
}