




def solution(money):
    d0 = [money[0], money[1], money[2] + money[0], max(money[1], money[0]) + money[3]]
    d1 = [money[1], money[2], money[1] + money[3]]
    if len(money) == 3 :
        return max(money)
    for i in range(4, len(money)) :
        d0.append(max(d0[-2], d0[-3]) + money[i])
        d1.append(max(d1[-2], d1[-3]) + money[i])

    #print(d0, d1)

    # print(d0)
    # print(d1)
    answer = max(d0[-2], d0[-3], d1[-1])
    return answer

if __name__ == "__main__" :
    money = [1,2,3,1]
    ans = solution(money)
    print(ans)