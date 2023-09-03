function solution(topping) {
    
    var answer = 0;
    var littleMap = new Map();
    var bigMap = new Map();
    for(var i =0;i<topping.length;i++){
        //토핑이 기존에 있었다면
        if(bigMap.has(topping[i])){
            bigMap.set(topping[i],bigMap.get(topping[i])+1);  
        }
        else{
            bigMap.set(topping[i],1);  
        }
    }

    for(var i =0;i<topping.length;i++){
        //big 쪽은 뺴줄꺼임. 근데 0이 된다면 빼지말고 아예 지워버림.
        
        if(bigMap.get(topping[i])===1){
            bigMap.delete(topping[i]);
        }
        else{
            bigMap.set(topping[i],bigMap.get(topping[i])-1); 
        }
        // littleMap은 값이 있다면 +1 해주고, 처음이라면 1로 지정.
        if(littleMap.has(topping[i])){
            littleMap.set(topping[i],littleMap.get(topping[i])+1);  
        }
        else{
            littleMap.set(topping[i],1);  
        }

        if(bigMap.size===littleMap.size){
            answer++;
        }

    }
    return answer;

}

solution([1, 2, 1, 3, 1, 4, 1, 2]);