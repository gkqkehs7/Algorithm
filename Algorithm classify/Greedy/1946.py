import sys

input = sys.stdin.readline
t = int(input())

results = []

for i in range(t):
    n = int(input())
    
    scores = []
    for i in range(n):
        a,b = map(int,input().split())
        scores.append((a,b))
        
    scores.sort()
    
    prev = scores[0][1]
    result = 1
    for i in range(1,n):
        if scores[i][1] < prev:
            prev = scores[i][1]
            result += 1
    
    results.append(result)
    
for i in range(len(results)):
    print(results[i])