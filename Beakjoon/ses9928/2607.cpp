#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int comp[27];
    string str;
    cin >> str;

    for(int i=0; i<27; i++) {
        comp[i] = 0;
    }

    for(int i=0; i<str.length(); i++) {
        comp[str[i] - '0' - 17]++;
    }

    int answer = 0;
    for(int i=1; i<n; i++) {
        string input;
        cin >> input;

        int arr[27];

        for(int j=0; j<27; j++) arr[j] = 0;

        for(int j=0; j<input.size(); j++) {
            arr[input[j] - '0' - 17]++;
        }

        int diff = 0;
        bool similar = false;
        if(input.size() == str.size()) {
            for(int j=0; j<27; j++) {
                if(comp[j] != arr[j]) {
                    diff++;
                }
            }  


            if(diff == 0 || diff == 2) {
                similar = true;
            }
        } else if(input.size() - str.size() == 1){
            for(int j=0; j<27; j++) {
                if(comp[j] != arr[j]) {
                    diff++;
                }
            }

            if(diff == 1 || diff == 3) {
                similar = true;
            }
        } else if(input.size() - str.size() == - 1){
            for(int j=0; j<27; j++) {
                if(comp[j] != arr[j]) {
                    diff++;
                }
            }

            if(diff == 1 || diff == 3) {
                similar = true;
            }
        } 
        
        
        if(similar) answer++;
    }

    cout << answer;
}