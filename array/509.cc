class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int a = 0, b = 1, temp = 0;
        while (n > 1) {
            temp = a + b;
            a = b;
            b = temp;
            --n;
        }
        return b;
    }
};


class Solution {
public:
    int fib(int n) {
        return recur(n, 0, 1);
    }
private:
    int recur(int n, int a0, int a1) {
        if (n == 0)
            return a0;
        return recur(--n, a1, a0+a1);
    }
};
