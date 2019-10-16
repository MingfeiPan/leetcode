type WordDictionary struct {
    next map[rune]*WordDictionary
    isWord bool
}


/** Initialize your data structure here. */
func Constructor() WordDictionary {
    return WordDictionary{next: make(map[rune]*WordDictionary), isWord: false}
}


/** Adds a word into the data structure. */
func (this *WordDictionary) AddWord(word string)  {
    for _, c := range word {
        if _, ok := this.next[c]; !ok {
            this.next[c] = &WordDictionary{next: make(map[rune]*WordDictionary), isWord: false}
        }
        this = this.next[c]
    }
    this.isWord = true
}


/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
func (this *WordDictionary) Search(word string) bool {
    if len(word) == 1 {
        if word[0] == '.' {
            for _, v := range this.next {
                if v.isWord {
                    return true
                }
            }
        }else {
            if _, ok := this.next[rune(word[0])]; !ok {
                return false
            }else {
                return this.next[rune(word[0])].isWord
            }    
        }
    }else {
        if word[0] == '.' {
            for _, v := range this.next {
                if v.Search(word[1:]) {
                    return true
                }
            }
        }else {
            if _, ok := this.next[rune(word[0])]; !ok {
                return false
            }else {
                return this.next[rune(word[0])].Search(word[1:])
            }            
        }
    }
    return false
}


/**
 * Your WordDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddWord(word);
 * param_2 := obj.Search(word);
 */
