function solution(n) {
    var answer = "";
    let mod = ["4","1","2"];
    
    while(n > 0){
        answer = mod[n%3] + answer;
        n = parseInt((n-1)/3);
    }
    
    return answer;
}