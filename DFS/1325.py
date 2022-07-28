import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

n, m = input().split()
n = int(n)
m = int(m)

computer = [[] for _ in range(n)]

for _ in range(m):
    a, b = input().split()
    a = int(a) - 1
    b = int(b) - 1
    computer[b].append(a)
    

answer = 0
def dfs(target):
    global answer
    visited[target] = 1 
    
    for com in computer[target]:
        if visited[com] == 0:
            answer += 1
            dfs(com)
        else:
            return False
    
max = answer
answers = []
for i in range(m):
    visited = [0]*n 
    dfs(i)

    if answer >= max:
        max = answer
        answers.append(i+1)
    answer = 0
    
print(*answers)