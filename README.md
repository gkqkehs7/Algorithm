# 구현

- 소수관련 문제 1 - 소수 판별법

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

어떤 수가 소수인지 확인 하는 알고리즘

어떤 x가 소수인지 확인할 때는 2부터 x의 제곱근 까지만 나누어 보는 것으로 확인할 수 있다.

[백준 1929 - 소수 구하기](https://www.acmicpc.net/problem/1929)

<br/>

- 소수관련 문제2 - 에라토스테네스의 체

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

n이 주어졌을 때, 1 부터 n 까지의 모든 소수를 구하는 방법

2 부터 n의 제곱근까지 검사하여 소수들의 배수를 지워 나간다.

[백준 1644 - 소수의 연속합](https://www.acmicpc.net/problem/1644)

<br/>

- 소수관련 문제 3 - 소수 판별법+에라토스테네스의 체로 소수 판별하기

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

이 방법은 배열의 최대 크기보다 훨씬 큰 수를 소수 판별할때 사용한다.

먼저 에라토스테네스의 체를 이용하여 check배열을 초기화한다.

최대한 소수를 벡터에 담고, 구하려는 수를 소수들로 나누어주며 나누어진다면 소수가 아니다. 소수가 아닌 수들은 소수를 약수로 갖기 때문이다.

[백준 15711 - 환상의 짝꿍](https://www.acmicpc.net/problem/15711)

<br/>

- 유클리드 호제법

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

=두 수의 최대공약수와 최소공배수를 구하는 알고리즘 

[백준 2609 - 최대공약수와 최소공배수](https://www.acmicpc.net/problem/2609)

[백준 2485 - 가로수](https://www.acmicpc.net/problem/2485)

<br/>

# DFS

- 기본 dfs코드

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
```

<br/>

- cycle찾기

```cpp
void findCycle(int now) {
    int next = graph[now];

    if(visited[next] == false) {
        visited[next] = true;
        findCycle(next);
    } else if(done[next] == false) {
        for(int i = next; i != now; i = graph[i]) {
            cnt++;
        }
        cnt++;
    }

    done[now] = true;
}
```

cycle을 찾을떄는 dfs를 사용한다. visited로 방문여부를 체크하면서 넘어가는건 dfs와 같지만,

더이상 이 노드를 방문하지 않을 것이란 걸 done배열로 관리한다.

방문을 했지만, done이 false인 경우는 cycle이 생성되었다는 것과 같다.

5 → 6 → 7 → 5 에서 7이 다시 5를 방문했을 때는 visited는 true지만 done은 false이므로 cycle이다.

4 → 5 → 6 → 3 에서 3에서 끝나기 때문에 모두 done과 visited가 true가 되면서 dfs를 빠져나오고, 4, 5, 6, 3은 다시 확인하기 않아도 된다.

이렇게 하면 노드별로 한번씩만 방문하는 O(N)시간안에 해결할 수 있다.

[백준 9466 - 텀 프로젝트](https://www.acmicpc.net/problem/9466)

<br />

# BFS

- bfs기본 코드

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

- 최단경로 문제

```cpp
while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;

    q.pop();

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && ny >= 0 && nx < n && ny < m && miro[nx][ny] == 1) {
            if(visited[nx][ny] == false) {
                visited[nx][ny] = true;
                distance[nx][ny] = distance[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }
}
```

보통 최단경로에는 dfs보단 bfs를 사용한다.

이전 경로까지의 거리를 +1 해나가며, 다음 경로까지의 거리를 계산해나간다.

[백준 14503 - 로봇 청소기](https://www.acmicpc.net/problem/14503)

<br/>

- 노드와 간선이 주어지지 않는다면?  [백준 9205 - 맥주 마시면서 걸어가기](https://www.acmicpc.net/problem/9205)

# 백트래킹

- backTracking 기본 코드

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

dsf와 똑같이 규칙이 존재하지 않아 모든 경우를 따져야할때 backtracking을 사용한다. 

backtracking과 dfs가 다른점은 dfs는 한번 간곳은 visited를 true로 두어서 다신 방문하지 않지만, 백트래킹의 경우 조건에 맞지 않다면 다시 false로 바꾸어 주어서 재 방문 한다는 점이다.

[백준 2661 - 좋은수열](https://www.acmicpc.net/problem/2661)

<br />

- 순열

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

backtracking을 사용해야하지만, vector와 algorithm의 next_permutation으로 구현할 수 있다.

<br/>

- 조합(nCk)

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

위의 순열을 구하는 방식으로 k개의 1, n개의 0을 순열을 구해서 1인 것만을 출력하면, 조합이 된다. 

[백준 14889 - 스타트와 링크](https://www.acmicpc.net/problem/14889)

<br/>

# **Dynamic Programming**

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

- 점화식

  점화식은 bottom-up문제가 기초가 되어 푸는 방식이다. 계속 최선의 선택을 해나가며 최종적으로    가장 큰값이나 가장 작은 값을 찾는 것이 대부분의 문제 유형이다.  

 문제를 푸는 방법은 **현재선택이 과거에 영향이 안 미치는 곳까지만 점화식을 사용**하는 것이다.

```cpp
for(int i=3; i<n; i++) {
    dp[i] = max(dp[i-3] + stair[i-1] + stair[i], dp[i-2] + stair[i]);
}
```

이 문제는 계단을 오르는데 세 계단을 연속으로 오를 수는 없고 하나를 오르던지 두 개를 연속해서 오르는 것을 선택하여 최종적으로 가장 큰 값을 구하는 문제이다.

현재를 n이라 하면 n-1의 계단을 거쳐 올랐을 때, n-2는 오를 수 없고, n-3을 올라야 하므로, 현재에서 최댓값은 3번째 전 계단(dp[n-3])에서 1번째 전 계단의 값, 그리고 현재 계단의 값까지 더해준 dp[n] = dp[n-3] + stair[n-1]이 된다.

또한 1번째 전 계단을 거쳐오지 않고, 두번째 전 계단에서 온경우, 두번째 까지의 최댓값(dp[n-2]) 에서 현재 계단의 값을 더해주면 된다. 그리고 위의 값과 아래의 값을 비교해서 큰 것을 넣어준 것이다.

여기서 그럼 dp[n-2]를 오르면 dp[n-3] dp[n-4]는 오른지 안오른지 어떻게 판단하나요? 라는 질문이 있을 수 있는데, dp[n-2]는 그 전의 반복문에서 이미 다루었을 것이기 떄문에 현재의 선택이 영향을 미치는 dp[n-2]에서 값을 더해준 것이다.

[백준 2579 - 계단 오르기](https://www.acmicpc.net/problem/2579)

<br/>

# 투 포인터

[백준 1644 - 소수의 연속합](https://www.acmicpc.net/problem/1644)

<br/>

### 

### 

### 오버플로우

가끔 **답을 n으로 나눈 값을 구하라**는 문제가 있다.

보통이면 그냥 n으로 나누면 되지만, 계속해서 값을 저장해야하는 dp문제의 경우 오버 플로우가 발생할 수 있다.

```cpp
for(int i=3; i <= n; i++ ) {
    dp[i] = (dp[i-1] + dp[i-2]);
}
```

전수와 전전수를 더하여 dp배열에 저장하는 문제였다. 

답을 10007로 나누어 답을 내는 문제였는데, 최대범위가 1000이라 dp[1000]을 계산해도 값이 잘 나오길래 10007을 나눈 값을 그대로 제출했더니 틀렸다. 오버플로우가 발생한 것이다.

아니 그럼 dp[1000]은 나온 것인가? 사실 나온 값보다 훨씬 큰 값인데 잘려나온 것이였다.

이런 경우 dp배열의 값을 전부 출력해보시면 바로 알수 있다.  

dp[71]이 약 15억, dp[70]이 약 7억이여서 72부터 71의 결과 + 70의 결과를 더해야 해서 23억이 나오고 int 범위인 2^31 - 1를 초과하게 되어 오버플로우가 나 음수로 나오는것을 확인할수 있다. 

이런식으로 계속 오버플로우가 나서 1000을 입력했을 때에는 그냥 우연히 양수가 나와 오버플로우가 안 일어난것처럼 보인것 뿐 단순히 우연일 뿐이였다.

dp문제이고 값을 n으로 나누라는 문제는 오버플로우를 항상 염두해두고 문제를 풀자

[백준 11726 - 2xn 타일링](https://www.acmicpc.net/problem/11726)

<br />
