# Algorithm

### vector사용법

- 1차원 vector

```cpp
#include <vector>                    
vector<int> v;                       // int타입 벡터 생성
vector<int> v = { 1, 2, 3 };         // int형 백터 생성 후 1, 2, 3 으로 초기화
v.push_back(2);                      // v[3]부터 값 추가됨

vector<int> v(10);                   // 10개의 원소를 0으로 초기화
v.push_back(2);                      // v[10]부터 값 추가됨

vector<int> v(10, 3);                // 5개의 원소를 3으로 초기화
v.push_back(2);                      // v[10]부터 값 추가됨
```

 <br/>

- 2차원 vector

```cpp
#include <vector>                    
vector<int> v[10];                   // int타입 벡터 배열(크기 : 10) 생성
// v[0] ~ v[9]까지만 사용 가능
vector<int> v[] = {{ 1, 2}, {3, 4}}; // v[0] ~ v[1]까지만 사용 가능

vector<vector<int>> v;               // 2차원 백터 생성(행과 열 모두 가변)
vector<int> v2;
v.push_back(v2);
```

 <br/>

- vector 삭제

```cpp
v.pop_back();                        // 마지막에 넣은 값 제거
v.erase(vec.begin()+10);             // index 10의 값을 제거
v.erase(vec.begin(), vec.begin()+5); // index 0~5의 값을 제거
v.clear();                           //모든 값 제거
```

 <br/>

### string사용법

- 특정 문자열 찾기
    
    str.find(”bcd”) “bcd”가 문자열에 있는지 확인 있다면 해당 부분의 첫번째 index반환
    
    ```cpp
    #include <string>
    string s = "abcd";
    
    int index = s.find("bcd");
    ```
    
     <br/>
    
- 문자열 자르기
    
    str.substr(index, number) 자를 index부터 자를 개수
    
    ```cpp
    #include <string>
    string s = "1234";
    
    string a = s.substr(0,2); // 12
    string b = s.substr(2,2); // 34
    ```
    
     <br/>
    

### 방향성 그래프를 사용해야할때와 사용하지 않아야 할떄

### DFS

```cpp
vector<int> graph[1001];
bool visited[1001] = { false };

void dfs(int now) {
    cout << now << " ";
     for(int i=0; i<graph[now].size(); i++) {
        int next = graph[now][i];

        if(visited[next] == false) {
            visited[next] = true;
            dfs(next);
        }
    }
}

int main() {
    int n,m,v;
    cin >> n >> m >> v;

    for(int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=0; i<n+1; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    visited[v] = true;
    dfs(v);
}
```

<br/>

### BFS

```cpp
vector<int> graph[1001];
bool visited[1001] = { false };

int main() {
    int n,m,v;
    cin >> n >> m >> v;

    for(int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=0; i<n+1; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

		queue<int> q;
    q.push(v);
    visited[v] = true;

    while(!q.empty()) {
        int now = q.front();
        cout << now << " ";
        q.pop();

        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i];

            if(visited[next] == false) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}
```

<br/>

### 백트래킹

- dsf와 똑같이 규칙이 존재하지 않아 모든 경우를 따져야할때 backtracking을 사용한다.
- backtracking과 dfs가 다른점은 dfs는 한번 간곳은 visited를 true로 두어서 다신 방문하지 않지만, 백트래킹의 경우 조건에 맞지 않다면 다시 false로 바꾸어 주어서 재 방문 한다는 점이다.

```tsx
void backTracking(int depth) {

    if(depth == n) { // 범위의 끝에 다달았을때 return
        return;
    }

    for(int i=0; i<graph[now].size(); i++) {
        int next = graph[now][i];

        if(visited[next] == false) {
            visited[next] = true;
            backTracking(next);
						visited[next] = false;
        }
    }
}
```

