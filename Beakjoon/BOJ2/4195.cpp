#include <iostream>
#include <string.h>
#include <string>
#include <unordered_map>

using namespace std;
int relation[200010];
int child_num[200010];

int find_parent(int child) {
    int parent = relation[child];

    if(parent == -1) return child;
    relation[child] = find_parent(parent);
    return relation[child];
}

void merge(int child1, int child2) {
    int c1_p = find_parent(child1);
    int c2_p = find_parent(child2);

    if(c1_p == c2_p) return;
    child_num[c2_p] += child_num[c1_p];
    relation[c1_p] = c2_p; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;
        
        unordered_map<string, int> m;
        unordered_map<string, int>::iterator iter;

        for(int i=0; i<200010; i++) {
            relation[i] = -1;
            child_num[i] = 1;
        }
        int m_size = 0;

        for(int i=0; i<n; i++) {
            string s1,s2;
            cin >> s1 >> s2;
            
            int s1_idx, s2_idx;

            iter = m.find(s1);
            if(iter == m.end()) {  
                s1_idx = m_size;
                m.insert({ s1, m_size });
                m_size++;
            }
            else {
                s1_idx = iter->second;
            }

            iter = m.find(s2);
            if(iter == m.end()) {
                s2_idx = m_size;
                m.insert({ s2, m_size });
                m_size++;
            }
            else {
                s2_idx = iter->second;
            }
            
            merge(s1_idx, s2_idx);
            cout << child_num[find_parent(s2_idx)] << "\n";
        }
    }
}