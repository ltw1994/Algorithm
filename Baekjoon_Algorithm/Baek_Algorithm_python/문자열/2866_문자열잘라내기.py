

if __name__ == "__main__" :

    R, C = map(int, input().split())
    strs = []
    for _ in range(R) :
        str1 = str(input())
        chars = []
        for i in range(C) :
            chars.append(str1[i])
        strs.append(chars)

    cnt = 0
    start = 0
    end = R - 1
    mid = 0
    flag = False
    before = 0
    while (start <= end):
        before = mid
        mid = (start + end) // 2
        print(start, end, mid)
        addLst = []
        for j in range(C):
            addStr = ''
            for i in range(mid, R):
                addStr += strs[i][j]
            addLst.append(addStr)
          #  print("@" , addStr)
        print(sorted(addLst))
        print(sorted(list(set(addLst))))
        if sorted(addLst) == sorted(list(set(addLst))):
            start = mid + 1
            flag = False
        else:
            end = mid - 1
            flag = True



    # while(True) :
    #     if (cnt-1) == R :
    #         break
    #     addLst = []
    #     for j in range(C):
    #         addStr = ''
    #         for i in range(cnt, R) :
    #             addStr +=  strs[i][j]
    #         addLst.append(addStr)
    #     # print(addLst)
    #     # print(sorted(list(set(addLst))))
    #     if sorted(addLst) == sorted(list(set(addLst))) :
    #         cnt += 1
    #     else :
    #         break
    if flag == True :

        print(mid-1)
    else :
        print(mid)
'''
6 6
qwerqy
asdbgh
zxcvbn
aceeda
abdbza
cbedqc

7 2
ab
ba
ab
aa
aa
aa
aa

0123456
'''