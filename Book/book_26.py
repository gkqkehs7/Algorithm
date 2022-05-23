import heapq as h

heap = []
n = int(input())

for i in range(n):
    h.heappush(heap, int(input()))


sum =0
if n == 1:
    print(0)
else:
    while len(heap) > 1:
        prev = h.heappop(heap)
        next = h.heappop(heap)
        sum += prev + next
        h.heappush(heap, prev + next)
        
    print(sum)

