#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expr) {
    stack<char> s;

    for(int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if(ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']') {
            if(s.empty()) {
                return false;
            }

            char top = s.top();
            s.pop();

            if((ch == ')' && top != '(') ||
               (ch == '}' && top != '{') ||
               (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return s.empty();
}

int main() {
    cout << "--- Parenthesis Matching Stack ---" << endl;
    string expr1 = "{[()]}";
    string expr2 = "([)]";

    cout << "Expression 1: " << expr1 << " -> ";
    if(isBalanced(expr1)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }
    
    cout << "Expression 2: " << expr2 << " -> ";
    if(isBalanced(expr2)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}