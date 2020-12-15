def decToBin(dec):
    binary = list()

    while dec > 0:
        binary.append(dec%2)
        dec = dec//2
    
    binary.reverse()
    return binary

def solution(N):
    answer = 0

    binary = decToBin(N)

    #print(binary)

    started = 0
    cnt = 0
    for i in binary:
        if i == 1:
            if started == 0:
                started = 1
            else:
                if answer < cnt:
                    answer = cnt
                cnt = 0
        else:
            cnt += 1

    return answer