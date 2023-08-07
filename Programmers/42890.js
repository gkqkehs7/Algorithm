function solution(relations) {

    let total_size = relations.length;
    let col_size = relations[0].length;
    let row_size = relations.length;

    for(let i=0; i<row_size; i++) {
            
        let set = new Set();
        for(let j=0; j<col_size; j++) {
            set.add(relations[j][i]);        
        }
          
        console.log(set)
        console.log(set.size)
    }


    var answer = 0;
    return answer;
}

solution([["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]])