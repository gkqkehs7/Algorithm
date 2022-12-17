#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int x, a, b;
		cin >> x >> a >> b;

		int tosoon = 0;
		int biryong = x;
		int tosoon_time = 0;
		int tosoon_break_time = b;
		bool tosoon_stop = false;
		int time = 0;

		while (true) {
		
			time++;

			if (tosoon_stop) {
				if (tosoon_break_time == 0) {
					tosoon_stop = false;
					tosoon_break_time = b;
					// cout << "tosson run!\n";
				}
				else {
					tosoon_break_time--;
				}
			}
			

			if (!tosoon_stop) {
				tosoon += 2;
				tosoon_time++;
			}
			biryong += 1;
			
			if (tosoon >= biryong) {
				break;
			}


			// cout << "tosson: " << tosoon << " biryong: " << biryong << "\n";

			if (tosoon_time % a == 0 && !tosoon_stop) {
				// cout << "tosson stop!\n";
				tosoon_stop = true;
				tosoon_time = 0;
			}
		}
		
		cout << time + x << "\n";
	}
}