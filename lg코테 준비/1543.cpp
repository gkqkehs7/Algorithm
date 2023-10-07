#include <iostream>
#include <string>
using namespace std;

int main() {

    string str, s;
    getline(cin, str);
    getline(cin, s);

    int idx = 0;
    int count = 0;

    while(idx != -1 && idx < str.length()) {
        idx = str.find(s);
        str = str.substr(idx + s.length());

        if(idx != -1) {
            count++;
        }
    }

    cout << count;

}