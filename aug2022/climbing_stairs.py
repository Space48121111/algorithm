from __future__ import annotations;
'''
n steps 1-45
1 or 2

comb = [(a, b)]
edge cases: all 1step only a only b
brutal force:
n=3 1,1,1
1,2 2,1 2
n=4 1,2,1 1,1,2 2,1,1 *3
2, 2
n=5 1,1,1,2 *4
2,2,1 *3
n=6 1,1,1,1,2 *5
2,2,1,1 *4
2,2,1 *3
(n-1)+(n-2)+...+3
n = a + 2b

decision trees:
at each step: either 1 or 2
base case recursion DFS O(2^n)
cache dynamic programming memoization
tree bottom up from base case(sub problems) all the way to the root
store into an array, each being solved once O(n)
Fibonacci sequence O(c)
8 5 3 2 1 1

'''

def climb_stairs(n: int) -> int:
    one, two = 1, 1
    for i in range(n-1):
        tmp = one
        one = one + two
        two = tmp
    return one

print(climb_stairs(4))

# nice trying
def climbStairs(n: int) -> int:
    # only a, b=0
    ct = 1
    for a in range(n+1):
        for b in range(n+1):
            if a + 2*b == n:
                print(a, b)
                # only b, a=0
                if n % 2 == 0:
                    ct += 1
                ct += 1

    return ct
