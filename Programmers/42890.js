const getCombinations = function (arr, selectNumber) {
    const results = [];
    if (selectNumber === 1) return arr.map((value) => [value]); 
  
    arr.forEach((fixed, index, origin) => {
      const rest = origin.slice(index + 1); 
      const combinations = getCombinations(rest, selectNumber - 1); 
      const attached = combinations.map((combination) => [fixed, ...combination]); 
      results.push(...attached); 
    });
  
    return results; 
  };

function solution(relations) {

    let total_size = relations.length;
    let col_size = relations[0].length;
    let row_size = relations.length;
    let arr = [];

    for(let i=0; i<col_size; i++) {
        arr.push(i);
    }

    let results = [];
    for(let i=0; i<col_size; i++) {

        let combs = getCombinations(arr, i + 1);

        for(let j=0; j<combs.length; j++) {
            let set = new Set();
           
            for(let k=0; k<row_size; k++) {
            
                let temp = "";
                for(let p=0; p<combs[j].length; p++) {
                    let pick_colmn = combs[j][p];
                    temp += relations[k][pick_colmn]
                }

                set.add(temp)
            }

            if(set.size === total_size) {
                results.push(combs[j])
            }
        }        
    }

    console.log(results)
    let answer = 0;

    console.log(answer)
    return answer;
}

solution([["100","ryan","music","2"],["300","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]])