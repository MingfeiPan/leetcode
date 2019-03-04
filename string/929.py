class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        
        ret = set()
        
        for str in emails:
            parts =  str.split('@')
            pre = parts[0].replace('.','')
            for i in range(len(pre)):
                if pre[i] == '+':
                    pre = pre[:i]
                    break
            
            ret.add(pre+parts[1])
            
        return len(ret)
                    
