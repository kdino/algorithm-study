def solution(X, Y, D):
    if (Y - X) % D == 0:
        cnt = (Y - X) // D
    else:
        cnt = (Y - X) // D + 1

    return cnt