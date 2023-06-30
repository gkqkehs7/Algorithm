#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string table;
    bool eat[20001];

    cin >> table;

    int answer = 0;

    for(int i=0; i<20001; i++) eat[i] = false;

    for(int i=0; i<table.size(); i++) {
        if(table[i] == 'P') {
            if(i - k < 0) {
                for(int j = 0; j <= i + k; j++) {
                    if(table[j] == 'H' && eat[j] == false) {

                        // cout << i << " eat " << j << " hambuger\n";
                        eat[j] = true;
                        answer++;
                        break;
                    }
                }
            } else {
                for(int j = i - k; j <= i + k; j++) {
                    if(table[j] == 'H' && eat[j] == false) {

                        // cout << i << " eat " << j << " hambuger\n";
                        eat[j] = true;
                        answer++;
                        break;
                    }
                }
            }
            
        } else {
            continue;
        }
    }

    cout << answer;
    
}