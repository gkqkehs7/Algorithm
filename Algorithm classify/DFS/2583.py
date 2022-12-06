# 1. 좌표를 뒤집않고 진행해도 문제가 없다.
# 2. 직사각형을 어떻게 표시해줄 것인가?
import sys
sys.setrecursionlimit(100000)

m , n , k = input().split()
m = int(m)
n = int(n)
k = int(k)

maps = [[0] * n for _ in range(m)]
draws = []

for _ in range(k):
    draws.append(list(map(int, input().split())))

for draw in draws:
    for i in range(draw[1], draw[3]):
        for j in range(draw[0], draw[2]):
            maps[i][j] = 1


answer = 0
def dfs(x,y):
    global answer
    if x < 0 or x >= m or y < 0 or y >= n:
        return False

    if maps[x][y] == 0:
        answer += 1
        maps[x][y] = 1 

        dfs(x+1, y)
        dfs(x-1, y)
        dfs(x, y+1)
        dfs(x, y-1)
        return True
    return False

answers = []
for i in range(m):
    for j in range(n):
        if dfs(i,j) == True:
            answers.append(answer)
            answer = 0

print(len(answers))
answers.sort()
print(*answers)