def solution(numbers):
    digits = list(numbers)
    visited = [False] * len(digits)
    result_set = set()

    def make_permutation(current):
        if current:
            result_set.add(int(''.join(current)))

        for i in range(len(digits)):
            if not visited[i]:
                visited[i] = True
                current.append(digits[i])
                make_permutation(current)
                current.pop()
                visited[i] = False
    
    def isPrime(num):
        if num <= 1:
            return False
        for i in range(2, (int)(num **0.5)+1):
            if num % i == 0:
                return False
        return True
        
    make_permutation([])
    cnt = 0
    for sosu in result_set:
        if isPrime(sosu):
            cnt += 1
    
    return cnt