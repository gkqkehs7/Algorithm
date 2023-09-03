function solution(arr) {

    let zero_count = 0;
    let one_count = 0;

    function check_same(start_x, end_x, start_y, end_y) {
    
        let first = arr[start_x][start_y];

        if(start_x === end_x) {
            if(first === 0) {
                zero_count += 1;
            } else {
                one_count += 1;
            }

            return;
        }
    
        let same = true;
    
        for(let i=start_x; i<=end_x; i++) {
            for(let j=start_y; j<=end_y; j++) {
                if(arr[i][j] !== first) {
                    same = false;
                    break;
                }
            }
        }

        if(same) {
            if(first === 0) {
                zero_count += 1;
            } else {
                one_count += 1;
            }
        }
    
        if(!same) {
            let mid_x = parseInt((start_x + end_x) / 2); 
            let mid_y = parseInt((start_y + end_y) / 2); 
        
            check_same(start_x, mid_x, start_y, mid_y)
            check_same(mid_x + 1, end_x, start_y, mid_y)
            check_same(start_x, mid_x, mid_y + 1, end_y)
            check_same(mid_x + 1, end_x, mid_y + 1, end_y)
        }   
    }

    check_same(0, arr.length - 1, 0, arr.length - 1);

    let answer = [zero_count, one_count];
    
    console.log(answer)

    return answer;
}

solution([[1,1,0,0],[1,0,0,0],[1,0,0,1],[1,1,1,1]])