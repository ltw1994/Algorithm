from collections import deque

def solution(arrangement):
    idx = 0
    cnt = 0
    answer = 0
    while(idx < len(arrangement)-1) :
        #print(idx, cnt, answer)
        if arrangement[idx] == '(' and arrangement[idx+1] == ')' :
            answer += cnt
            idx += 2
        elif arrangement[idx] == '(' :
            cnt += 1
            idx += 1
        elif arrangement[idx] == ')' :
            answer += 1
            cnt -= 1
            idx += 1
    return answer+1