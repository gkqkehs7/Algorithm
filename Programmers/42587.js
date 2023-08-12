function solution(priorities, location) {
    

    let queue = [];

    for(let i=0; i<priorities.length; i++) {
        queue.push([priorities[i], i]);
    }

    let out = 0;
    while(queue.length > 0) {

        let [value, idx] = queue[0];

        let isMax = true;
        for(let i=1; i<queue.length; i++) {
            if(value < queue[i][0]) {
                isMax = false;
                break;
            }
        }

        if(isMax) {
            out++;
            if(idx === location) {
                return out;
            }
            console.log(value)
            queue.shift();
        } else {
            queue.shift();
            queue.push([value, idx])
        }
    }

}

solution([2, 1, 3, 2])