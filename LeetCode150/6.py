class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        cycle = 2*numRows - 2
        ans = ""
        for i in range(0, numRows):
            for j in range(i, len(s), cycle):
                ans += s[j]
                # print("***")
                # print(j)
                if (i != 0 and i != numRows-1) and (j + cycle - 2*i < len(s)):
                    # print("###")
                    # print(j + cycle - 2*i )
                    ans += s[j+cycle - 2*i];
        
        return ans

        
if __name__=="__main__":
    obj = Solution()
    param_1 = obj.convert("0123456789", 4)
    print(param_1)