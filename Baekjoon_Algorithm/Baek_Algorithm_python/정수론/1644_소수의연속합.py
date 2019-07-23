MAX = 4000000
prime = [1 for _ in range(MAX+1)]
lst = []
for i in range(2, MAX+1):
    if i*i > MAX:
        break
    if prime[i] == 1:
        for j in range(i*i, MAX+1, i):
            prime[j] = 0

#print(prime[2:20])
prime[0] = 0
prime[1] = 0

for i in range(4000001) :
    if prime[i] == 1 :
        lst.append(i)
#print(lst[0:20])
left = 0
right = 0

N = int(input())
count = 0
sum = 0
while(True) :
    sum = 0

    if (left > right) or (right >= len(lst)) :
        break
    for i in range(left, right+1) :
        sum += lst[i]
  #  print(sum)
    if sum < N :
        right += 1
    elif sum == N :
        right += 1
        count += 1
    elif sum > N :
        left += 1
print(count)

