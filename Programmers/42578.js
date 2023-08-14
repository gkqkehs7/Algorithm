function solution(clothes) {

    let hash = {};

    for(let i=0; i<clothes.length; i++) {
        let [name, type] = clothes[i];

        if(hash.hasOwnProperty(type)) {
            hash[type].push(name)
        } else {
            hash[type] = [name]
        }
    }

    let arr = [];
    for(let cloth in hash) {
        arr.push(hash[cloth].length)
    }

    let answer = 1;

    for(let i=0; i<arr.length; i++) {
        answer *= (arr[i] + 1);
    }

    return answer - 1;
}

solution([["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]])