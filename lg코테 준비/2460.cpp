#include <iostream>
using namespace std;

int main() {

    int people = 0;
    int max_people = 0;
    for(int i=0; i<10; i++) {
        int down, up;
        cin >> down >> up;

        people = people - down + up;
        max_people = max(people, max_people);
    }

    cout << max_people;
}