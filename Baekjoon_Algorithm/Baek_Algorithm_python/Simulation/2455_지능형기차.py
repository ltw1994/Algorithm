def train_people() :
    global people
    global count
    people -= train_out[count]
    people += train_in[count]
    count += 1
    history.append(people)

if __name__ == "__main__" :
    train_in = []
    train_out = []
    history = []
    for _ in range(4) :
        tmp1, tmp2 = map(int, input().split())
        train_out.append(tmp1)
        train_in.append(tmp2)

    count = 0
    people = 0

    for _ in range(4) :
        train_people()

    print(max(history))

