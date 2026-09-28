class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> str;
        for (string st : tokens) {
            if (st == "+") {
                int b = str.top();
                str.pop();
                int a = str.top();
                str.pop();
                str.push(a + b);
            } else if (st == "-") {
                int b = str.top();
                str.pop();
                int a = str.top();
                str.pop();
                str.push(a - b);
            } else if (st == "*") {
                int b = str.top();
                str.pop();
                int a = str.top();
                str.pop();
                str.push(a * b);
            } else if (st == "/") {
                int b = str.top();
                str.pop();
                int a = str.top();
                str.pop();
                str.push(a / b);
            } else {
                str.push(stoi(st));
            }
        }
        return str.top();
    }
};
