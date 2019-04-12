class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if not A or not B or len(A) != len(B):
            return False
        
        index = 0
        flag = 0
        buddy = []
        
        if A == B:
            if len(A) < 2:
                return False
            temp = set()
            for c in A:
                if c in temp:
                    return True
                temp.add(c)
            return False
        else:
            while index < len(A):
                while index < len(A) and A[index] == B[index]:
                    index += 1    

                if index == len(A) - 1 and A[index] == B[index]:
                    break
                buddy.append(index)
                index += 1    

            if len(buddy) == 2:
                if A[buddy[0]] == B[buddy[1]] and A[buddy[1]] == B[buddy[0]]:
                    return True

            return False
            
            
