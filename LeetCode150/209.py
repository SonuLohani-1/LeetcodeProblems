class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        i, j, res, sum, = 0, 0, int(2e9), 0
        while j < len(nums):
            sum += nums[j]
            while sum >= target:
                res = min(res, j - i +1)
                sum -= nums[i]
                i+=1
            j += 1
        return res if res < int(2e9) else 0
    

def main():
    obj = Solution()
    nums = [5,1,3,5,10,7,4,9,2,8]
    ans = obj.minSubArrayLen(15, nums)
    print(ans)

if __name__=="__main__":
    main()