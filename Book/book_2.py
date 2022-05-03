strs = input();

string = sorted(strs)

split = 0;
for i in range(len(string)):
    if(string[i].isdigit() == False):
         split = i;
         break;

nums = string[:split]
notNum = string[split:]

sum = 0
for num in nums: 
    sum += int(num)
    

print("".join(notNum)+str(sum))
