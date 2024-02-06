class Solution:
    def fullJustify(self, words: list[str], maxWidth: int) -> list[str]:
        justified_text = []
        curr_line = ""
        num_words_curr_line = 0 #number of words in current line
        for word in words:
            if curr_line != "" and len(curr_line) + len(word) + 1 > maxWidth: # 1 for space
                extra_space = maxWidth - len(curr_line) #count how much extra space is there
                more_spaces = 0
                rem_spaces = 0
                if num_words_curr_line > 1:
                    more_spaces = extra_space//(num_words_curr_line-1)
                    rem_spaces = extra_space % (num_words_curr_line-1)

                    curr_line = curr_line.replace(" ", " "*(more_spaces + 1))
                    curr_line = curr_line.replace(" " * (more_spaces + 1), " " * (more_spaces + 2), rem_spaces)

                else: # num of words == 1:
                    curr_line += " "*extra_space
                justified_text.append(curr_line)

                curr_line = word
                num_words_curr_line = 1
            else:
                if curr_line != "":
                    curr_line += " "
                curr_line += word
                num_words_curr_line +=1

        # the last line has not appended yet
        curr_line += " "*(maxWidth - len(curr_line))
        justified_text.append(curr_line)
        return justified_text

def main():
    words = ["Listen","to","many,","speak","to","a","few."]
    maxWidth = 6
    sol_obj = Solution()
    justified_text = sol_obj.fullJustify(words, maxWidth)
    print(justified_text)
    for line in justified_text:
        print(line)

if __name__=="__main__":
    main()
