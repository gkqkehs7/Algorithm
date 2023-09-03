function solution(number, k) {

    let rest_len = number.length - k;
    let stack = [];
    
    for(let i=0; i<number.length; i++) {
        let now = number[i];
    
        while(k > 0 && stack.length > 0) {
            let top = stack[stack.length - 1];
            if(top < now) {
                stack.pop();
                k--;
            } else {
                break;
            }
        } 

        stack.push(now);
    }


//   console.log(stack)

    if(stack.length !== rest_len) {
        console.log(stack.length, rest_len)
        for(let i=0; i <= stack.length - rest_len; i++) {
            stack.pop();
        }
    }

//    console.log(stack)

    let answer = stack.join("");
    
//    console.log(answer);

    return answer;
}

solution("4177252841", 9)