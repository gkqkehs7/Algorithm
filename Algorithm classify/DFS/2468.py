import sys
import copy
sys.setrecursionlimit(100000)

n = int(input())

maps = []
max_height = 0
for _ in range(n):
    temp = list(map(int, input().split()))
    if max(temp) > max_height:
        max_height = max(temp)
    maps.append(temp)
copied = copy.deepcopy(maps)

def dfs(x,y,sink):
    if x < 0 or x >= n or y < 0 or y >= n:
        return False;
    
    if maps[x][y] > sink:
        maps[x][y] = -1
        dfs(x+1, y, sink)
        dfs(x-1, y, sink)
        dfs(x, y-1, sink)
        dfs(x, y+1, sink)
        return True
    return False

answers = []
for k in range(max_height+1):
    answer = 0
    for i in range(n):
        for j in range(n):
            if dfs(i,j,k) == True:
                answer += 1
    answers.append(answer)
    maps = copy.deepcopy(copied)

print(max(answers))