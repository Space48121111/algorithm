import heapq

class Solution:
    def maxPerformance(self, n, eff, spd, k):
        eng = []
        for eff, spd in zip(eff, spd):
            eng.append([eff, spd])
        eng.sort(reverse=True)

        res, speed = 0, 0
        minHeap = []
        for eff, spd in eng:
            if len(minHeap) == k:
                speed -= heapq.heappop(minHeap)
            speed += spd
            heapq.heappush(minHeap, spd)
            res = max(res, eff * speed)
        return res % (10 ** 9 + 7)

s = Solution()
eff = [5, 4, 3, 9, 7, 2]
spd = [2, 10, 3, 1, 5, 8]
print(s.maxPerformance(6, eff, spd, 2))
