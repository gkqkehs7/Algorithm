function solution(numbers) {

    let isPrime = Array(10000000).fill(0);
    isPrime[0] = 1;
    isPrime[1] = 1;
    isPrime[2] = 0;

    for(let i=2; i<= Math.sqrt(10000000); i++) {
        if(isPrime[i] === 0) {
            for(let j= i + i; j <=10000000; j += i) {
                isPrime[j] = 1;
            }
        }
    }

    const getPermutations = function (arr, selectNumber) {
        const results = [];
        if (selectNumber === 1) return arr.map((value) => [value]); // 1개씩 택할 때, 바로 모든 배열의 원소 return
        
        arr.forEach((fixed, index, origin) => {
            const rest = [...origin.slice(0, index), ...origin.slice(index + 1)]; // 해당하는 fixed를 제외한 나머지 배열
        
            const permutations = getPermutations(rest, selectNumber - 1); // 나머지에 대해 순열을 구한다.
            const attached = permutations.map((permutation) => [fixed, ...permutation]); // 돌아온 순열에 대해 떼 놓은(fixed) 값 붙이기
            results.push(...attached); // 배열 spread syntax 로 모두다 push
        });
        
        return results; // 결과 담긴 results return
    };

    let arr = []
    for(let i=0; i<numbers.length; i++) {
        arr.push(i);
    }

    let results = [];
    for(let i=0; i<numbers.length; i++) {
        results.push(getPermutations(arr, i + 1));

    }

    let answer = 0;

    let temp = [];
    for(let i=0; i<results.length; i++) {
        for(let j=0; j<results[i].length; j++) {
            let number = "";

            for(let k=0; k<results[i][j].length; k++) {
                number += numbers[results[i][j][k]];
            }

            temp.push(parseInt(number))
        }
    }

    
    temp = new Set(temp)

    console.log(temp)


    for(let n of temp) {
        if(isPrime[n] === 0) {
            answer++;
        }
    }

    return answer;
}

solution("3320")