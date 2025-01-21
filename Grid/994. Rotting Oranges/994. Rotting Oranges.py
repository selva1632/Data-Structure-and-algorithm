class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        fresh = 0
        Q = deque()

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    fresh += 1
                elif grid[i][j] == 2:
                    Q.append([i, j])
        
        if fresh == 0:
            return 0

        dx = [1, 0, 0, -1]
        dy = [0, -1, 1, 0]
        time = 0

        while len(Q) > 0:
            size = len(Q)
            time += 1
            for i in range(size):
                x, y = Q[0][0], Q[0][1]
                Q.popleft()

                for k in range(4):
                    r = x + dx[k]
                    c = y + dy[k]

                    if r >= 0 and r < n and c >= 0 and c < m and grid[r][c] == 1:
                        grid[r][c] = 2
                        fresh -= 1
                        Q.append([r, c])

        if fresh > 0: return -1
        return time - 1