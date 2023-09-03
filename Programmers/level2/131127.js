function solution(want, number, discount) {
    
    let obj = {};

    for(let i=0; i<want.length; i++) {
        if(!obj.hasOwnProperty(want[i])) {
            obj[want[i]] = number[i];
        }
    }

    let start = 0;

    let answer = 0;
   
    while(start + 10 < discount.length + 1) {
        let new_obj = JSON.parse(JSON.stringify(obj));

        for(let i=start; i<start + 10; i++) {

            new_obj[discount[i]] -= 1;
        }

        let can_buy = true;
        for (const key in new_obj) {
            const value = new_obj[key];
            if(value !== 0) {
                can_buy = false;
                break;
            }
        }

        if(can_buy) answer += 1;

        start++;
    }


    console.log(answer)
    return answer;
}

solution(["banana", "apple", "rice", "pork", "pot"], [3, 2, 2, 2, 1], ["chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"])