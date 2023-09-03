function solution(k, d) {
    let answer = 0;

    for(let x=0; x<=d; x+=k){
        // 2) 원점과의 거리 y의 좌표를 구한다.
        let y = parseInt(Math.sqrt(d**2 - x**2));
        
        // 3) y 좌표 내부 찍을 수 있는 점의 개수
        answer += parseInt(y/k)+1;
    }
    return answer;
}