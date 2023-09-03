function solution(targets) {

    /*
    비교 함수 (a, b) => a[0] - b[0]는 첫 번째 값에 대해 오름차순으로 정렬하도록 정렬 알고리즘에게 지시하는 역할을 합니다. 
    반환 값이 음수이면 a[0]이 b[0]보다 작다는 의미이므로 a를 b보다 앞으로 이동시킵니다.\
    반환 값이 양수이면 a[0]이 b[0]보다 크다는 의미이므로 a를 b보다 뒤로 이동시킵니다. 반환 값이 0이면 두 값이 같은 순서로 유지됩니다.
    */
    targets.sort((a, b) => {
        if(a[1] == b[1]) {
            return a[0] - b[0];
        } 
        return a[1] - b[1];
    });

    var checkpoint = -1;
    var answer = 0;
    
    for (let i = 0; i < targets.length; i++) {
      const [start, end] = targets[i];
        
        if(checkpoint <= start) {
            answer++;
            checkpoint = end;
        }
    }
    
    return answer;
}

