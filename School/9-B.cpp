#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for(int t=0; t<T; t++) {
        string a;
        string b;
        
        cin >> a>> b;
        
        int temp_i = -1;
        int temp_j = -1;
        int result = 0;
        
        for(int i=0; i<a.length(); i++) {
            for(int j=temp_j+1; j<b.length(); j++) {
                if ( a[i] == b[j] ) {
                    result += max(i-temp_i-1, j-temp_j -1);
                    temp_i = i;
                    temp_j = j;
                    break;
                }
            }
        }
        
        result += max(a.length() - temp_i - 1, b.length() - temp_j - 1);
        cout << result << "\n";
    }
}