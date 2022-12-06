n = int(input())

tree = list(map(int, input().split()))

target_input = int(input())

trees = [[] for _ in range(n)]

for i in range(n):
    if tree[i] != -1:
        trees[tree[i]].append(i)

def dfs(target):
    if len(trees[target]) == 0:
        trees[target].append(0)
        return False

    for i in range(len(trees[target])):
        if trees[target][i] != 0:
            to = trees[target][i]
            trees[target][i] = 0
            dfs(to)
        else:
            return False

dfs(target_input)

answer = 0
for tre in trees:
    if len(tre) == 0:
        answer += 1

print(trees)
print(answer)
