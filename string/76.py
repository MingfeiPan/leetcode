
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        
        counter_dict = self._counter(t)
        tar_dict = {x:0 for x in t}
        tar_list = [x for x in t]
        
        index = len(s)
        pre = 0 
        nxt = 0
        ans_start = 0 
        ans_end = 0
        ans_length = sys.maxsize
        
        while nxt < index:
            
            if s[nxt] in tar_list:
                tar_dict[s[nxt]] += 1
            if self.check_tar(tar_dict, counter_dict):
                
                while self.check_tar(tar_dict, counter_dict):
                    if s[pre] in tar_list:
                        tar_dict[s[pre]] -= 1
                    pre += 1
                pre = pre - 1 #退回最后之前的一个

                if nxt - pre + 1 < ans_length:
                    ans_start = pre
                    ans_end = nxt
                    ans_length = nxt - pre + 1
                pre += 1 #跳过当前这个结果, 找下一个
            nxt += 1
            
        if ans_start == 0 and ans_end == 0 and ans_length == sys.maxsize:
            return ""
        else:
            return s[ans_start:ans_end+1]
        
                
            
    def check_tar(self, tar_dict, counter_dict):
        for i, j in tar_dict.items():
            if j < counter_dict.get(i, 0):
                return False
        return True
    
    def _counter(self, s):
        d = {}
        for i in s:
            if d.get(i, None):
                d[i] += 1
            else:
                d[i] = 1
        return d