[백준 2661 - 좋은수열](https://www.acmicpc.net/problem/2661)

이 문제는 n=7일때와 n=8일때 결과가 아예 달랐다. 규칙이 없다는 것이다. 따라서 완전탐색을 하기로 했고, 1231이 실패했을때 1232 이런식으로 depth가 같지만 앞 경우가 실패했을때 뒷 경우도 살펴보아야 하므로 backtracking을 이용하였다.

<br/>

### 

### **Dynamic Programming**

- Top-down - 큰 문제를 작은 문제로 나누어 푸는 방식

```cpp
int dp[100] = { 0,}; 
 
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        if (dp[n] > 0) {        
            return dp[n];    
        }
        dp[n] = fibonacci(n-1) + fibonacci(n-2);
        return dp[n];
    }
}
```

fibonacci(10)을 구하려면 fibonacci(10)을 fibonacci(9), fibonacci(8)로 나누고 1이 될때까지 이를 계속 나누어 fibonacci(10)을 구하여 dp배열에 저장한다음, 다음 재귀함수에서 fibonacci(10)이 나왔을때, 바로 꺼내어 return해주는 방식이다.

10을 9,8 9를 8,7..이렇게 큰 수를 작은 수로 쪼개어 풀어 나가기 때문에, top-down방식이다.

이 방식은 연산 수가 줄어들지만, 재귀함수가 너무 많이 호출되어 overhead가 존재하기 때문에 비효율 적이다. 

<br/>

- Bottom-up - 작은 문제를 해결하여 큰 문제를 해결하는 방식

```cpp
int dp[100] = { 0,};    
 
int fibonacci(int n) {
    dp[0] = 0;
    dp[1] = 1;
    int i;
    for (i=2; i<=n; i++) {   
         dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
```

dp[0]과 dp[1]을 이용해 dp[2]를 구하고 dp[1]과 dp[2]를 이용해 dp[3]을 구하면서 원하는 수까지 다다르는 bottom-up방식이다. 

이렇게 풀면 연산 수도 줄어들면서, 재귀함수로 인한 overhead가 없기 떄문에 효율적이다. dp문제는 되도록 bottom-up방식으로 풀도록 하자.

[백준 1003 - 피보나치 함수](https://www.acmicpc.net/problem/1003)

<br/>

### 투 포인터

[백준 1644 - 소수의 연속합](https://www.acmicpc.net/problem/1644)

<br/>

### 순열과 조합

- 순열 - vector와 algorithm의 next_permutation으로 구현한다.

```cpp
#include <algorithm>
    
vector<int> perm(n);
for(int i = 1; i <= n; i++)
    perm.push_back(i);

do {
    for(int i = 0; i < v.size(); i++){
       cout << perm[i] << " ";
		}
		cout << "\n";
} while(next_permutation(perm.begin(), perm.end()));
```

<br/>

- 조합(nCk) - 위의 순열을 구하는 방식으로 k개의 1, n개의 0을 순열을 구해서 1인 것만을 출력하면, 조합이 된다.

```cpp
#include <algorithm>
    
vector<int> perm(n), comb(n);
for(int i = 1; i <= n; i++)
    comb.push_back(i);

for(int i = 0; i <= k; i++)
    perm.push_back(1);

do {
    for(int i = 0; i < perm.size(); i++){
			 if (perm[i] == 1) {
				 cout << comb[i] << " ";
			 }
		}
		cout << "\n";
} while(next_permutation(perm.begin(), perm.end()));
```

[백준 14889 - 스타트와 링크](https://www.acmicpc.net/problem/14889)

<br/>

### 소수 판별법

- 어떤 수가 소수인지 확인 하는 알고리즘
- 어떤 x가 소수인지 확인할 때는 2부터 x의 제곱근 까지만 나누어 보는 것으로 확인할 수 있다.

```cpp
#include <cmath>
int x = 10;
sqrt(x); //x의 제곱근
pow(x, 2); // x의 n제곱 

for(int i=2; i<sqrt(x); i++) {
	if(x % i == 0) {
		sosu = false;
	}
}
```

[백준 1929 - 소수 구하기](https://www.acmicpc.net/problem/1929)

<br/>

### 에라토스테네스의 체

- n이 주어졌을 때, 1 부터 n 까지의 모든 소수를 구하는 방법
- 2 부터 n의 제곱근까지 검사하여 소수들의 배수를 지워 나간다.

```cpp
int check[1000000] = { 1, 1, 0 };
for(int i=2; i<= sqrt(n); i++) {
    if(check[i] == 0) {
        for(int j= i + i; j <= n; j += i) {
            check[j] = 1;
        }
    }
}
```

[백준 1644 - 소수의 연속합](https://www.acmicpc.net/problem/1644)

<br/>

### 소수 판별법+에라토스테네스의 체로 소수 판별하기

- 이 방법은 배열의 최대 크기보다 훨씬 큰 수를 소수 판별할때 사용한다.
- 먼저 에라토스테네스의 체를 이용하여 check배열을 초기화한다.
- 최대한 소수를 벡터에 담고, 구하려는 수를 소수들로 나누어주며 나누어진다면 소수가 아니다. 소수가 아닌 수들은 소수를 약수로 갖기 때문이다.

```cpp
int check[1000000000] = { 1, 1, 0 };
for(int i=2; i<= sqrt(n); i++) {
    if(check[i] == 0) {
        for(int j= i + i; j <= n; j += i) {
            check[j] = 1;
        }
    }
}

for(int i=2; i<1000000000; i++) {
	if(!check[i]) v.push_back(i);
}

for(int i = 0; i < v.size(); i++) {
	if(target % v[i] == 0) break;
}
```

[백준 15711 - 환상의 짝꿍](https://www.acmicpc.net/problem/15711)

<br/>

### 유클리드 호제법

- 두 수의 최대공약수와 최소공배수를 구하는 알고리즘

```cpp
int get_gcd(int a, int b){
    if(a<b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    while(b!=0){
        int n = a%b;
        a = b;
        b = n;
    }
    return a;
}

int main() {
    int n,m;
    cin >> n >> m;
    int gcd = get_gcd(n,m);
    int lcm = ( n * m ) / gcd;

    cout << gcd << "\n";
    cout << lcm;
}
```

[백준 2609 - 최대공약수와 최소공배수](https://www.acmicpc.net/problem/2609)

[백준 2485 - 가로수](https://www.acmicpc.net/problem/2485)

<br/>
