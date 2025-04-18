class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        n, result = len(s), 0
        while n > 0:
            n -= 1
            if s[n] != ' ': result += 1
            elif result > 0: return result
        return result
        