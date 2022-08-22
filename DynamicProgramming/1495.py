# for 문을 다 도는 구조 dp 테이블을 어떻게 짤것인가?가 문제가 된다
import sys
input = sys.stdin.readline

n,s,m = map(int, input().split())

songs = list(map(int, input().split()))
dp = [[0] * (m+1) for _ in range(n+1)]
dp[0][s] = 1


for i in range(n):
    for j in range(m+1):
        if dp[i][j] == 1:
            num1 = j + songs[i]
            num2 = j - songs[i]    
    
        