function solution(cacheSize, cities) {

    let cache = [];
    let answer = 0;

    if(cacheSize === 0) {
        return 5 * cities.length;
    }

    for(let i=0; i<cities.length; i++) {
        let input = cities[i].toLowerCase();

        if(cache.includes(input)) {
            cache = cache.filter(item => item !== input);
            cache.push(input);
            answer++;
        } else {
            if(cache.length >= cacheSize) {
                cache.shift();
            }

            cache.push(input);
            answer += 5;
        }
    }

    return answer;
}

solution(0, ["Jeju", "Pangyo", "NewYork", "newyork"]);