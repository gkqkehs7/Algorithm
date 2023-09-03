function solution(arr1, arr2) {

    let answer = new Array(arr1.length).fill().map(() => {
        return [];
    })


    for(let i=0; i<arr1.length; i++) { // arr1의 i행, arr2의 i열
        
        for(let j=0; j<arr2[0].length; j++) {
            
            let mul = 0;
            for(let k=0; k<arr1[i].length; k++) {
                mul += arr1[i][k] * arr2[k][j]; 
            }
        
       
            answer[i].push(mul)
        }
    }

    console.log(answer)
    return answer;
}

solution([[1, 2, 3], [4, 5, 6]], [[1, 4], [2, 5], [3, 6]])