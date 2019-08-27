class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        rets = {}

        for s in strs:
            if not rets:
                rets[tuple(sorted(s))] = [s]
                continue
            key = tuple(sorted(s))
            if rets.get(key, None):
                rets[key].append(s)
            else:
                rets[key] = [s]
        return rets.values()
        
