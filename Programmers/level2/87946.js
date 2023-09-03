function solution(k, dungeons) {

    const getPermutations = function (arr, selectNumber) {
      const results = [];
      if (selectNumber === 1) return arr.map((value) => [value]); // 1개씩 택할 때, 바로 모든 배열의 원소 return
    
      arr.forEach((fixed, index, origin) => {
        const rest = [...origin.slice(0, index), ...origin.slice(index + 1)]; // 해당하는 fixed를 제외한 나머지 배열
        const permutations = getPermutations(rest, selectNumber - 1); // 나머지에 대해 순열을 구한다.
        const attached = permutations.map((permutation) => [fixed, ...permutation]); // 돌아온 순열에 대해 떼 놓은(fixed) 값 붙이기
        results.push(...attached); 
      });
    
      return results; 
    };

    let results = getPermutations(dungeons, dungeons.length)

      let answer = 0;
    for(let i=0; i<results.length; i++) {
      let temp = 0;
      let fatigue = k;

      for(let j=0; j<results[i].length; j++) {
        
        let [min_fatigue, use_fatigue] = results[i][j];

        if(fatigue < min_fatigue) {
          break;
        } else {
          fatigue = fatigue - use_fatigue;
          temp++;
        }
      }

      console.log(temp)

      answer = Math.max(answer, temp)
    }

    console.log(answer)

    return answer;
}

solution(80, [[80,20],[50,40],[30,10]])