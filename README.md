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

 <br/>

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

<br/>

### 순열과 조합

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

vector와 algorithm의 next_permutation으로 구현한다.

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

위의 순열을 구하는 방식으로 k개의 1, n개의 0을 순열을 구해서

1인 것만을 출력하면, 조합이 된다. 

<br/>

<br/>

### 에라토스테네스의 체

- 어떤 수가 소수인지 확인 하는 알고리즘
- 어떤 x가 소수인지 확인할 때는 1부터 x의 제곱근 까지만 나누어 보는 것으로 확인할 수 있다.

```cpp
#include <cmath>
int x = 10;
sqrt(x); //x의 제곱근
pow(x, 2); // x의 n제곱 
```

<br/>

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

<br/>

<br/>
