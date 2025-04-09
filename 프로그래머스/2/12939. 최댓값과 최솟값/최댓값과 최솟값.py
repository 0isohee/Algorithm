def solution(s):
    
    input_list = list(map(int, s.split(' ')))
    
    minV = min(input_list)
    maxV = max(input_list)
    
    ans = [minV, maxV]
    
    return ' '.join(map(str,ans))