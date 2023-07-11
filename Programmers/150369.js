function solution(cap, n, deliveries, pickups) {

    let answer = 0;

    let deliver_sum = 0;
    for(let i=0; i<deliveries.length; i++) {
        deliver_sum = deliver_sum + deliveries[i];
    }

    while(deliveries[deliveries.length-1] === 0) {
        deliveries.pop()
    }

    while(pickups[pickups.length-1] === 0) {
        pickups.pop()
    }

    while((deliveries.length > 0) || (pickups.length > 0)) {

        let boxes = 0;

        if(deliver_sum >= cap) {
         boxes = cap;
        } else {
         boxes = deliver_sum;
        }
     
        let last_deliver = deliveries.length;
        let last_pickup = pickups.length;

        while(boxes > 0 || deliveries[deliveries.length-1] === 0) {
            let to_deliver = deliveries[deliveries.length-1];
        
            if(to_deliver <= boxes) {
                boxes -= to_deliver
                deliver_sum -= to_deliver;
                deliveries.pop();
            } else {
                deliveries[deliveries.length-1] -= boxes;
                deliver_sum -= boxes;
                boxes = 0;
            }
        }
     
        // 수거
        let empty_boxes = cap;
        while(empty_boxes > 0 || pickups[pickups.length-1] === 0) {
            let to_pickup = pickups[pickups.length-1];
        
            if(to_pickup <= empty_boxes) {
                empty_boxes -= to_pickup
                pickups.pop();
            } else {
                pickups[pickups.length-1] -= empty_boxes;
                empty_boxes = 0;
         
            }
        }

     
        answer += Math.max(last_deliver, last_pickup) * 2;
   
    }
   
    console.log(answer)
    return answer;
}

solution(4, 5, [1, 0, 3, 1, 2, 0], [0, 3, 0, 4, 0]	)