function solution(plans) {

    let hash = {};

    for(let i = 0; i<plans.length; i++) {
        let [now_subject, now_start, now_duration] = plans[i];
        
        let [now_hour, now_minute] = now_start.split(":");

        let newTime = parseInt(now_hour) * 60 + parseInt(now_minute);

        plans[i] = [now_subject, newTime, parseInt(now_duration)];

        hash[newTime] = [now_subject, newTime, parseInt(now_duration)];
    }
    
    // 한번 정렬
    plans.sort((plan1, plan2) => {return plan1[1] - plan2[1]})

    // stack 생성
    let time = plans[0][1];
    let stack = [];
    let answer = [];
    let finish = 0;

    while(finish < plans.length) {
        if(stack.length > 0) {

            // stack top
            let [subject, start_time, duration] = stack[stack.length - 1];

            duration = duration - 1;

            if(duration === 0) {
                answer.push(subject)
                stack.pop()
                finish++
            } else {
                stack[stack.length - 1][2] = duration;
            }
        }

        if(hash[time.toString()]) {
            stack.push(hash[time.toString()]);
        }

        time++;

    }
    
    return answer;
}
