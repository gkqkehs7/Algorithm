#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string.h>

using namespace std;

bool check[1001] = { false, };
vector<pair<int, int>> student;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            student.push_back({ b, a });
            
        }

        sort(student.begin(), student.end());

        int count = 0;
        for(int i=0; i<student.size(); i++) {
            int start = student[i].second;
            int end = student[i].first;
            
            while(start <= end) {
                if(check[start] == false) {
                    check[start] = true;
                    count++;
                    break;
                }
                start++;
            }
        }

        memset(check, false, sizeof(check));
        student.clear();
        cout << count << "\n";
    }
    
}