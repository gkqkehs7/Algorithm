n,s = map(int, input().split())

arr = list(map(int, input().split()))


cnt = 0;
def dfs(idx, sum):
    global cnt;
    
    #끝까지 탐색한 경우
    if idx >= n:
        return;
    
    sum += arr[idx]
    
    if sum == s:
        cnt += 1;
    
    dfs(idx + 1, sum - arr[idx])
    dfs(idx + 1, sum)
    
dfs(0,0)
print(cnt)