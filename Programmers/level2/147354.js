function solution(data, col, row_begin, row_end) {

    col = col - 1;
    row_begin = row_begin - 1;    
    row_end = row_end - 1;    

    data.sort((prev, next) => {
        if(prev[col] === next[col]) {
            return next[0] - prev[0];
        } 

        return prev[col] - next[col];
    })


    let answer = 0;
    for(let i = row_begin; i <= row_end; i++) {

        let temp = 0;
        for(let j = 0; j < data[i].length; j++) {
            temp += data[i][j] % (i + 1);
        }
        
        answer = answer ^ temp;
    }
   

    console.log(answer);
    return answer;
}

solution([[2,2,6],[1,5,10],[4,2,9],[3,8,3]], 2, 2 ,3 ,4);