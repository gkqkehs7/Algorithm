# combination을 사용할 줄 아는가? -> 코딩 테스트는 푸는 방법 외워서 푸는구나

from itertools import combinations

res = []
while True:
    arr = list(map(int, input().split()))
    if arr[0] == 0:
        break;
    len = arr.pop(0)

    res.append(list(combinations(arr, 6)))
    
for re in res:
    for r in re:
        arr = list(map(str, r))
        st = ' '.join(arr)
        print(st)
    print("")