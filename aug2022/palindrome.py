'''
 l
abba
  r

  l
abcba
  r
'''

s = 'abba'

def longestPalindrome(s):
    bestLength = 0
    res = ''
    for i in range(len(s)):
        for j in range(2):
            l, r = i, i+j
            while l >= 0 and r < len(s) and s[l] == s[r]:
                print('l r', l, r)
                length = r-l+1
                # length = max(length, r-l+1)
                if length > bestLength:
                    bestLength = length
                    res = s[l:r+1]
                    print('Res ', res)
                l -= 1
                r += 1
    return res

print('Final Res ', longestPalindrome(s))








# end
