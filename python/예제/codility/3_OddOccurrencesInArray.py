def solution(A):
    mydict = dict()

    checker = [-1 for _ in range(1000000)]
    curr = 0

    for j in A:
        # Hashing process
        if j in mydict:
            i = mydict[j]
        else:
            mydict[j] = curr
            i = curr
            curr += 1

        # check
        if checker[i] == -1:
            checker[i] = 0
        elif checker[i] == 0:
            checker[i] = 1
        elif checker[i] == 1:
            checker[i] = 0
    
    #print(A)
    #print(mydict)
    #print(checker)

    for i in range(len(checker)):
        if checker[i] == 0:
            answer = list(mydict.keys())[i]
            break

    return answer