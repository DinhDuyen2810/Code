#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
int checkVar(char s){
    switch (s)
    {
        case '+' : case '-' : return 4;
        case '*' : case '/' : case '%' : return 5;
        case '^' : return 6;
    }
    return 1;
}
vector<string> infixToPostfix(string s)
{
    vector<string> arr;
    int n = s.length(), j = 0;
    stack<char> stack;
    while(j != n){
        char a = s[j];
        if(isdigit(a) || isalpha(a)){
            if(isdigit(a)){
                int sum = a - '0';
                a = s[j + 1];
                while(isdigit(a)){
                    sum = sum * 10 + (a - '0');
                    j++;
                    a = s[j + 1];
                }
                arr.push_back(to_string(sum));
                j++;
            } else {
                arr.push_back(string(1, a));
                j++;
            }
        } else if(stack.empty() || a == '('){
            stack.push(a);
            j++;
        } else if(a == ')') {
            do{
                if(a != '('){
                    arr.push_back(string(1, stack.top()));
                    stack.pop();
                }
            } while (stack.top() != '(');
            j++;
            stack.pop();
        } else {
            while(!stack.empty() && checkVar(stack.top()) >= checkVar(a)){
                if(a == '^'){
                    break;
                }
                arr.push_back(string(1, stack.top()));
                stack.pop();
            }
            stack.push(a);
            j++;
        }
        if(j == n){
            while(!stack.empty()){
                arr.push_back(string(1, stack.top()));
                stack.pop();
            }
        }
    }
    return arr;
}

int main() {
    string s;
    cin >> s;
    vector<string> arr = infixToPostfix(s);
    for (int j = 0; j < static_cast<int>(arr.size()); j++) {
        cout << arr[j] << " ";
    }
}
