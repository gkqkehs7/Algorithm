n = int(input())

schedule = []
for i in range(n):
    schedule.append(list(map(int, input().split())))
    
d = [0] * (n+1);

for i in range(n-1, -1 ,-1):
    time = schedule[i][0] + i
    
    if time <= n:
        d[i] = max( schedule[i][1] + d[time], d[i+1])
    else:
        d[i] = d[i+1]
        
print(d[0])
    