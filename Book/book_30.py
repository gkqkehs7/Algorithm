# from bisect import bisect_left, bisect_right

# def solution(words, queries):
    
#     words.sort()
    
    
#     answer = []
#     return answer


# a = "fro???"
# b = ["frozen", "froooo", "froadf", "frdd"]


# def count_by_range(n, left, right):
#     r = bisect_right(n, right)
#     l = bisect_left(n,left)
#     return r, l

# b.sort()
# print(count_by_range(b, "f?????", "fr????"))

from bisect import bisect_left, bisect_right


arr = [1,2,3,3,3,4,4,5,5,6]

def count_by_range(nums, left, right):
    l = bisect_left(nums, left) 
    r = bisect_right(nums, right)
    
    print(l,r)
 
count_by_range(arr,2,5) # 