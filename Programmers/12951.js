function solution(s) {

    let str_arr = s.split(" ");

    for(let i=0; i<str_arr.length; i++) {
        let str = str_arr[i];

        if(str === "") continue;
  
        let first_str = str[0].toUpperCase();

        let new_str = "";

        if(str.length > 1) {
            new_str = first_str + str.slice(1).toLowerCase();
        }
        
        str_arr[i] = new_str
    }

    let answer = "";

    for(let i=0; i<str_arr.length; i++) {
        if(i !== str_arr.length - 1) {
            answer += str_arr[i] + " ";
        } else {
            answer += str_arr[i];
        }   
    }
  

    // console.log(answer);

    return answer;  
}

solution(" 3people  unFollowed me")