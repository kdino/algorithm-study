def solution(A, K):
    if len(A) == 0:
        return A

    for _ in range(K):
        top = A.pop()
        A.insert(0, top)

    return A