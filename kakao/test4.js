function removeElementsFromArray(arr, elementsToRemove) {
    const copy_arr = arr.slice();
    const newArray = copy_arr.filter(element => !elementsToRemove.includes(element));
    return newArray;
}
  

const getCombinations = (arr, num) => {
    const results = [];
    if (num === 1) return arr.map(v => [v]);

    arr.forEach((fixed, index, origin) => {
        const rest = origin.slice(index + 1);
        const combinations = getCombinations(rest, num - 1);
        const attached = combinations.map(v => [fixed, ...v]);

        results.push(...attached);
    });

    return results;
}


function solution(coin, cards) {
    let answer = 0;

    function dfs(selected, unselected, coin, n, depth) {

        answer = Math.max(answer, depth + 1);
        // console.log(selected, unselected, coin)
        // 뽑을 수 있는 카드 없어서 종료
        if(unselected.length < 2) {
            return;
        }

        // 낼 수 있는 카드 없어서 종료
        if(selected.length < 2) {
            return;
        }

        const first = unselected.shift();
        const second = unselected.shift();

        // 두 장 다 버리는 경우
        const combs = getCombinations(selected, 2);  
        
        for(const comb of combs) {
            const new_selected = selected.slice();

            if(comb[0] + comb[1] === n) {        
                const newArray = removeElementsFromArray(new_selected, comb);
            
                dfs(newArray, unselected, coin, n, depth + 1);
            }
        }

        // 첫 번쨰 카드만 가져가는 경우
        if(coin >= 1) {
            const new_selected = selected.slice();
            
            new_selected.push(first);

            const combs = getCombinations(new_selected, 2);
            
            for(const comb of combs) {
                if(comb[0] + comb[1] === n) {
                    const newArray = removeElementsFromArray(new_selected, comb);
                    dfs(newArray, unselected, coin - 1, n, depth + 1);
                }
            }
        }

        // 두번째 카드만 가져가는 경우
        if(coin >= 1) {
            const new_selected = selected.slice();
            
            new_selected.push(second);

            const combs = getCombinations(new_selected, 2);
            
            for(const comb of combs) {
                if(comb[0] + comb[1] === n) {
                    const newArray = removeElementsFromArray(new_selected, comb);
                    dfs(newArray, unselected, coin - 1, n, depth + 1);
                }
            }
        }

    
        // 두장 다 가져가는 경우
        if(coin >= 2) {
            const new_selected = selected.slice();

            new_selected.push(first);
            new_selected.push(second);

            const combs = getCombinations(new_selected, 2);

            for(const comb of combs) {
                if(comb[0] + comb[1] === n) {
                    const newArray = removeElementsFromArray(new_selected, comb);
                    dfs(newArray, unselected, coin - 2, n, depth + 1);
                }
            }
        }
    }

    
    const size = Math.floor(cards.length / 3);
    const [selected, unselected] = [cards.slice(0, size), cards.slice(size)];
    dfs(selected, unselected, coin, cards.length + 1, 0)

    return answer;
}

solution(3, [1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11, 12])