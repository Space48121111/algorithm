import heapq

'''
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
performance = (10 + 5) * min(4, 7) = 60.
'''


def maxPerformance(n, eff, spd, k):
    comb = []
    minHeap = []
    speed = 0
    res = 0

    # transpose
    for e, s in zip(eff, spd):
        comb.append((e, s))
    print(comb)
    comb.sort(reverse=True)
    print(comb)
    for eff, spd in comb:
        # if len(minHeap) >= k and spd > minHeap[0][0]:
        if minHeap and len(minHeap) >= k:
            print('len', minHeap)
            speed -= minHeap[0][0]
            heapq.heappop(minHeap)
            print('popout', minHeap)
        print('spd', spd)
        speed += spd
        perf = eff * speed
        print('perf', perf)
        res = max(res, perf)

        heapq.heappush(minHeap, [spd, res])

    return res % (10**9 + 7)

# n = 6
# eff = [5,4,3,9,7,2]
# spd = [2,10,3,1,5,8]
# k = 4
# expect 72

# n = 5
# spd = [10,10,7,9,8]
# eff = [9,8,3,6,9]
# k = 1
# expect 90


n = 6
spd = [2,10,3,1,5,8]
eff = [5,4,3,9,7,2]
k = 2
# expect 55
print(maxPerformance(n, eff, spd, k))
