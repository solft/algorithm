# 11809번 충돌
# 풀이:
#       간단한 구현 문제
#       python으로 풀면 쉬워 보여 python으로 풀었는데
#       너무 중복 코드도 많고 조금 복잡하게 푼 거 같다.
#       그냥 뒤에서부터 숫자 비교해가며 답에 더했다.
n = int(input())
m = int(input())
nAns = 0
mAns = 0
nYoda = True
mYoda = True

nk = 0
mk = 0
while n > 0 or m > 0:
    if n % 10 > m % 10:
        nYoda = False
        nAns += (n % 10) * (10 ** nk)
        nk = nk + 1
    elif n % 10 < m % 10:
        mYoda = False
        mAns += (m % 10) * (10 ** mk)
        mk = mk + 1
    else:
        nYoda = False
        mYoda = False
        nAns += (n % 10) * (10 ** nk)
        mAns += (m % 10) * (10 ** mk)
        nk = nk + 1
        mk = mk + 1

    n = n // 10
    m = m // 10

if nYoda:
    print("YODA")
else:
    print(nAns)

if mYoda:
    print("YODA")
else:
    print(mAns)
