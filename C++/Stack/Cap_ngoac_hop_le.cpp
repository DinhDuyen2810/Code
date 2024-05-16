#include <iostream>
#include <stack>
#include <string>
using namespace std;
int checkVar(char c)
{
    switch (c)
    {
    case '(' : case ')' : return 1;
    case '[' : case ']' : return 2;
    case '{' : case '}' : return 3;
    }
    return 0;
}
int main()
{
    stack<char> stack;
    string s;
    cin >> s;
    int n = s.length();
    for(int i = 0; i < n; i++){
        char a = s[i];
        if(!stack.empty() && checkVar(a) == checkVar(stack.top())){
            stack.pop();
        } else {
            stack.push(a);
        }
    }
    if(stack.empty()){
        cout << "true";
    } else {
        cout << "false";
    }
}