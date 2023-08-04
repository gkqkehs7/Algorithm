function solution(w, h) {

    let squre = 0;
    for(let i=1; i<h; i++) {
        let hei = (w * i) / h;

        squre += Math.floor(hei)
    }

    let answer = squre * 2;
    return answer;
}

solution(8, 12)