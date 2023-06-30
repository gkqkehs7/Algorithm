#include <iostream>
using namespace std;

int main() {
    int p;
    cin >> p;

    while(p--) {
        int case_num;
        cin >> case_num;

        int arr[20];

        for(int i=0; i<20; i++) {
            cin >> arr[i];
        }

        int cnt = 0;
        for(int i=0; i<20; i++) {
            int now = arr[i];

            for(int j=0; j<i; j++) {
                int compare = arr[j];

                if(now < compare) {

                    for(int k=i; k>j; k--) {
                        cnt++;
                        arr[k] = arr[k-1];
                    }

                    arr[j] = now;
                    break;
                }
            }
        }
        
        cout << case_num << " " << cnt << "\n";
    }
}
