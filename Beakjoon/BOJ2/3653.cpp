#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    while(t--) {
        int n, m;
        vector<int> v;
        cin >> n >> m;

        for(int i=0; i<m; i++) {
            int input;
            cin >> input;
            v.push_back(input);
        }
    }
}