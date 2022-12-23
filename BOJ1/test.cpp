#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string s = "1";
vector<int> v;
bool visited[81] = { false };
char choice[3] = { '1', '2', '3' }; 

bool dfs(int depth) {    

    bool find = true;
    char last_char = s[depth - 1];



    for(int i=0; i<3; i++) {
        if(choice[i] != last_char && visited[depth] == false) {
            s += choice[i];
            visited[depth] = true;
            if(dfs(depth + 1)) {
                cout << s;
                exit(1);
            };
            visited[depth] = false;
        }
    }
}

int main() {

    cin >> n;

    visited[0] = true;
    dfs(1);
}