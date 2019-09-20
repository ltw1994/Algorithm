import re

answer = []
inout = []
match = dict()

if __name__ == "__main__" :
    record = ["Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo",
              "Change uid4567 Ryan"]
    for i in range(len(record)):
        tmp = re.split(" ", record[i])
        if tmp[0] == "Enter":
            match[tmp[1]] = tmp[2]
            inout.append([0, tmp[1]])
        elif tmp[0] == "Leave":
            inout.append([1, tmp[1]])
        else:
            match[tmp[1]] = tmp[2]

    for i in range(len(inout)) :
        id = inout[i][1]
        if inout[i][0] == 0 :
            answer.append(match[id]+"님이 들어왔습니다.")
        else :
            answer.append(match[id]+"님이 나갔습니다.")