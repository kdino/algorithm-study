def solution(X, A):
    N = len(A)
    check = [0 for _ in range(X+1)]
    leaves = 0
    time = 0
    ans = 0

    for i in range(N):
        if check[A[i]] == 0:
            check[A[i]] = 1
            leaves += 1
        
        time += 1
        #print(check)

        if leaves == X:
            break

    
    if leaves != X:
        ans = -1
    else:
        ans = time - 1

    return ans