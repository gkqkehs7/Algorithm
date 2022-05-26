T = int(input())

answers = []
for i in range(T):

    pin = list(map(int, input().split()))
    n = pin[0] # 3
    m = pin[1] # 4

    d = []
    cave = list(map(int, input().split()))


    idx = 0
    for i in range(n):
        d.append(cave[idx:idx+m])
        idx += m
        
    for i in range(1, m):
        for j in range(n):
            if j == 0:
                d[j][i] = d[j][i] + max(d[j][i-1], d[j+1][i-1])
            elif j == n-1:
                d[j][i] = d[j][i] + max(d[j][i-1], d[j-1][i-1])
            
            else:
                d[j][i] = d[j][i] + max(d[j][i-1], d[j+1][i-1], d[j-1][i-1])
                

    maxx = 0
    for i in range(n):
        maxx = max(maxx, d[n-i-1][m-1])
    answers.append(maxx)
    
for answer in answers:
    print(answer)