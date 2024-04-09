#include <iostream>
#include <vector>

using namespace std;

int n = 5;
int r = 3;
bool visited1[101] = { false, };
bool visited2[101] = { false, };


void get_combinations(int idx, int depth) {
    if(depth == r) {
        for(int i=0; i<n; i++) {
            if(visited1[i]) {
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
    }

    for(int i=idx; i<n; i++) {
        if(visited1[i] == false) {
            visited1[i] = true;
            get_combinations(i, depth + 1);
            visited1[i] = false;
        }
    }
}

void get_permutations(vector<int> temp) {
    if(temp.size() == r) {
        for(int i=0; i<temp.size(); i++) {
            cout << temp[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=0; i<n; i++) {
        if(visited2[i] == false) {
            visited2[i] = true;
            temp.push_back(i + 1);
            get_permutations(temp);
            temp.pop_back();
            visited2[i] = false;
        }
    }
}

int main() {
    get_combinations(0, 0);
    cout << "----------\n";
    vector<int> temp;
    get_permutations(temp);
}