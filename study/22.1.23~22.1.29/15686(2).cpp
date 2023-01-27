#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int n, m;
int map[51][51] = { 0, };
bool visited[2500] = { false, };

int chick_size = 0;
int house_size = 0;
pair<int, int> chick[2500];
pair<int, int> house[2500];
pair<int, int> temp[2500];

void comb(int depth, int next) {
    if(depth == m) {

    }

    for(int i=next; i<chick_size; i++) {
        if(visited[i] == false) {
            temp[depth] = 
            comb(depth + 1, i + 1);
        }
    }

}
int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int input;
            cin >> input;

            if(input == 2) {
                chick[i].first = i;
                chick[i].second = j;
                chick_size++;
            } else {
                house[i].first = i;
                house[i].second = j;
                house_size++;
            }
        }
    }
}