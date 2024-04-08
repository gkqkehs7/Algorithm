    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;
    int r, c, k;
    int row_size = 3;
    int col_size = 3;
    int map[101][101];

    struct Num {
        int value;
        int count;
    };

    bool compare(Num n1, Num n2) {
        if(n1.count == n2.count) {
            return n1.value < n2.value;
        } 

        return n1.count < n2.count;
    }

    int sort_row(int row_index) {
        vector<Num> temp;

        for(int i=0; i<col_size; i++) {
            int value = map[row_index][i];

            if(value != 0) {
                bool find = false;
                for(int j=0; j<temp.size(); j++) {
                    if(temp[j].value == value) {
                        temp[j].count += 1;
                        find = true;
                    }
                }

                if(!find) {
                    temp.push_back({ value, 1 });
                }
            }
            
        }

        sort(temp.begin(), temp.end(), compare);

        vector<int> v;
        for(int i=0; i < temp.size(); i ++) {
            v.push_back(temp[i].value);
            v.push_back(temp[i].count); 
        }
        
        for(int i=0; i<100; i++) {
            if(i < v.size()) {
                map[row_index][i] = v[i];
            } else {
                map[row_index][i] = 0;
            }
        }
        
        return v.size();
    }

    int sort_col(int col_index) {
        vector<Num> temp;

        for(int i=0; i<row_size; i++) {
            int value = map[i][col_index];

            if(value != 0) {
                bool find = false;
                for(int j=0; j<temp.size(); j++) {
                    if(temp[j].value == value) {
                        temp[j].count += 1;
                        find = true;
                        break;
                    }
                }

                if(!find) {
                    temp.push_back({ value, 1 });
                }
            } 
        }

        sort(temp.begin(), temp.end(), compare);
        
        vector<int> v;
        for(int i=0; i < temp.size(); i++) {
            v.push_back(temp[i].value);
            v.push_back(temp[i].count); 
        }
        
        for(int i=0; i<100; i++) {
            if(i < v.size()) {
                map[i][col_index] = v[i];
            } else {
                map[i][col_index] = 0;
            }
        }
        
        return v.size();
    }

    void print_map() {
        for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                cout << map[i][j] << " ";
            }
            cout << "\n";
        }
        cout << '\n';
    }


    int main() {
        cin >> r >> c >> k;    

        for(int i=0; i<row_size; i++) {
            for(int j=0; j<col_size; j++) {
                cin >> map[i][j]; 
            }
        }
        

        int time = 0;
        while(true) {

            if(time > 100) {
                cout << -1;
                break;
            }

            int max_row_size = 0;
            int max_col_size = 0;

            if(map[r-1][c-1] == k) {
                cout << time;
                break;
            }

            if(row_size >= col_size) {
                for(int i=0; i<row_size; i++) {
                    max_col_size = max(max_col_size, sort_row(i));
                }
                col_size = max_col_size;
            } else {
                for(int i=0; i<col_size; i++) {
                    max_row_size = max(max_row_size, sort_col(i));
                }
                row_size = max_row_size;
            }
    

            time++; 

            // print_map();
        }
    }