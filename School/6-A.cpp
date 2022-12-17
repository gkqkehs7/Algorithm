    #include <iostream>
    #include <stack>
    using namespace std;

    // stack<int> s1;
    stack<int> s2;
    int cn = 0;
    bool stop = false;

    void hanoi(int n, int from, int to, int by, int total) {

        if (n == 1) {
            if(!stop) {
                if (from == 2) {
                    s2.pop();
                }

                if (to == 2) {
                    s2.push(n);
                }
                cn++;
            }

            if (cn == total) {
                stop = true;
            }

            //cout << "move" << n << " " << from << "->" << to << "\n";
            return;
        }

        else {
            hanoi(n - 1, from, by, to, total);
            //cout << "move" << n << " " << from << "->" << to << "\n";
            if(!stop) {
                if (from == 2) {
                    s2.pop();
                }

                if (to == 2) {
                    s2.push(n);
                }
                cn++;
            }
            

            if (cn == total) {
                stop = true;
            }
            
            hanoi(n - 1, by, to, from, total);
            
        }
    }

    int main() {
        int T;
        cin >> T;

        for (int t = 0; t < T; t++) {
            int n, k;
            cin >> n >> k;

            hanoi(n, 1, 3, 2, k);

            if(s2.size() == 0) {
                cout << 0;
            } else {
                while(s2.size() !=0) {
                    cout << s2.top() << " ";
                    s2.pop();
                }
            }
            stop = false;
            cn = 0;
            cout << "\n";

        

        }

    }