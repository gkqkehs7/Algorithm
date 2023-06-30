#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

    
vector<string> voca;
unordered_map<string, int> hs;

bool compare(string a, string b) {
    if(hs[a] > hs[b]) {
        return true;
    } else if(hs[a] == hs[b]) {
        if(a.length() > b.length()) {
            return true;
        } else if(a.length() == b.length()) {
            if(a < b) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        
        if(str.length() >= m) {
           if(hs.find(str) == hs.end()) {
                hs[str] = 0;
                voca.push_back(str);
           }
           hs[str]++;
        }
    }

    sort(voca.begin(), voca.end(), compare);

    for (int i = 0; i < voca.size(); i++) {
        cout << voca[i] << '\n';
    }
}