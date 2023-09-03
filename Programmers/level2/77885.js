function change_to_binary(number) {
    let result = [];

    while(number >= 2) {
        result.unshift(number % 2);
        number = parseInt(number / 2)
    }

    result.unshift(parseInt(number))

    return result;
}

function change_to_demical(bin) {
    let result = 0;

    let count = 0;
    for(let i=bin.length - 1; i >= 0; i--) {
        result += bin[i] * Math.pow(2, count);
        count++;
    }

    return result;
}

function solution(numbers) {

    let answer = [];

    for(let i=0; i<numbers.length; i++) {

        let num = numbers[i];
        let bin = change_to_binary(numbers[i])

        // 짝수인 경우
        if(numbers[i] % 2 === 0) {
            answer.push(num + 1);

        // 홀수 인경우
        } else {
            let find = false;
            for(let j = bin.length - 1; j >=0; j--) {
                if(bin[j] === 0) {
                    bin[j+1] = 0;
                    bin[j] = 1;
                    find = true;
                    break;
                }
            }

            if(!find) {
                bin[0] = 0;
                bin.unshift(1);    
            }

            answer.push(change_to_demical(bin))
            
        }

    }


    return answer;
}

solution([2, 7])