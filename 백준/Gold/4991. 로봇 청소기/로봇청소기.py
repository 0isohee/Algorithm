from collections import deque
from itertools import permutations

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(start, room, w, h):
    queue = deque([start])
    distances = [[-1] * w for _ in range(h)]
    distances[start[1]][start[0]] = 0
    
    while queue:
        x, y = queue.popleft()
        
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            
            if 0 <= nx < w and 0 <= ny < h and room[ny][nx] != 'x' and distances[ny][nx] == -1:
                distances[ny][nx] = distances[y][x] + 1
                queue.append((nx, ny))
    
    return distances

def solve(w, h, room):
    dirty_positions = []
    start = None
    
    for y in range(h):
        for x in range(w):
            if room[y][x] == 'o':
                start = (x, y)
            elif room[y][x] == '*':
                dirty_positions.append((x, y))
    
    if not dirty_positions:
        return 0
    
    all_positions = [start] + dirty_positions
    n = len(all_positions)
    
    # 모든 위치 간의 최단 거리 계산
    distances = [[0] * n for _ in range(n)]
    for i in range(n):
        d = bfs(all_positions[i], room, w, h)
        for j in range(n):
            distances[i][j] = d[all_positions[j][1]][all_positions[j][0]]
            if distances[i][j] == -1:
                return -1
    
    dp = [[float('inf')] * n for _ in range(1 << n)]
    dp[1][0] = 0
    
    for mask in range(1 << n):
        for i in range(n):
            if mask & (1 << i):
                for j in range(n):
                    if not (mask & (1 << j)):
                        dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + distances[i][j])
    
    return min(dp[(1 << n) - 1][i] for i in range(n))

while True:
    w, h = map(int, input().split())
    if w == 0 and h == 0:
        break
    
    room = [input().strip() for _ in range(h)]
    print(solve(w, h, room))
