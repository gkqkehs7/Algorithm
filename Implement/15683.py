#문제를 풀다보니 독립이 아니였다
import sys
input = sys.stdin.readline

n, m = input().split()
n = int(n)
m = int(m)

maps = []
for _ in range(n):
    maps.append(list(map(int, input().split())))

cctvs = []
for i in range(n):
    for j in range(m):
        if maps[i][j] != 0 and maps[i][j] != 6:
            cctvs.append((i,j,maps[i][j]))

def count(cctv, direction):
    dx = [-1,0,1,0]
    dy = [0,1,0,-1]
    count = 0
    x = cctv[0]
    y = cctv[1]

    while 0 <= x < n and 0 <= y < m and maps[x][y] != 6:
        count += 1    
        x = x + dx[direction]
        y = y + dy[direction] 

    return count

def draw(x,y,directions):
    dx = [-1,0,1,0]
    dy = [0,1,0,-1]
    for direction in directions:
        while 0 <= x < n and 0 <= y < m and maps[x][y] != 6:
            x = x + dx[direction]
            y = y + dy[direction]
            maps[x][y] = '#' 

for cctv in cctvs:
    if cctv[2] == 1:
        max_direct = []
        for i in range(4):
            max_direct.append((count(cctv, i), i))
        max_direct.sort(reverse=True)
        directions = [max_direct[0][0]]
        draw(cctv[0], cctv[1], directions)

    elif cctv[2] == 2:
        vertical = count(cctv,0) + count(cctv,2)
        horizontal = count(cctv,1) + count(cctv,3)

        if vertical > horizontal:
            directions = [0,2]
        else:
            directions = [1,3]

    elif cctv[2] == 3:
        case = []
        case.append(0,count(cctv,0) + count(cctv,1))
        case.append(1,count(cctv,1) + count(cctv,2))
        case.append(2,count(cctv,2) + count(cctv,3))
        case.append(3,count(cctv,3) + count(cctv,0))
        
    elif cctv[2] == 4:
        min_direct = []
        for i in range(4):
            min_direct.append((count(cctv, i), i))
        min_direct.sort()
        directions = [min_direct[1][1], min_direct[2][1], min_direct[3][1]]

    elif cctv[2] == 5:
        print()

print(maps)

