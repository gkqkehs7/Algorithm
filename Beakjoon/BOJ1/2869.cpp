#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, v;

    cin >> a >> b >> v;
    
    int day = ( v - a ) / ( a - b );
 
    cout << ceil(day) + 1;
}