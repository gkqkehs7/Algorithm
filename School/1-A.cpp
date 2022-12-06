#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}

	if ( b != 0 ){
		gcd(b, a % b);
	}
	else {
		return a;
	}

}

int main() {

	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		int n, m;
		cin >> n >> m;
		
		int* inha = new int[n];
		int* birong = new int[m];
	

		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			inha[i] = input;
		}

		for (int i = 0; i < m; i++) {
			int input;
			cin >> input;
			birong[i] = input;
		}

		int inha_gcd = inha[0];
		int birong_gcd = birong[0];

		for (int i = 1; i < n; i++) {
			inha_gcd = gcd(inha_gcd, inha[i]);
		}

		for (int i = 1; i < m; i++) {
			birong_gcd = gcd(birong_gcd, birong[i]);
		}


		for (int i = 0; i < n; i++) {
			if (inha[i] % birong_gcd == 0) {
				birong_gcd = -1;
				break;
			}
		}

		for (int i = 0; i < m; i++) {
			if (birong[i] % inha_gcd == 0) {
				inha_gcd = -1;
				break;
			}
		}

		cout << birong_gcd << " " << inha_gcd << "\n";
	}
}