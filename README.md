# Algorithm들 

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

### 에라토스테네스의 체

- 어떤 수가 소수인지 확인 하는 알고리즘
- 어떤 x가 소수인지 확인할 때는 1부터 x의 제곱근 까지만 나누어 보는 것으로 확인할 수 있다.

```cpp
#include <cmath>
int x = 10;
sqrt(x); //x의 제곱근
pow(x, 2); // x의 n제곱 
```

### 유클리드 호제법

- 두 수의 최대공약수와 최소공배수를 구하는 알고리즘
