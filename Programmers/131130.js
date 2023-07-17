function solution(cards) {

    cards.unshift(-1);
  
    let answer = 0;

    for(let i=1; i<cards.length; i++) {

        let visited = Array(101).fill(false);

        let first = 1;

        let now = cards[i];

        visited[now] = true;
        
        while(true) {

            let next = cards[now];

            if(visited[next] === true) {
                break;
            } else {
                first++;
                visited[next] = true;
                now = next;
            }

        }

        // 두번째 뽑기
        let new_cards = [];
        for(let j=1; j<cards.length; j++) {
            if(visited[j] === false) {
                new_cards.push(j);
            }
        }

        if(new_cards.length === 0) {
            continue;
        }

        new_cards.unshift(-1);

        for(let j=1; j<new_cards.length; j++) {

            let second = 1;
 
            let new_visited = Array(101).fill(false);

            let new_now = new_cards[j];

            new_visited[new_now] = true;


            while(true) {

                let next = cards[new_now];
    
                if(new_visited[next] === true) {
                    break;
                } else {
                    second++;
                    new_visited[next] = true;
                    new_now = next;
                }
    
            }
            
            answer = Math.max(answer, first * second);
       }

    }

    return answer;
}

solution([8,6,3,7,2,5,1,4])