#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

double result(double a, double b, char c)
{
    if(c == '+'){
        return a + b;
    } else if(c == '-'){
        return a - b;
    } else if(c == '*'){
        return a * b;
    } else if(c == '/'){
        return a / b;
    }
    return pow(a, b);
}
double postfixToValue(vector<string> s)
{
    stack<double> stack;
    for (int i = 0; i < static_cast<int>(s.size()); i++){
        if(isdigit(s[i][0])){
            stack.push(stod(s[i]));
        } else {
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();
            stack.push(result(a, b, s[i][0]));
        }
    }
    double value = stack.top();
    stack.pop();
    return value;
}

int main()
{
    vector<string> hauto = {"63", "24", "+", "5", "*"};
    cout << postfixToValue(hauto);
}