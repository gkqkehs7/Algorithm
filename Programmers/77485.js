



function solution(rows, columns, queries) {

    // 가장 작은 숫자 찾고 -> 회전 

    let num = 1;
    let maps = Array(rows).fill().map(() => []);

    for(let i=0; i<rows; i++) {
        for(let j=0; j<columns; j++) {
            maps[i].push(num);
            num++;
        }
    }

    function get_arr(x1, y1, x2, y2) {
        let arr = [];
    
        for(let i = y1; i <= y2; i++) {
            arr.push(maps[x1][i]);
        }
    
        for(let i = x1 + 1; i<x2; i++) {
            arr.push(maps[i][y2]);
        }
    
        for(let i = y2; i >= y1; i--) {
            arr.push(maps[x2][i]);
        }
    
        for(let i = x2 - 1; i > x1; i--) {
            arr.push(maps[i][y1]);
        }
    
        return arr;
    }
    
    function rotate_arr(x1, y1, x2, y2, origin_arr) {
        
        let count = 0;
        for(let i = y1; i <= y2; i++) {
            maps[x1][i] = origin_arr[count];
            count++;
        }
    
        for(let i = x1 + 1; i<x2; i++) {
            maps[i][y2] = origin_arr[count];
            count++;
        }
    
        for(let i = y2; i >= y1; i--) {
            maps[x2][i] = origin_arr[count];
            count++;
        }
    
        for(let i = x2 - 1; i > x1; i--) {
            maps[i][y1] = origin_arr[count];
            count++;
        }
    }

    let answer = [];

    for(let i=0; i<queries.length; i++) {
        let [x1, y1, x2, y2] =  queries[i];

        let origin_arr = get_arr(x1 - 1, y1 - 1, x2 - 1, y2 - 1);

        answer.push(Math.min(...origin_arr));

        origin_arr.unshift(origin_arr.pop())

        rotate_arr(x1 - 1, y1 - 1, x2 - 1, y2 - 1, origin_arr)


    }


    console.log(answer)

    return answer;
}

solution(3, 3, [[1,1,2,2],[1,2,2,3],[2,1,3,2],[2,2,3,3]]);