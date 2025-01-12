#problem link: https://leetcode.com/problems/number-of-provinces

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        provinces = 0
        visited = [False for i in range(n)]

        def dfs(ind: int, isConnected: List[List[int]], visited: List[bool]): 
            visited[ind] = True

            for j in range(0, len(isConnected)):
                if ind != j and isConnected[ind][j] == 1:
                    if visited[j] == False:
                        dfs(j, isConnected, visited)

        for i in range(0, n):
            if visited[i] == False:
                provinces += 1
                dfs(i, isConnected, visited)
        
        return provinces