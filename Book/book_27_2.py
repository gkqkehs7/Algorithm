from bisect import bisect_left, bisect_right

pin = list(map(int, input().split()))

arr = list(map(int, input().split()))

answer = bisect_left(arr,pin[1])- bisect_right(arr,pin[0])

if answer == 0: print(-1)
else: print(answer)
