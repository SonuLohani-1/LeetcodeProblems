class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(words) != len(pattern):
            return False
        word_map = {}
        char_map = {}
        for i in range(len(words)):
                if words[i] in word_map and pattern[i] in char_map:
                    print(word_map[words[i]], " and ", char_map[pattern[i]])
                    if word_map[words[i]] != char_map[pattern[i]]:
                        return False
                elif words[i] not in word_map and pattern[i] not in char_map:
                    word_map[words[i]] = char_map[pattern[i]]=i
                else:
                    print("Both are matched differently. Returning False")
                    return False
        
        return True
    

def main():
    obj = Solution()
    pattern = "abba"
    s = "dog cat cat fish"
    print(obj.wordPattern(pattern, s))


if __name__=="__main__":
    main()

                