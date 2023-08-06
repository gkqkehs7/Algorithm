function solution(skill, skill_trees) {


    let answer = 0;

    let skillList = skill.split("");

    for (let skill_tree of skill_trees) {
        let temp = [];
        for (let skill of skill_tree) {
            if (skillList.includes(skill)) temp.push(skill);
        }

        if (skill.startsWith(temp.join(""))) {
            answer += 1;
        }
    }

    console.log(answer)

    return answer;
}

solution("CBD", ["BACDE", "CBADF", "AECBF", "BDA"])