    #include <iostream>
    #include <string>
    using namespace std;
    char map[65][65];
    int n;
    string ans = "";

    void quadTree(int start_x, int start_y, int end_x, int end_y, int size) {
        // cout << "(" << start_x << ", " << start_y << ")" << "  (" << end_x << ", " << end_y << ")\n"; 

        int square_size = size / 2;
        bool same = true;
        char first = map[start_x][start_y];
        for(int i = start_x; i <= end_x; i++) {
            for(int j = start_y; j <= end_y; j++) {
                if(map[i][j] != first) {
                    same = false;
                    break;
                }
            }
            if(!same) break;
        }
        
        if(same) {
            ans += first;
        } else {
            ans += "(";
            quadTree(start_x, start_y, start_x + square_size - 1, start_y + square_size - 1, square_size);
            quadTree(start_x, start_y + square_size, start_x + square_size - 1, start_y + square_size + square_size - 1, square_size);
            quadTree(start_x + square_size, start_y , start_x + square_size + square_size - 1, start_y + square_size - 1, square_size);
            quadTree(start_x + square_size, start_y + square_size, start_x + square_size + square_size - 1, start_y + square_size + square_size - 1, square_size);
            ans +=  ")";
        }
    }

    int main() {

        cin >> n;

        for(int i=1; i<=n; i++) {    
            string s;
            cin >> s;

            for(int j=1; j <= n; j++) {
                map[i][j] = s[j-1];
            }
        }

        quadTree(1, 1, n, n, n);
        cout << ans;
    
    }