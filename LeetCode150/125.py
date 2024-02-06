class Solution:
    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s)-1
        while i < j:
            if not s[i].isalnum():
                i+=1
            elif not s[j].isalnum():
                j-=1
            else:
                if s[i].lower() != s[j].lower():
                    a = s[i].lower()
                    print(a)
                    return False
                i+=1
                j-=1
        return True
    
def main():
    obj = Solution()
    s = "A man, a plan, a canal: Panama"
    res = obj.isPalindrome(s)
    print(res)

if __name__ == "__main__":
    main()