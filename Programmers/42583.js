function solution(bridge_length, weight, truck_weights) {

    let now_idx = 1; // 지금 올라타야 하는 트럭 index

    let now_wei = 0; // 지금 올라가 있는 트럭 무게

    let now_count = 0; // 지금 올라가 있는 트럭 개수

    let queue = [];
    queue.push([truck_weights[0], 0])
    now_wei = truck_weights[0]
    now_count = 1;

    let time = 0;

    while(queue.length > 0) {

        for(let i=0; i<queue.length; i++) {
            queue[i][1] = queue[i][1] + 1;
        }
    
        // 다 도착한놈 내리기
        if(queue[0][1] === bridge_length) {
            now_wei -= queue[0][0];
            now_count -= 1;
            queue.shift();
        }

        // 새로 탈수 있으면 태우기
        if((now_count < bridge_length) && (truck_weights[now_idx] + now_wei <= weight)) {
            now_wei += truck_weights[now_idx];
            now_count += 1;
            queue.push([truck_weights[now_idx], 0])
            now_idx += 1;
        }

        time++;

        // console.log(time, "초\n", queue)

        // console.log("==================")
    }
    
    return time + 1;
}

solution(2, 10,[7,4,5,6])