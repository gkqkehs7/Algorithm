#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int n;
    char game;
    cin >> n >> game;

    set<string> s;

    for(int i=0; i<n; i++) {
        string name;
        cin >> name;
        s.insert(name);
    }

    int people_num = s.size();
    int answer;

    if(game == 'Y') {
        answer = people_num;
    } else if(game == 'F') {
        answer = people_num / 2;
    } else {
        answer = people_num / 3;
    }

    cout << answer;
}