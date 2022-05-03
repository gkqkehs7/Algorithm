import heapq

def solution(food_times, k):
    if sum(food_times) <= k:
        return -1
        
    h = []
    for i in range(len(food_times)):
        heapq.heappush(h, (food_times[i], i+1))
    
    length = len(food_times);
    left_time = k;
   
    sum_value = 0;
    prev = 0
    
    while sum_value + ((h[0][0] - prev) * length) <= k:
        now = heapq.heappop(h)[0] 
        sum_value = (now - prev) * length;
        length -= 1 
        prev = now
        
        
h=[]
heapq.heappush(h, (3, 2))
heapq.heappush(h, (2, 2))
print(h)
heapq.heappop(h)
print(h[0])
