#include <iostream>
#include <vector>
using namespace std;

vector<int> classes;
int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        classes.push_back(input);
    }

    int b, c;
    cin >> b >> c;

    long long answer = 0;

    for(int i=0; i<classes.size(); i++) {
        int student = classes[i];

        int rest_student = student - b;

        if(rest_student <= 0) {
            answer = answer + 1;
            continue;
        } else {
            int rest = rest_student % c;
            int num = rest_student / c;
            if(rest == 0) {
                answer += num + 1;
            } else {
                answer += num + 2;
            }
        }

    }

    cout << answer;


}
