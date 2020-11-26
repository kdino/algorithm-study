def solution(n, lost, reserve):
    answer = 0  
    lostSet = set(lost)
    reserveSet = set(reserve)
    
    lost = list(lostSet)
    reserve = list(reserveSet)
    
    inter = lostSet & reserveSet
    
    for i in inter:
        lost.remove(i)
        reserve.remove(i)
    
    nlost = len(lost)
    saved = 0
    
    for i in reserve:
        for j in lost:
            if abs(i-j) <= 1:
                saved += 1
                lost.remove(j)
                print(i, j)
                break
            elif i<j: break
            else: continue
                
    answer = n - nlost + saved
    
    return answer