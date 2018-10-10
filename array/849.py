class Solution:
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """
        if not seats:
            return 0
        pre = 0
        nxt = 0
        ret = 0
        cur = 0
        
        for i in range(0, len(seats)):
            if seats[i] == 0:
                pre = i-1
                nxt = i+1
                if i == 0:
                    while nxt < len(seats) and seats[nxt] == 0:
                        nxt += 1
                    cur = nxt - i
                    ret = max(cur, ret)
                elif i == len(seats) - 1:
                    while seats[pre] == 0:
                        pre -= 1
                    cur = i - pre
                    ret = max(cur, ret)
                else:
                    while seats[pre] == 0:
                        pre -= 1

                    while nxt < len(seats) and seats[nxt] == 0:
                        nxt += 1

                    print(i-pre)
                    cur = min((i-pre), (nxt-i))
                    # print(cur)
                    ret = max(cur, ret)
        return ret
        
