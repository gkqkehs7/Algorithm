#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int map[51][51] = { 0, };
vector<pair<int, int>> chick;
vector<pair<int, int>> house;

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int input;
            cin >> input;

            if(input == 2) {
                chick.push_back({ i,j });
            } else if(input == 1) {
                house.push_back({ i,j });
            }
        }
    }

    vector<int> comb(chick.size() - 1);
    for(int i=0; i<m; i++) {
        comb.push_back(1);
    }

    // for(int i=0; i<comb.size(); i++) {
    //     cout << comb[i] << " ";
    // }


    int min_chick_dis = 1000000000;
    do {

        vector<pair<int, int>> temp;
        for(int i = 0; i < comb.size(); i++){
			 if (comb[i] == 1) {
                  // cout << chick[i].first << " " << chick[i].second << "\n";
                 temp.push_back({ chick[i].first, chick[i].second });
			 }
		}
        int chick_dis = 0;

        for(int i=0; i<house.size(); i++) {
            int min_dis = 1000000000;
            for(int k=0; k<temp.size(); k++) {
                int dis = abs(temp[k].first - house[i].first) + abs(temp[k].second - house[i].second);
                if(dis < min_dis) {
                    min_dis = dis;
                }
            }
            chick_dis += min_dis;
        }
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         if(map[i][j] == 1) {
                    
        //         }
        //     }
        // }
        
        // cout << chick_dis << "\n";
        if(chick_dis < min_chick_dis) {
            min_chick_dis = chick_dis;
        }
	
    } while(next_permutation(comb.begin(), comb.end()));

    cout << min_chick_dis;
}