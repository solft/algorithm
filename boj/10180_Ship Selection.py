# 10180번 Ship Selection
# 풀이:
#       수학 관련 구현 문제
#       식을 만족하는 개수만 구하면 된다.
t = int(input())

for i in range(t):
    line = input().split(" ")
    n = int(line[0])
    d = float(line[1])

    ans = 0

    for j in range(n):
        val = input().split(' ')
        if d <= (float(val[0]) * float(val[1]) / float(val[2])):
            ans += 1

    print(ans)
