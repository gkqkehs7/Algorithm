function solution(stones, k) {

    function work_stone(people) {
    
        let copy_stones = [...stones]
        let count = 0;

        for(let i=0; i<stones.length; i++) {
            if(copy_stones[i] - people <= 0) {
                count++;
            } else {
                count = 0;
            }

            if(count >= k) {
                return false;
            }
        }

        return true;
    }

    let answer = 0;

    let start = 0;
    let end = 2000000000;

    while(start <= end) {
        let mid = parseInt((start+end) / 2);

        if(work_stone(mid)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return start;
}

solution([2, 4, 5, 3, 2, 1, 4, 2, 5, 1], 3)