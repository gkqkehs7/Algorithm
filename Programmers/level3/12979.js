function solution(n, stations, w) {

    let arr = [];

    for(let i=0; i<stations.length; i++) {
        arr[i] = [stations[i]- w, stations[i] + w];
    }
    
    let scope = w * 2 + 1;

    let now = 0;
    let idx = 0;
    let answer = 0;

    if(arr[0][1] <= scope) {
        now = arr[0][1] + 1;
        idx += 1;
    }

    while(idx < arr.length) {

        let [wifi_start, wifi_end] = arr[idx]

        if(now < wifi_start) {
            now = now + scope;
            answer += 1;
        } else if(now >= wifi_start) {
            now = wifi_end + 1
            idx += 1; 
        }

    }

    console.log(now, n)

    if(now === n) {
        answer += 1;
    } else if(now < n) {
        let plus = parseInt((n - now) / scope);
        let rest = (n - now) % scope;
    
        if(rest !== 0) {
            answer += 1;
        }
    
        answer += plus;
    } 


    return answer;
}

solution(11, [4, 11], 1)