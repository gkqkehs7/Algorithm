# 제발 표를 그려서 규칙을 찾아내라
# 표를 그려서 푸는 문제
# 나머진 다 채워져있다ㅏ고 자정, 뒤에서 부터 빼는 문제
# https://huiyu.tistory.com/entry/DP-01-Knapsack%EB%B0%B0%EB%82%AD-%EB%AC%B8%EC%A0%9C
# 0 - 1 knapsack
# dp를 할때 유의 할 점은 dp table은 항상 그 에 대한 최댓 값이다 한번 설정하면 바꿀수 없다는 거다
import sys
input = sys.stdin.readline

n, k = map(int, input().split())

bag = []
for _ in range(n):
    bag.append(list(map(int, input().split())))

dp = [[0]*(k+1) for _ in range(n + 1)]


for i in range(1, n+1):
    w = bag[i-1][0]
    v = bag[i-1][1]
    
    for j in range(1,k+1):
        if w <= j:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v)
        else:
            dp[i][j] = dp[i-1][j]
            
            
print(dp[-1][-1])