import sys
input = sys.stdin.readline

n, m = map(int, input().split())

computer = [[] for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    computer[b-1].append(a-1)
    

result = [0 for i in range(n)]
stack = []
for i in range(n):
    visited = [0] * n;
    stack.append(i)
    visited[i] = True
    
    while stack:
        com = stack.pop()
        result[i] += 1
        
        for j in range(len(computer[com])):
            if visited[computer[com][j]] == 0:
                stack.append(computer[com][j])
                visited[computer[com][j]] = 1
    
answer = []
max_value = max(result)
for i in range(n):
    if result[i] == max_value:
        print(i + 1, end=" ")