function solution(records) {

    let profiles = {};

    for(let i=0; i<records.length; i++) {
        let record = records[i];

        let [command, userId, userNickname] = record.split(" ");
        
        if(command !== "Leave") {
            profiles[userId] = userNickname;  
        }
    }

    var answer = [];

    for(let i=0; i<records.length; i++) {
        let record = records[i];

        let [command, userId, userNickname] = record.split(" ");
        
        if(command === "Enter") {
            let result = `${profiles[userId]}님이 들어왔습니다.`
            answer.push(result)
        } else if(command === "Leave") {
            let result = `${profiles[userId]}님이 나갔습니다.`
            answer.push(result)
        }
    }
   
    return answer;
}

solution(["Enter uid1234 Muzi",  "Enter uid4567 Prodo", "Change uid4567 Ryan","Leave uid1234","Enter uid1234 Prodo"])