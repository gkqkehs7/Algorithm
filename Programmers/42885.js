function solution(people, limit) {

    people.sort((prev, next) => {
        return prev - next;
    })

    console.log(people);
    let start = 0;
    let end = people.length - 1;

    let answer = 0;
    while(start <= end) {
        let wei = people[start] + people[end]
        if(wei > limit) {
            answer++;
            end -= 1;
        } else if(wei <= limit) {
            answer++;
            start += 1;
            end -= 1;
        }
    }
    
    console.log(answer);

    return answer;
}

solution([70, 50, 80, 50], 100)