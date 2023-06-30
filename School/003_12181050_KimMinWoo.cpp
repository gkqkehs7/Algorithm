   #include <iostream>
   #include <vector>
   #include <string>
   using namespace std;

   vector<string> v;
   vector<string> temp;

   // (x^2 + y^2) % d 계산하는 함수
   int cal(int a, int b, int d) {
      return ((a * a) + (b * b)) % d;
   }

   // 결과를 담은 배열을 순회하며 vector에 담아준다. 
   // s[1][n]를 s[2][n]값을 통해 1~s[2][n] / s[2][n]+1~n으로 i,j가 서로 같은 값이 나올떄까지 계속 재귀로 나누어준다. 
   // 같은 값이 나오면 v vector에 넣어준다 괄호도 같이 넣어준다.

   void print_optimal_parens(int s[][1001], int i, int j) { // 그리고 여기 s배열 입력받는 부분을 저랑 다르게 하세여
      if (i == j) {
         v.push_back(to_string(i)); // string vector이므로 to_string으로 정수를 string으로 바꿔주는 과정
      } else {
         v.push_back("(");
         print_optimal_parens(s, i, s[i][j]);
         print_optimal_parens(s, s[i][j] + 1, j);
         v.push_back(")");
      }
   }

   int main() {
      int T;
      cin >> T;

      while (T--) {
         int n, d;

         cin >> n >> d;

         int p[1001]; // 차원에 대한 서열을 입력 받을 배열
         int s[1001][1001]; // dp값이 최저일때 k를 담을 배열 (어디 부분에서 괄호를 씌울지 결정하는 역할)
         int dp[1001][1001]; // 행렬곱의 최저 값을 저장하는 역할 dp[a][b]는 a부터 b행렬까지의 곱셈수의 최저 값

         for (int i = 0; i < n + 1; i++) cin >> p[i];

         for (int i = 1; i <= n; i++) dp[i][i] = 0; // 대각선은 0으로 초기화

         for (int r = 2; r <= n; r++) { // 자신기준 왼쪽 값들 순회할 변수
            for (int i = 1; i <= n - r + 1; i++) { // 자신기준 아래쪽 값들 순회할 변수
               int j = i + r - 1;
               dp[i][j] = 999999999;   

               // 점화식 [1][3]이라면 [1][2]*[3][3]과 [1][1]*[2][3]중에 선택 k로 i부터 j까지 순회하여 가장 작은 값을 dp에저장
               for (int k = i; k < j; k++) { 
                  int compare = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                  if (dp[i][j] > compare) {
                     dp[i][j] = compare;
                     s[i][j] = k;
                  }
               }
            }
         }

         print_optimal_parens(s, 1, n);  

         // 위에서 구한 string (6((3 4) 5)) 같은 값들을 순회
         // vector temp를 stack의 역할로 사용
         // 여는 괄호가 나왔을때는 continue로 넘어가고
         // 숫자가 나왔을때는 temp vector 맨뒤에 저장한다
         // 닫는 괄호가 나왔을때는 temp의 맨 뒤 두개의 값을 계산하여 다시 temp의 맨 뒤에 넣어준다.
         // 마지막으로 남은 temp[0]이 답이된다.

         // 이 부분이 직접 구현해야 하는 부분
         for(int i=0; i<v.size(); i++) {
            if(v[i] == "(") {
               continue;
            } else if(v[i] == ")") {
               int first = stoi(temp[temp.size() - 1]);
               temp.pop_back();

               int second = stoi(temp[temp.size() - 1]);
               temp.pop_back();

               temp.push_back(to_string(cal(first, second, d)));
            } else {
               temp.push_back(v[i]);
            }
         }
         
         for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
               cout << dp[i][j] << " ";
            }
            cout << "\n";
         }

         cout << "\n";
         
         for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
               cout << s[i][j] << " ";
            }
            cout << "\n";
         }

         // cout << dp[1][n] << "\n" << temp[0] << "\n";
         
         // // vector 초기화
         // temp.clear();
         // v.clear();
      }
   }