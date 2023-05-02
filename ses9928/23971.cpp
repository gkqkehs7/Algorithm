#include <iostream>
using namespace std;

int main() {
    int h,w,n,m;

    cin >> h >> w >> n >> m;
    
    int first,second;

    if(w % (m+1) == 0) {
        first = (w / (m+1));
    } else {
        first = (w / (m+1)) + 1;
    }

    if(h % (n+1) == 0) {
        second = (h / (n+1));
    } else {
        second = (h / (n+1)) + 1;
    }

    cout << first * second;

}

// 인원을 배치해야하는 경우가 단 한가지라고 꺠달았다면 바로 구현을 들어간다.