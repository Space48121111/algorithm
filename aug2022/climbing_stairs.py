from __future__ import annotations;
'''
n steps 1-45
1 or 2

comb = [(a, b)]
n = a + 2b
'''

def climbStairs(n: int) -> int:
    a, b = 0, 0
    ct = 0
    for a in range(45):
        for b in range(45):
            if a + 2*b == n:
            # if a + 2*b == n and a != b:
                print(a, b)
                ct += 1

    return ct

print(climbStairs(20))
