#include <iostream>
using namespace std;

int main() {

    int light[101];
    pair<int, int> student[101]; // 성별, 스위치 넘버

    int n, m;
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> light[i];
    }

    cin >> m;

    for(int i=0; i<m; i++) {
        cin >> student[i].first >> student[i].second;
    }

    for(int i=0; i<m; i++) {
        int gender = student[i].first;
        int light_num = student[i].second;

        if(gender == 1) { // 남학생
            int increase = light_num;
            while(light_num <= n) {
                if(light[light_num] == 1) {
                    light[light_num] = 0;
                } else {
                    light[light_num] = 1;
                }
                light_num += increase;
            }
        } else { // 여학생
            
            // 일단 자기 번호 off
            if(light[light_num] == 1) {
                light[light_num] = 0;
            } else {
                light[light_num] = 1;
            }

            int left = light_num - 1;
            int right = light_num + 1;
            while(left > 0 && right <= n && (light[left] == light[right])) {
                
                if(light[left] == 1) {
                    light[left] = 0;
                    light[right] = 0;
                } else {
                    light[left] = 1;
                    light[right] = 1;
                }

                left--;
                right++;
            }
        }
    }

    int temp = 1;
    while(n > 20) {
        for(int i=temp; i<temp + 20; i++) cout << light[i] << " ";
        cout << "\n";

        temp = temp + 20;
        n = n - 20;
    }
    
    for(int i=temp; i<temp + n; i++) cout << light[i] << " ";
}