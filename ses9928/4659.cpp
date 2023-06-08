#include <iostream>
#include <string>

using namespace std;

int main() {
    while(true) {
        string str;
        cin >> str;

        if(str == "end") {
            break;
        }

        char consonant[21] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
        char gather[5] = {'a','e','i','o','u'};

        int gather_count = 0;
        int three_dup_consonant = 0;
        int three_dup_gather = 0;
        bool goodPassword = true;
        char prev;

       
        for(int i=0; i<str.length(); i++) {
            char now = str[i];
            bool isConsonant = false;
            bool isGather = false;

            // 모음인지 확인
            for(int j=0; j<5; j++) {
                if(gather[j] == now) {
                    isGather = true;
                    gather_count++;
                    three_dup_gather++;
                    three_dup_consonant = 0;
                    break;
                }
            }

            // 자음인지 확인
            for(int j=0; j<21; j++) {
                if(consonant[j] == now) {
                    isConsonant = true;
                    three_dup_consonant++;
                    three_dup_gather = 0;
                    break;
                }
            }   

            // 3연속 모음
            if(three_dup_gather == 3) {
                goodPassword = false;
                // cout << "three_dup_gather\n";
                break;
            }

            // 3연속 자음
            if(three_dup_consonant == 3) {
                goodPassword = false;
                // cout << "three_dup_consonant\n";
                break;
            }

            // 같은 글자 연속 두번 방지
            if(i != 0) {
                if(prev == now) {
                    if(prev != 'e' && prev != 'o') {
                        // cout << "two duplicate alphabet\n";
                        goodPassword = false;
                        break;
                    }
                }
            }
            
            prev = now;
        }

        if(gather_count == 0) {
            // cout << "no gather\n";
            goodPassword = false;
        }

        if(goodPassword) {
            cout << "<" << str << ">" << " is acceptable.\n";
        } else {
            cout << "<" << str << ">" << " is not acceptable.\n";
        }
    }
}