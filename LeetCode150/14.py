class Solution:
    def findCommon(self, s1, s2):
        for i in range(min(len(s1), len(s2))):
            if s1[i] != s2[i]:
                return s1[:i]
            
        return s1 if len(s1) <= len(s2) else s2

    def longestCommonPrefix(self, strs: list[str]) -> str:
        common = strs[0]
        for i in range(1, len(strs)):
            common = self.findCommon(common, strs[i])
        return common

s = Solution()
strs = ["abcd", "abc"]
common = s.longestCommonPrefix(strs)
print(common)