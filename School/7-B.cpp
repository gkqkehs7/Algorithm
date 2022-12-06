#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        int maxlen = 0;
        for (int i = 0; i < s.length(); i++) {

            int zero = 0;
            int one = 0;

            for (int j = i; j < s.length(); j++) {
                if (s[j] == '0') {
                    zero++;
                }
                else {
                    one++;
                }

                if (zero == one) {
                    if (j - i > maxlen) {
                        maxlen = j - i;
                    }
                }
            }
        }

        if (maxlen != 0) {
            cout << maxlen + 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
}