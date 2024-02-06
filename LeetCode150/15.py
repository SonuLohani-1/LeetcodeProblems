# similar to two sum just one more loop for the first member
# so if i is the position then the first number 
class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums = sorted(nums)
        ans = []
        for i in range(len(nums)-2):
            start = i+1
            end = len(nums)-1
            if i > 0 and nums[i-1] == nums[i]:
                continue
            while start < end:
                sum = nums[i] + nums[start] + nums[end]
                if  sum == 0 :
                    ans.append([nums[i], nums[start], nums[end]])
                    start += 1
                    end -= 1
                    while start < end and nums[start] == nums[start-1]:
                        start += 1
                    while end > start and nums[end] == nums[end+1]:
                        end -= 1
                elif sum > 0:
                    end -= 1
                else:
                    start += 1
        return ans


                

def main():
    nums = [-1,0,1,2,-1,-4]
    obj = Solution()
    ans = obj.threeSum(nums)
    print(ans)

if __name__=="__main__":
    main()