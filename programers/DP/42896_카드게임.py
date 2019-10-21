


def solution(left, right):
    answer = 0
    d = [[-1 for i in range(len(right)+1)] for _ in range(len(left)+1)]
    d[0][0] = 0
    for i in range(len(left)) :
        for j in range(len(right)) :
            if d[i][j] != -1 :
                if left[i] > right[j] :
                    d[i][j] += right[j]
                    d[i][j+1] = max(d[i][j], d[i][j+1])
                else :
                    d[i+1][j+1] = max(d[i][j], d[i+1][j])
                    d[i + 1][j] = d[i][j]

    mx = 0
    for i in range(len(right) ) :
        mx = max(mx, d[len(left)-1][i], d[i][len(right)-1])
    print(mx)
    answer = mx
    return answer

if __name__ == "__main__" :
    left = [1]
    right = [2]
    ans = solution(left, right)
    print(ans)



# discards = [10000000]
#
# def DFS(left, right, left_cnt, right_cnt, discard) :
#
#     if discard > min(discards) :
#         return
#
#     if (left_cnt > len(left) - 1) or (right_cnt > len(right) - 1) :
#         if discard < min(discards) :
#             discards.append(discard)
#         return
#     if right[right_cnt] < left[left_cnt] :
#         DFS(left, right, left_cnt, right_cnt+1, discard)
#
#     else :
#         DFS(left, right, left_cnt+1, right_cnt, discard)
#         discard += right[right_cnt]
#         DFS(left, right, left_cnt+1, right_cnt+1, discard)
#
#
#
# def solution(left, right):
#     answer = 0
#     DFS(left, right, 0, 0, 0)
#     answer = sum(right) - min(discards)
#     return answer
#
#
#
# if __name__ == "__main__" :
#     left = [3,2,5]
#     right = [2,4,1]
#     ans = solution(left, right)
#     print(ans)







# scores = []
#
# def DFS(left, right, left_cnt, right_cnt, score, discard) :
#
#     #print(score, left_cnt, right_cnt)
#
#     if (left_cnt > len(left) - 1) or (right_cnt > len(right) - 1) :
#         scores.append(score)
#         return score
#     if right[right_cnt] < left[left_cnt] :
#         score += right[right_cnt]
#         right_cnt += 1
#         DFS(left, right, left_cnt, right_cnt, score, discard)
#
#     else :
#         DFS(left, right, left_cnt+1, right_cnt, score, discard)
#         discard += right[right_cnt]
#         DFS(left, right, left_cnt+1, right_cnt+1, score, discard)
#
#
# def solution(left, right):
#     answer = 0
#     DFS(left, right, 0, 0, 0, 0)
#     answer = max(scores)
#     return answer






#
# if __name__ == "__main__" :
#     left = [3,2,5]
#     right = [2,4,1]
#     ans = solution(left, right)
#     print(scores)
#
#     discards = [10000000]
#
#
#     def DFS(left, right, left_cnt, right_cnt, discard):
#
#         if discard > min(discards):
#             return
#
#         if (left_cnt > len(left) - 1) or (right_cnt > len(right) - 1):
#             if discard < min(discards):
#                 discards.append(discard)
#             return
#         if right[right_cnt] < left[left_cnt]:
#             DFS(left, right, left_cnt, right_cnt + 1, discard)
#
#         else:
#             DFS(left, right, left_cnt + 1, right_cnt, discard)
#             discard += right[right_cnt]
#             DFS(left, right, left_cnt + 1, right_cnt + 1, discard)
#
#
#     def solution(left, right):
#         answer = 0
#         DFS(left, right, 0, 0, 0)
#         answer = sum(right) - min(discards)
#         return answer