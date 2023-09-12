function solution(n, stations, w) {

    let arr = [];

    for(let i=0; i<stations.length; i++) {
        arr.push([stations[i]- w, stations[i] + w])
    }
    
    let scope = w * 2 + 1;

    let now = 0;
    let idx = 0;
    let answer = 0;

    console.log(arr)

    while(idx < arr.length) {
        let [wifi_start, wifi_end] = arr[idx]

        if(idx === 0 && wifi_end <= now + scope) {
            now = wifi_end + 1
            idx += 1;
            continue;
        }

        if(now + scope < wifi_start) {
            now = now + scope + 1
            answer += 1;
        } else if(now + scope >= wifi_start) {
            now = wifi_end + 1
            answer += 1;
            idx += 1; // 다음 와이파이 체크
        }
    }

    answer += Math.ceil((n - now) / scope);


    return answer;
}

solution(11, [4, 11], 1)