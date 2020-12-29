# O(n^2)
def getDiff(A, index):
    return abs(sum(A[:index]) - sum(A[index:]))

def solution(A):
    answer = -1
    N = len(A)

    curr = N//2
    answer = getDiff(A, curr)
    # print(curr)
    #print(getDiff(A, 2))

    for i in range(N):
        if i == 0:
            continue
        temp = getDiff(A, i)

        if temp < answer:
            answer = temp

    return answer

# O(n)
def solution2(A):
    answer = 99999
    N = len(A)

    forwardSum = []
    backwardSum = []

    Sum = 0
    for i in A:
        Sum += i
        forwardSum.append(Sum)

    A.reverse()
    Sum = 0
    for i in A:
        Sum += i
        backwardSum.append(Sum)

    backwardSum.reverse()

    for i in range(N-1):
        cand = abs(forwardSum[i] - backwardSum[i+1])

        if cand < answer:
            answer = cand

    return answer