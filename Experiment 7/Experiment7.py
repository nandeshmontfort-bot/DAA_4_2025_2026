class Solution(object):
    def findCheapestPrice(self, n, flights, src, dst, k):
        dist = [float('inf')] * n
        dist[src] = 0
        
        for _ in range(k + 1):
            temp = dist[:]
            
            for u, v, price in flights:
                if dist[u] != float('inf') and dist[u] + price < temp[v]:
                    temp[v] = dist[u] + price
            
            dist = temp
        
        return -1 if dist[dst] == float('inf') else dist[dst]
