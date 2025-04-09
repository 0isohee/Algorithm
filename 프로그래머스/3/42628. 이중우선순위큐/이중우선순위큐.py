import heapq

def solution(operations):
    min_heap = []
    max_heap = []
    visited = [False] * len(operations)
    
    for i, operate in enumerate(operations):
        o, v = operate.split(' ')
        v = int(v)

        if o == "I":
            heapq.heappush(min_heap, (v, i))
            heapq.heappush(max_heap, (-v, i))
        else:
            #erase minV
            if v == -1:
                while min_heap and visited[min_heap[0][1]]:
                    heapq.heappop(min_heap)
                if min_heap:
                    visited[min_heap[0][1]] = True
                    heapq.heappop(min_heap)
            
            if v == 1:
                while max_heap and visited[max_heap[0][1]]:
                    heapq.heappop(max_heap)
                if max_heap:
                    visited[max_heap[0][1]] = True
                    heapq.heappop(max_heap)
    
    #sync
    while min_heap and visited[min_heap[0][1]]:
        heapq.heappop(min_heap)
    while max_heap and visited[max_heap[0][1]]:
        heapq.heappop(max_heap)
        
    if min_heap:
        return [-max_heap[0][0], min_heap[0][0]]
    else:
        return [0,0]