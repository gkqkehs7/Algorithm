    
    for(let i=0; i<maps.length; i++) {
        for(let j=0; j<maps[i].length; j++) {
            if(maps[i][j] === "X") {
                new_map[i][j] = -1;
            } else {
                new_map[i][j] = parseInt(maps[i][j])
            }
        }
    }

    console.log(new_map)
    var answer = [];
    return answer;