import sys
sys.setrecursionlimit(100000)

n = int(input())

maps = []
for _ in range(n):
    maps.append(list(input()))

blind = [[0]*n for _ in range(n)]

for i in range(n):
    for j in range(n):
        if maps[i][j] == 'G':
            blind[i][j] = 'R'
        else:
            blind[i][j] = maps[i][j]

target = 0
def dfs(x,y):
    global target
    if x < 0 or x >= n or y < 0 or y >= n:
        return False

    if maps[x][y] == target:
        maps[x][y] = 0
        dfs(x+1,y)
        dfs(x-1,y)
        dfs(x,y+1)  
        dfs(x,y-1)
    return False

answer = 0
for i in range(n):
    for j in range(n):
        target = maps[i][j]

        if target != 0:
            dfs(i,j)
            answer += 1


blind_target = 0
def blind_dfs(x,y):
    global blind_target
    if x < 0 or x >= n or y < 0 or y >= n:
        return False

    if blind[x][y] == blind_target:
        blind[x][y] = 0
        blind_dfs(x+1,y)
        blind_dfs(x-1,y)
        blind_dfs(x,y+1)  
        blind_dfs(x,y-1)
    return False


blind_answer = 0
for i in range(n):
    for j in range(n):
        blind_target = blind[i][j]

        if blind_target != 0:
            blind_dfs(i,j)
            blind_answer += 1

print(answer, blind_answer)