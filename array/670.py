class Solution:
    def maximumSwap(self, num: int) -> int:
        arr = list(map(int, str(num))) #int->str->int list
        last = {x : i for i, x in enumerate(arr)} #考察每一个数以及其index位置, 并把这个数最靠后的index位置保存下来, 替换要确保替换到靠后的数

        for i, x in enumerate(arr):
            for d in range(9, x, -1): #对于每个数只有比他大的数才会被考察, 而且会从最大的开始考察, 保证不会交换到较小数 比如789123 不会造成7,8交换
                if last.get(d, 0) > i: #如果比他大的数位置靠后, 则直接交换
                    arr[i], arr[last[d]] = arr[last[d]], arr[i]
                    return int("".join(map(str, arr)))
                
        return num
                
