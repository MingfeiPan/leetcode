class Solution {
public:
    string minimizeResult(string expression) {
        // find +
        int index = 0;
        for (int i = 0; i < expression.size(); ++i) {
            if (expression[i] == '+') {
                index = i;
                break;
            }
        }
        int ret = INT_MAX;
        int left = 0, right = expression.size()-1;
        for (int i = index-1; i >= 0; --i) {
            for (int j = index+1; j < expression.size(); ++j) {
                int sum = convert(expression.substr(i, index-i)) + convert(expression.substr(index+1, j-index));
                int a = convert(expression.substr(0, i));
                int b = convert(expression.substr(j+1, expression.size()-j));
                if (a > 0) sum *= a;
                if (b > 0) sum *= b;
                if (sum < ret) {
                    ret = sum;
                    left = i;
                    right = j;
                }
            }
        }
        expression.insert(left,"(");
        expression.insert(right+2,")");
        return expression;
    }
private:
    int convert(std::string s) {
        if (s.empty()) return 0;
        return std::stoi(s);
    }
};
