#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int team[21][21] = { 0 };
int answer = 1000000;

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int input;
            cin >> input;
            team[i][j] = input;
        }
    }
    vector<int> num(n), comb(n);
  
    for (int i = n - (n/2); i < n; i++) {
        comb[i] = 1;
    }  

    do {
        int start_score = 0;
        int link_score = 0;

        for(int i = 0; i < comb.size() - 1; i++){
            
            int first = comb[i];
            for(int j = i + 1; j < comb.size(); j++){
                int second = comb[j];

                if(first == second) {
                    if(first == 1) {
                        start_score += team[i][j];
                        start_score += team[j][i];
                    } else {
                        link_score += team[i][j];
                        link_score += team[j][i];
                    }
                } 
            }
        }

        if(abs(start_score - link_score) < answer) {
            answer = abs(start_score - link_score);
        }
    
    } while(next_permutation(comb.begin(), comb.end()));
    
    cout << answer << "\n";
}