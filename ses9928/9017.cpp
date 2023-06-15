#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        int arr[1001];
        int count[201];
        int scores[201];
        int team_count = 1;

        for(int i=0; i<201; i++) {
            count[i] = 0;
            scores[i] = 0;
        }

        for(int i=0; i<n; i++) {
            int input;
            cin >> input;
            arr[i] = input;
            count[input] += 1;
            team_count = max(team_count, input);
        }

        int score = 1;
        for(int i=0; i<n; i++) {
            if(count[arr[i]] >= 4) {
                scores[i] += score;
                score++;
            } 
        }

        for(int i=1; i<=team_count; i++) {
            cout << scores[i] << " ";
        }

        
        // pair<int, int> score[201];
        // int five[201]; // 다섯번째 주자 점수
        // int six[201];  // 여섯번째 주자 점수

        // for(int i=0; i<201; i++) {
        //     score[i].first = 0;
        //     score[i].second = 0;
        //     five[i] = 0;
        //     six[i] = 0;
        // }

        // for(int i=1; i<=n; i++) {
        //     int input;
        //     cin >> input;

        //     arr[i] = input;

        //     if(score[input].second < 4) {
        //         score[input].first += i;
        //         score[input].second += 1;
        //     } else if(score[input].second == 4) {
        //         five[input] = i;
        //         score[input].second += 1;
        //     } else if(score[input].second == 5) {
        //         six[input] = i;
        //     }  
        // }

        // for(int i=1; i<=n; i++) {
            
        // }

        // vector<pair<int ,int>> v;
        // int min_value = 999999999;
        // int cnt = 1;

        // while(score[cnt].second >= 4) {
        //     if(score[cnt].first < min_value) {
        //         v.clear();
        //         v.push_back({ cnt, score[cnt].first });
        //         min_value = score[cnt].first;
        //     } else if(score[cnt].first == min_value) {
        //         v.push_back({ cnt, score[cnt].first });
        //     }

        //     cnt++;
        // }

        // if(v.size() == 1) {
        //     cout << v[0].first << "\n";
        // } else if(v.size() > 1) {
            
        //     vector<pair<int ,int>> v1;
        //     int min2 = 999999999;
        //     // 5등 점수 추가
        //     for(int i=0; i<v.size(); i++) {
        //         v[i].second += five[v[i].first];

        //         if(v[i].second < min2) {
        //             v1.clear();
        //             v1.push_back({ v[i].first, v[i].second });
        //             min2 = v[i].second;
        //         } else if(v[i].second == min2) {
        //             v1.push_back({ v[i].first, v[i].second });
        //         }
        //     }

        //     if(v1.size() == 1) {
        //         cout << v1[0].first << "\n";
        //     } else {
        //         for(int i=0; i < v1.size(); i++) {
        //             v1[i].second += six[v1[i].first];  
        //         }

        //         sort(v1.begin(), v1.end());

        //         cout << v1[0].first << "\n";
        //     }

        // }
    }
}