function solution(prices) {

    let answer = Array(prices.length).fill(0);

    let stack = [];
    stack.push(0);

    let idx = 1;
    
    while(idx < prices.length) {
        
        if(prices[stack[stack.length - 1]] < prices[idx]) { // 값이 감소하지 않은 경우
            stack.push(idx)
        } else {  // 값이 감소한 경우
            while(prices[idx] < prices[stack[stack.length - 1]]) {
                let top = stack.pop();
                
                answer[top] = idx - top;
            }

            stack.push(idx)
        }

        idx++;
    }

    for(let i=0; i<stack.length; i++) {
        answer[stack[i]] = prices.length - stack[i] - 1;
    }

    console.log(answer)

    return answer;
}

solution([1,2,3,2,3])