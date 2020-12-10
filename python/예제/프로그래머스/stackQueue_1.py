stack = list()

def solution(prices):
    answer = [0 for _ in range(len(prices))]
    
    for i in range(len(prices)-1):
        if i == 0:
            stack.append(i)
        else:
            while len(stack) != 0 and prices[stack[-1]] > prices[i]:
                poped = stack.pop()
                answer[poped] = i - poped
            stack.append(i)
    
    while len(stack) != 0:
        poped = stack.pop()
        answer[poped] = len(prices) - 1 - poped
    
    return answer