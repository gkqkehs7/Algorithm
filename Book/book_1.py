# 정렬 후 반복문을 돌면서 순서대로 끊어줄 것이다.
# 정렬 nlogn + 반복문 n = o(NlogN)
# n의 개수 100,000 시간제한 1초이므로 nlon으로 풀수있다
import sys
input = sys.stdin.readline

n = int(input())

adventures = list(map(int, input().split()))

adventures.sort()

adventures.reverse()

count = adventures[0]
team = 0;
for adventure in adventures:
    if count == 0:
        count = adventure
 
    count -= 1;
    
    if count == 0:

        team += 1;
    
print(team)