#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string s = "1";
char choice[3] = { '1', '2', '3' }; 
bool find_answer = false;


void dfs(int depth, string newstring) {    
    // cout << newstring << "\n";
    if(find_answer) {
        return;
    }

    char last_string = newstring[newstring.length() - 1];
    bool duplicate = false;

    for(int i=1;  i <newstring.length()/2 + 1; i++) {
        string sub1 = newstring.substr(newstring.length() - i, i);
        string sub2 = newstring.substr(newstring.length() - 2*i, i);

        // cout << "sub1: " << sub1 << " sub2: " << sub2 << "\n"; 
        if(sub1 == sub2) {
            duplicate = true;
            break;
        }
    }

    if(depth == n && !duplicate) {
        find_answer = true;
        s = newstring;
        // cout << "find!\n";
        return;
    }

    if(duplicate) {
       // cout << "dulpicate!!\n"; 
       return; 
    } else {
        for(int i=0; i<3; i++) {
            if(last_string != choice[i]) {
                dfs(depth + 1, newstring + choice[i]);
            }
        }
    }
}

int main() {

    cin >> n;
    dfs(1, s);

    cout << s;
}

// 규칙을 찾았을떄 n = 7일떄와 8일떄 아예 규칙이 없고 문자열이 달랐다
// 이렇게 규칙이 없는 경우 완전탐색을 하기로한다
// 모든 경우를 따져야하기 때문에 backtracking을 사용한다
// backtracking과 dfs가 다른점은 dfs는 한번 간곳은 visited를 true로 두어서 다신 방문하지 않지만,
// 백트래킹의 경우 조건에 맞지 않다면 다시 false로 바꾸어 주어서 재 방문 한다는 점이다