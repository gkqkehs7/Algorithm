function solution(numbers) {

    let answer = new Array(numbers.length).fill(-1);

    let stack = [];
    
    for(let i=0; i<numbers.length; i++) {
        let now = numbers[i];

        while(stack.length > 0) {
            let [top, index] = stack[stack.length - 1];

            if(top < now) {
                let [num, num_idx] = stack.pop();
                answer[num_idx] = now;
            } else {
                break;
            }
        }

        stack.push([now, i]);
    }

    while(stack.length > 0) {
        let [num, num_idx] = stack.pop();
        answer[num_idx] = -1;
    }

    return answer;
}
