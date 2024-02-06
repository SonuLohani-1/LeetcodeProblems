class Solution:
    def summaryRanges(self, nums: list[int]) -> list[str]:
        if len(nums) == 0:
            return []
        if len(nums) == 0:
            return [str(nums[0])]
        lower_bound = nums[0]
        last = nums[0]

        res = []

        for num in nums[1:]:
            if num != last + 1:
                if lower_bound == last:
                    res.append(str(lower_bound))
                else:
                    res.append(str(lower_bound)+"->"+str(last))
                lower_bound = num
            last = num
        
        if lower_bound == nums[-1]:
            res.append(str(lower_bound))
        else:
            res.append(str(lower_bound) + "->" + str(nums[-1]))

        return res

def main():
    obj = Solution()
    nums = [0,2,3,4,6,8,9]
    ans = obj.summaryRanges(nums)
    print(ans)

if __name__=="__main__":
    main()

        