'''
Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true

Constraints: 0 <= fromi < toi <= 1000

'''


class Solution:
    # O(n)
    def carPooling(self, trips, capacity):
        delta_n = [0] * 1001

        for t in trips:
            num, start, end = t
            delta_n[start] += num
            delta_n[end] -= num

        curr = 0
        for i in range(1001):
            curr += delta_n[i]
            if curr > capacity:
                return False
        return True

    # O(nlogn)
    def carPooling1(self, trips, capacity):
        trips.sort(key=lambda t: t[1])
        minHeap = [] # [end, num]
        curr = 0
        for t in trips:
            num, start, end = t
            while minHeap and minHeap[0][0] <= start:
                curr -= minHeap[0][1]
                heapq.heappop(minHeap)

            curr += num
            if curr > capacity:
                return False
            heapq.heappush(minHeap, [end, num])
        return True

    def carPooling2(self, trips, capacity):
        end = 0
        for i in range(len(trips)):
            if end < trips[i][2]:
                end = trips[i][2]
        for j in range(end):
            c = 0
            for i in range(len(trips)):
                if (trips[i][1] <= j <= trips[i][2]):
                    c += trips[i][0]
            if c > capacity:
                return False
        return True


s = Solution()
print(s.carPooling([[2,1,5],[3,3,7]], 5))
print(s.carPooling1([[2,1,5],[3,3,7]], 5))
print(s.carPooling2([[2,1,5],[3,3,7]], 5))













# end
