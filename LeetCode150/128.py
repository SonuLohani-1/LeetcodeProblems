class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        myset = set()
        ans = 0
        for num in nums:
            myset.add(num)
        for num in nums:
            if num-1 not in myset:
                j = num
                while j in myset:
                    j += 1
                ans = max(ans, j - num) 
        return ans
                    
def main():
    obj = Solution()
    nums = [0,3,7,2,5,8,4,6,0,1]
    ans = obj.longestConsecutive(nums)
    print(ans)

if __name__=="__main__":
    main()
        