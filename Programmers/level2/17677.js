function solution(str1, str2) {

    let arr1 = {};
    
    for(let i=0; i<str1.length - 1; i++) {
        let temp = str1[i];
        temp += str1[i+1];

        temp = temp.toLowerCase();

        var alphabetPattern = /^[a-zA-Z]+$/;

        if(alphabetPattern.test(temp)) {
            if(arr1.hasOwnProperty(temp)) {
                arr1[temp] += 1;
            } else {
                arr1[temp] = 1;
            }
        }
    }

    let arr2 = {};
    
    for(let i=0; i<str2.length - 1; i++) {
        let temp = str2[i];
        temp += str2[i+1];

        temp = temp.toLowerCase();

        var alphabetPattern = /^[a-zA-Z]+$/;

        if(alphabetPattern.test(temp)) {
            if(arr2.hasOwnProperty(temp)) {
                arr2[temp] += 1;
            } else {
                arr2[temp] = 1;
            }
        }
    }

    console.log(arr1, arr2)

    let intersect = 0;

    let union = 0;

    for(let key in arr1) {

        // arr2도 가지고 있는 경우
        if(arr2.hasOwnProperty(key)) {
            intersect += Math.min(arr1[key], arr2[key])
            union += Math.max(arr1[key], arr2[key])
        } else {
            union += arr1[key];
        }
    }

    // arr2만 가지고 있는 경우
    for(let key in arr2) {

        if(!arr1.hasOwnProperty(key)) {
            union += arr2[key];
        } 
    }

    console.log(intersect, union)

    if(intersect === 0 && union === 0) {
        return 65536;
    }   

    return parseInt((intersect / union) * 65536);
}

console.log(solution("aa1+aa2", "AAAA12"))