function solution(numbers, target) {

    let answer = 0;

    function dfs(now, depth) {

        if(depth === numbers.length) {
            if(now === target) {
                answer++;
            }
            return;
        }

        
        let next = numbers[depth];

        dfs(now + next, depth + 1)
        dfs(now - next, depth + 1)
    }

    dfs(0, 0);

    
    return answer;
}

solution([4, 1, 2, 1], 4);