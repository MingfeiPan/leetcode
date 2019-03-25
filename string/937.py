class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def f(log):
            pre, nxt = log.split(" ", 1)
            return (0, nxt) if nxt[0].isalpha() else (1,)
        
        return sorted(logs, key=f)
