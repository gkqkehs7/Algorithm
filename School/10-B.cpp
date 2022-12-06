#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
pair<int, int> sharks[100001];
int aqua_temp[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;


        int* aqua_temp = new int[m];

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            sharks[i].first = a;
            sharks[i].second = b;
        }

        for (int i = 0; i < m; i++) {
            int input;
            cin >> input;
            aqua_temp[i] = input;
        }

        sort(sharks, sharks + n);
        sort(aqua_temp, aqua_temp + m);

        int answer = 0;
        int idx = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < m; i++) {

            while (idx < n && sharks[idx].first <= aqua_temp[i]) {
                pq.push(make_pair(sharks[idx].second, sharks[idx].first));
                idx++;
            }


            while (!pq.empty() && (pq.top().first < aqua_temp[i])) {
                pq.pop();
            }


            if (!pq.empty()) {
                pq.pop();
                answer++;
            }
        }

        cout << answer << "\n";

    }
}