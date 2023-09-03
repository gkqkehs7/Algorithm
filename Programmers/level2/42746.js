function solution(numbers) {


    for(let i=0; i<numbers.length; i++) {
        numbers[i] = numbers[i].toString()
    }

    numbers.sort((prev, next) => {
        let first = prev + next;
 
        let second = next + prev;
 
        return second - first; // 내림 차순
    });

    let answer = '';

    for(let i=0; i<numbers.length; i++) {

        if(i === 0) {
            if(numbers[0] === "0") {
                answer = "0"
                break;
            }
        }
        answer += numbers[i].toString()
    } 

    return answer;
}

solution([0,0,0,0])