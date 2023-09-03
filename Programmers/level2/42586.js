function solution(progresses, speeds) {

    let answer = [];
    
 

    while(progresses.length > 0) {

        console.log(progresses);

        for(let i=0; i<progresses.length; i++) {
            progresses[i] = progresses[i] + speeds[i]
        }

        let count = 0;
        for(let i=0; i<progresses.length; i++) {
            if(progresses[i] >= 100) {
                count++;
            } else {
                break;
            }
        }

        if(count > 0) {
            answer.push(count);    
        }

        while(count > 0) {
            progresses.shift();
            speeds.shift();
            count--;
        }

    }
        

    console.log(answer);

    return answer;
}

solution([93, 30, 55], [1, 30, 5])