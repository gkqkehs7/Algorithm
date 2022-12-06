n = int(input())

maps = []
for _ in range(n):
    maps.append(list(map(int, input())))
answer = 0
def dfs(x,y):
    global answer
    if x < 0 or x >= n or y < 0 or y >= n:
        return False
    
    if maps[x][y] == 1:
        maps[x][y] = 0
        answer += 1
        dfs(x+1, y)
        dfs(x-1, y)
        dfs(x, y+1)
        dfs(x, y-1)

    return False

answers = []
for i in range(n):
    for j in range(n):
        dfs(i,j)
        if answer != 0:
            answers.append(answer)
            answer = 0

answers.sort()
print(len(answers))
for i in range(len(answers)):
    print(answers[i])