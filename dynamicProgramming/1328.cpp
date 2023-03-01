#include <iostream>
using namespace std;

long long building[101][101][101];
int main() {
    int n,r,l;
    cin >> n >> r >> l;

    building[1][1][1] = 1;
    for(int i=2; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                building[i][j][k] = (building[i-1][j-1][k] + building[i-1][j][k-1] + building[i-1][j][k] * (i-2)) % 1000000007;
            }
        }
    }
    
    cout << building[n][r][l];
}