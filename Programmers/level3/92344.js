function solution(board, skills) {


    const arr = Array.from({ length: board.length + 1 }, () =>
        Array(board[0].length + 1).fill(0)
    );

    for(const skill in skills) {
        const [type, r1, c1, r2, c2, degree] = skill;
        
        const attck = type === 1 ? -1 : 1;

        arr[r1][c1] += degree * attck;
        
    }
    var answer = 0;
    return answer;
}

solution([[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5]], [[1,0,0,3,4,4],[1,2,0,2,3,2],[2,1,0,3,1,2],[1,0,1,3,3,1]])