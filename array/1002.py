class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        words_list = []
        for word in A:
            word_list = list(word)
            words_list.append(word_list)
            
        ret = []
        for c in words_list[0]:
            flag = 0
            for i in range(1, len(words_list)):
                if not c in words_list[i]:
                    flag = 1
                    break
                else:
                    words_list[i].remove(c)
            if flag == 0:
                ret.append(c)
        
        return ret
            
