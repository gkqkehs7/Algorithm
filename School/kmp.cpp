#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    string s = "abcab";
    string t = "abcacabbcabccabcac";


    for(int i=0; i<t.length(); i++) {

        int same_num = 0;
        for(int j=0; j<s.length(); j++) {
            if(t[i] == s[j]) {
                same_num++;
            }
        }

        
    }
}