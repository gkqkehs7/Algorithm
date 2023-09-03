function solution(n, k, enemy) {
    let answer = 0;
    let start = 0, end = enemy.length;
    
    while(start<=end){
        let mid = Math.floor((start+end)/2);
        let arr = enemy.slice(0, mid).sort((prev, next)=> next-prev); // 오름 차순 정렬
        
        let flag = true;
        let temp = 0;
        for(let i=k ; i<arr.length; i++){
            temp+=arr[i];
            if(temp>n) flag = false;
        }
        
        if(flag) {
            answer = mid;
            start = mid+1; 
        }
        else end = mid-1;
    }
    
    return answer;
}