# 계속 데이터를 빼내는 pop을 사용할경우 list에서 pop 하는 것보다 deque로 만든다음 popleft를 하는게 편하다

# 아니 pop을 많이 사용해서 queue를 사용하고, 정렬을 하려했더니 그럼 우선순위 큐를 써야겟네!

# q에서 빼가지고 끝날때까지 반복문 돌고 돌고 개수 세면 되겟다!
import sys
import heapq 
input = sys.stdin.readline

n = int(input())


# heapq 두번째 값 기준으로 정렬을 어떻게 하는거지?
heap = []
for _ in range(n):
    start, end = map(int, input().split())
    heapq.heappush(heap, (end,start))

# 빼내는 index와 맞지가 않다 heapq는 left가 아니면 시간이 많이 드는데 따로 표시를 해야할까?
# 삭제하려는 원소를 맨 앞으로 가져와서 pop을 한다
    
cnt = 1
# 끝, 시작
while heap:
    tmp = heapq.heappop(heap)
    cnt += 1
    if not heap:
        break
    while heap and heap[0][1] < tmp[0]:
        heapq.heappop(heap)
print(cnt)