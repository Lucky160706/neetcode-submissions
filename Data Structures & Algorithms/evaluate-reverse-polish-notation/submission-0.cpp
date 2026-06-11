class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int top = 0;
        string token;
        for (int i = 0; i < tokens.size(); i++) {
            token = tokens[i];
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num1 = stoi(tokens[top - 1]);
                int num2 = stoi(tokens[top - 2]);
                int val;
                if (token == "+") val = num2 + num1;
                else if (token == "-") val = num2 - num1;
                else if (token == "*") val = num2 * num1;
                else if (token == "/") val = num2 / num1;
                tokens[top - 2] = to_string(val);
                top--;
            } else {
                tokens[top] = token;
                top++;
            }
        }
        return stoi(tokens[0]);
    }
};
