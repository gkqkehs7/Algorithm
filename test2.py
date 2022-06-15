import heapq as h

def solution(food_times, k):
    
    if (sum(food_times) <= k):
        return -1 
    items = []
    for i in range(len(food_times)):
        h.heappush(items,(food_times[i], i+1))

    remain = 0;
    items_len = len(items)
    last = 0;
    while True:
        min = items[0][0] - last
    
        if(min * items_len <= k):
            h.heappop(items)
            k = k - min * items_len
            last = last + min
            items_len -= 1;
        else: 
            remain = k % items_len
            break;
        
    result = sorted(items, key = lambda x: x[1])
    return result[remain][1]
    
a = solution([4,2,9,6,7], 17)
print(a)