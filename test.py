def solution(food_times, k):
    
    ing = True;
    answer = 0;
    
    # if sum(food_times) < k:
    #     return -1;
    
    while ing:    
        no_food = True;
        for i in range(len(food_times)):
            if food_times[i] != 0:
                no_food = False
                if k == 0:
                    answer = i + 1;
                    ing = False
                    break;
                food_times[i] -= 1;
                k -= 1;
        if no_food == True:
            return -1
    return answer
    
print(solution([7,3,2], 9))