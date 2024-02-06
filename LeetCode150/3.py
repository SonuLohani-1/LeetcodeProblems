class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        map = {}
        ans = 0
        start = 0
        for i in range(len(s)):
            if s[i] in map:
                start = max(start, map[s[i]]+1)
            ans = max(ans, i - start + 1)
            map[s[i]] = i
        return ans
    
def main():
    s = "abcabcbb"
    obj = Solution()
    print(obj.lengthOfLongestSubstring(s))

if __name__=="__main__":
    main()

            
            
