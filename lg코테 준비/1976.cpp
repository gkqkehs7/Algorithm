#include <iostream>
#include <vector>
using namespace std;

int dist[201][201];
vector<int> plan;

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> dist[i][j];
        }
    }

    for(int i=0; i<m; i++) {
        int city;
        cin >> city;
        plan.push_back(city);
    }


    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {

                if(i == j) {
                    dist[i][j] = 1;
                }

                if(dist[i][k] && dist[k][j]) {
                    dist[i][j] = 1;
                }
            }
        }
    }
    

    int prev = plan[0];
    bool cango = true;
    for(int i=1; i<plan.size(); i++) {
        int next = plan[i];

        if(dist[prev][next] == 0) {
            cango = false;
            break;
        }

        prev = next;
    }


    if(cango) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}