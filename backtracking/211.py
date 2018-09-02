class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.wordarr = {}
        

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        if len(word) in self.wordarr:
            self.wordarr[len(word)].append(word)
        else:
            self.wordarr[len(word)] = [word]
        

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        
        if not self.wordarr or not word:
            return False
        if len(word) not in self.wordarr:
            return False
        
        if not self.wordarr[len(word)]:
            return False
        
        for w in list(self.wordarr[len(word)]):
            count = 0
            for i in range(len(word)):
                if word[i] == '.' or word[i] == w[i]:
                    count+= 1
            if count == len(word):
                return True
        return False
            
    


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
