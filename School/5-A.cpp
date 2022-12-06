#include <iostream>
#include <set>
#include <string>

using namespace std;
int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string s1, s2;
		cin >> s1 >>  s2;

		set<char> ss1;
		set<char> ss2;


		for (int i = 0; i < s1.length(); i++) {
			ss1.insert(s1[i]);
		}


		for (int i = 0; i < s2.length(); i++) {
			ss2.insert(s2[i]);
		}
	
		bool same = true;

		if (ss1.size() != ss2.size()) {
			same = false;
		}
		else {
			for (int i = 0; i < s1.size(); i++) {
				
				set<char>::iterator iter1;
				set<char>::iterator iter2;

				iter1 = ss1.begin();
				iter2 = ss2.begin();

				while (iter1 != ss1.end()) {
					if (*iter1 != *iter2) {
						same = false;
						break;
					}
					iter1++;
					iter2++;
				}
				
			}
		}

		if (same) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	} 

}