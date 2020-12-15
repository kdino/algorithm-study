def solution(A):
    ans = -1
    N = len(A)

    checker = [0 for _ in range(N+2)]

    for i in A:
        checker[i] = 1

    #print(checker)

    if N == 0:
        ans = 1
    else:
        for i in range(1, N+2):
            if checker[i] == 0:
                ans = i
                break
    
    return ans