# class Solution:
    # def maxProfit(self, prices: List[int]) -> int:
def maxProfit(prices):
        # naive approach
#         max_p = 0
#         if prices == None:
#             return 0
#         for i in range(len(prices)-1):
#             # exclusive
#             for j in range(i+1, len(prices)):
#                 if max_p < 0:
#                     return 0
#                 max_p = max(max_p, (prices[j] - prices[i]))

#         return max_p

        # pointers
        max_p = 0
        l, r = 0, 1
        if prices == None:
            return 0
        # increase r
        while r < len(prices):
            p = prices[r] - prices[l]
            if p > 0:
                max_p = max(p, max_p)
            else:
                # increase l
                l = r
            r += 1
        return max_p


prices = [7,1,5,3,6,4]

prices1 = [7,6,4,3,1]


# expecting: 5
print(maxProfit(prices))
# expecting: 0
print(maxProfit(prices1))

# end
