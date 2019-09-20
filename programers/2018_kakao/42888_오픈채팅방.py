import re


def Enter(id, character) :
    for i in range(len(ids)) :
        if ids[i] == id :
            answer.append(characters[i] + "님이 들어왔습니다.")
            return
    ids.append(id)
    characters.append(character)
    answer.append(character+"님이 들어왔습니다.")

def Leave(id) :
    for i in range(len(ids)) :
        if ids[i] == id :
            answer.append(characters[i]+"님이 나갔습니다.")
            break

def Change(id, character) :
    for i in range(len(ids)) :
        if ids[i] == id :
            characters[i] = character

def Enterchange(id, character) :
    for i in range(len(ids)) :
        if ids[i] == id :
            characters[i] = character
            return
    ids.append(id)
    characters.append(character)






if __name__ == "__main__" :
    record = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
    ids = []
    characters = []
    answer = []
    inout = []
    for i in range(len(record)) :
        print("a")
        tmp = re.split(" ", record[i])
        if tmp[0] == "Enter" :
            Enterchange(tmp[1], tmp[2])
            inout.append([tmp[1],tmp[2]])
        elif tmp[0] == "Leave" :
            inout.append([tmp[1]])
        else :
            Change(tmp[1], tmp[2])
    print(ids)
    print(characters)
    for i in range(len(inout)) :
        if len(inout[i]) == 1 :
            Leave(inout[i][0])
        else :
            Enter(inout[i][0], inout[i][1])
    print(answer)