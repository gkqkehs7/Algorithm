#include <iostream>
#include <string>
using namespace std;

int sosuToInt(string sosu) {
    string res = "";

    if(sosu[0] == '0') {
        for(int i=2; i<sosu.length(); i++) {
            res += sosu[i];
        }
    } else {
        for(int i=0; i<sosu.length(); i++) {
            if(sosu[i] != '.') res += sosu[i];
        }
    }
   
    return stoi(res);
}

int temp(int a) {
    
}

int main() {
    string a;
    int b;
    cin >> a >> b;
    
    bool start = false;
    int sosu = 0;
    for(int i=0; i<a.length(); i++) {
        if(start) sosu++;

        if(a[i] == '.') {
            start = true;
        }
    }
    cout << sosu << "\n";
    cout << sosuToInt(a);

}