from bisect import bisect_left, bisect_right

def solution(words, queries):
    
    words.sort()
    
    
    answer = []
    return answer


a = "fro???"
b = ["frozen", "froooo", "froadf", "frdd"]


def count_by_range(n, left, right):
    r = bisect_right(n, right)
    l = bisect_left(n,left)
    return r, l

b.sort()
print(count_by_range(b, "f?????", "fr????"))
    