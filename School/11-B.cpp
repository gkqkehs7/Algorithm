/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int t=0; t<T; t++) {
        int n,m;
        cin >> n >> m;
        
        vector<pair<int, int> > score_team;
        int *player = new int[n];
        int *team_score = new int[m];
        int *can_game = new int[m];
        int gamenum = 0;
        int answer = 0;
        bool play = false;
        for(int i=0; i<n; i++) {
            int input;
            cin >> input;
            player[i] = input;
        }
        
        for(int i=0; i<m; i++) {
            team_score[i] = 0;
            can_game[i] = 0;
        }
        
        for(int i=0; i<n; i++) {
            if(i != 0 && player[i] == 1) {
                if(player[i-1] != 1) {
                    can_game[player[i-1]]++;
                    gamenum++;
                }
            }
            
            team_score[player[i]-1] += n - i;
        }
        
        for(int i=0; i<m; i++) {
            score_team.push_back(make_pair(team_score[i], i+1 ));
        }
        sort(score_team.begin(), score_team.end());
        
        while(gamenum) {
            if(score_team[0].second == 1) {
                break;
            }
            
            for(int i=0; i<score_team.size(); i++){
                if(score_team[i].second == 1){
                   score_team[i].first += 1;
                }
                
                if(can_game[score_team[i].second] > 0 && play == false) {
                    score_team[i].first -= 1;
                    gamenum--;
                    answer++;
                    play = true;
                }
            }
            
            sort(score_team.begin(), score_team.end());
            play = false;
        }
        
       if(score_team[0].second == 1) {
            cout << answer << "\n";
        } else {
            cout << -1 << "\n";
        }
            
    }

    return 0;
}
