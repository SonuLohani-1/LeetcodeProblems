class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t): 
            return False
        d = {}
        for i in range(len(s)):
            if s[i] not in d:
                if t[i] in d.values():
                    return False
                d[s[i]] = t[i]
            else:
                if d[s[i]] != t[i]:
                    return False
        return True

def main():
    obj = Solution()
    s = "egg"
    t = "add"
    print(obj.isIsomorphic(s, t))

if __name__=="__main__":
    main()