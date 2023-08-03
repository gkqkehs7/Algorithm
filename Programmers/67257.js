function calculation(cal_str, order) {
    
    let cal = cal_str.split(/([-+*])/); // 배열로 변경
    
    let stack = [];

    for(let i=0; i<cal.length; i++) {
        let temp = cal[i];

        if((temp === order[0]) || (temp === order[1]) || (temp === order[2])) {
            stack.push(temp);
        } else {  // 숫자인 경우
            if(i === 0) {
                stack.push(parseInt(temp));
            } else {
                if(cal[i-1] === order[0]) {
                    let calculator = stack.pop();

                    let prev = stack.pop();

                    if(calculator === "+") {
                        stack.push(prev + parseInt(temp));
                    } else if(calculator === "-") {
                        stack.push(prev - parseInt(temp));
                    } else {
                        stack.push(prev * parseInt(temp));
                    }
                } else {
                    stack.push(parseInt(temp));
                }   
            }
        }
    } 

    let stack2 = [];
    for(let i=0; i<stack.length; i++) {
        let temp = stack[i];

        if((temp === order[0]) || (temp === order[1]) || (temp === order[2])) {
            stack2.push(temp);
        } else {  // 숫자인 경우
            if(i === 0) {
                stack2.push(parseInt(temp));
            } else {
                if(stack[i-1] === order[1]) {
                    let calculator = stack2.pop();

                    let prev = stack2.pop();

                    if(calculator === "+") {
                        stack2.push(prev + parseInt(temp));
                    } else if(calculator === "-") {
                        stack2.push(prev - parseInt(temp));
                    } else if(calculator === "*") {
                        stack2.push(prev * parseInt(temp));
                    }
                } else {
                    stack2.push(temp);
                }   
            }
        }
    }
    

    let calculator = order[2]

    const numbers = stack2.filter(item => item !== calculator);

    let result = numbers[0];

    if(calculator === "+") {
        for(let i=1; i<numbers.length; i++) {
            result += numbers[i];
        }
    } else if(calculator === "-") {
        for(let i=1; i<numbers.length; i++) {
            result -= numbers[i];
        }
      
    } else if(calculator === "*") {
        result = 1;
        for(let i=0; i<numbers.length; i++) {
            result *= numbers[i];
        }
      
    }

    return Math.abs(result);
}



function solution(expression) {
    let orders = [['*', '+', '-'], ['*', '-', '+'], ['+', '*', '-'], ['+', '-', '*'], ['-', '*', '+'], ['-', '+', '*']]

    let answer = 0;

    for(let i=0; i<orders.length; i++) {
        let result = calculation(expression, orders[i])

        answer = Math.max(answer, result)
    }

    console.log(answer)

    return answer;
}

solution("100-200*300-500+20")