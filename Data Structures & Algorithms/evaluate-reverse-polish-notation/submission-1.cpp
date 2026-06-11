class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack(tokens.size());
        
        for (const string& token : tokens) {
            // An operator is exactly 1 char long and is not a digit
            // (Note: negative numbers like "-5" have a size > 1)
            if (token.size() == 1 && !isdigit(token[0])) {
                // Pop operands ONCE to keep code DRY
                int num2 = stack.back();
                stack.pop_back();
                int num1 = stack.back();
                stack.pop_back();
                
                // Switch statement on the single char is faster than string comparison
                switch (token[0]) {
                    case '+': stack.push_back(num1 + num2); break;
                    case '-': stack.push_back(num1 - num2); break;
                    case '*': stack.push_back(num1 * num2); break;
                    case '/': stack.push_back(num1 / num2); break;
                }
            } else {
                // It's a number, convert and push
                stack.push_back(stoi(token));
            }
        }
        
        return stack.back();
    }
};
