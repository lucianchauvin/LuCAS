#include "LuCAS.h"

double eval(std::string xpr) {
    std::stack<double> stack;

    for (int i = 0; i < xpr.length(); i++) {
        char c = xpr[i];
        if (c == ' ') continue;

        if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (stack.size() < 2) {
                throw std::invalid_argument("Invalid expression");
            }
            double a = stack.top();
            stack.pop();
            double b = stack.top();
            stack.pop();

            switch (c) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(b - a);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(b / a);
                    break;
            }
        } else {
            std::string operand = "";
            while (i < xpr.length() && xpr[i] >= '0' && xpr[i] <= '9' || xpr[i] == '.') {
                operand += xpr[i];
                i++;
            }
            i--;
            stack.push(std::stod(operand));
        }
    }

    return stack.top();
}

int main() {
    std::cout << eval("5.2 2 x -") << std::endl;
    return 0;
}

