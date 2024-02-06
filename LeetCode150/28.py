class Solution:
    def strStr(self, haystack: str, needle: str) -> int:

        i, j = 0, 0
        prefix = self.built_prefix(needle)
        while i < len(haystack):

            print (f"Value of i : {i} and Value of j : {j}")

            if j == len(needle):
                print("now since j and needle length are equal we can return")
                return i - j
            
            if haystack[i] != needle[j] and j != 0:
                j = prefix[j-1]

            elif haystack[i] == needle[j]:
                i+=1
                j+=1

            else: # j == 0
                i+=1
            
        if(j == len(needle)):
            return len(haystack) - len(needle) 
        return -1

    def built_prefix(self, needle: str):
        j, i = 0, 1
        prefix = [0]
        while i < len(needle):
            if needle[i] == needle[j]:
                # print("appending ", j+1)
                prefix.append(j+1)
                i+=1
                j+=1
            elif j == 0:
                # print("appending ", 0)
                prefix.append(0)
                i+=1
            else:
                j = prefix[j-1]
        return prefix
    
def main():
        obj = Solution()
        needle = "issip"
        haystack = "mississippi"
        ans = obj.strStr(haystack, needle)
        print(ans)
        
        

if __name__ == "__main__":
    main()

            
            
