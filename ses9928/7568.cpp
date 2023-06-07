#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> v;

    for(int i=0; i<n; i++) {
        int wei, hei;
        cin >> wei >> hei;
        v.push_back({ wei, hei, i });
    }

    int ranks[51];
    // 55 181
    // 54 181
    // 56 181
    // 55 179
    // 56 182
    // 54 190
    // 1 1 2 1 4 1

    for(int i=0; i<n; i++) {
        int prev_wei = get<0>(v[i]);
        int prev_hei = get<1>(v[i]);
        int prev_num = get<2>(v[i]);
        int count = 0; // 나보다 덩치 큰 사람 count

        for(int j=0; j<n; j++) {
            if(i == j) {
                continue;
            }
            int cur_wei = get<0>(v[j]);
            int cur_hei = get<1>(v[j]);
            int cur_num = get<2>(v[j]);

            if(cur_wei > prev_wei && cur_hei > prev_hei) {
                count++;
            } 
        }

        ranks[prev_num] = count + 1;
    }

    for(int i=0; i<n; i++) {
        cout << ranks[i] << " ";
    }
}