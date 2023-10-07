#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> h;

int main() {
    h.insert({ "a", 1 });
    h.insert({ "b", 2 });
    h.insert({ "c", 3 });

    unordered_map<string, int>::iterator iter;
    iter = h.find("c");

    cout << iter->second;
}