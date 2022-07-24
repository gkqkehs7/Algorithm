def solution(N, stages):

    peoples = len(stages)
    fails = [0] * N 
    for stage in stages:
        if stage - 1 == N: continue
        fails[stage-1] += 1;
   
    results = []
    divide = peoples
    for i in range(len(fails)):
        
        if fails[i] == 0:
            results.append((0, i+1))
        else:
            result = fails[i] /divide
            results.append((result,i+1))
            divide -= fails[i]
            
    results.sort(key = lambda x: (-x[0], x[1]))
    
    answer = []
    for result in results:
        answer.append(result[1])

    return answer 

