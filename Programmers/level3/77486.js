function solution(enroll, referral, seller, amount) {

    let tree = Array(enroll.length + 1).fill(0);
    let answer = Array(enroll.length + 1).fill(0);
    let people = {};

    for(let i=0; i<enroll.length; i++) {
        people[enroll[i]] = i + 1;
    }

    for(let i=0; i<referral.length; i++) {
        if(referral[i] === "-") {
            tree[i + 1] = -1;
        } else {
            const parent = people[referral[i]];

            tree[i + 1] = parent;
        }
    } 
    

    for(let i=0; i<seller.length; i++) {

        let me = people[seller[i]];

        let money = amount[i] * 100;

        answer[me] += money;

        while(true) {
            let to_parent = parseInt(money / 10);

            // 부모 몫
            let parent = tree[me];

            if(parent === -1) {
                answer[me] -= to_parent;
                break;
            } else {
                answer[parent] += to_parent;

                answer[me] -= to_parent;
                
                me = parent;
    
                money = parseInt(money / 10);
            }        
        }
    
    }

    answer.shift()
    return answer;
}

solution(["john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"], ["-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"], ["young", "john", "tod", "emily", "mary"], [12, 4, 2, 5, 10])
