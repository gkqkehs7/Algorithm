function solution(user_id, banned_id) {


    user_id.sort();

    banned_id.sort();

    console.log(user_id, banned_id)
    var answer = 0;
    return answer;
}

solution(["frodo", "fradi", "crodo", "abc123", "frodoc"], ["fr*d*", "abc1**"])