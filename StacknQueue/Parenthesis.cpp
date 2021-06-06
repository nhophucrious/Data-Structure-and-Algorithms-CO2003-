#include<iostream>
#include<stack>
using namespace std;


bool isValidParentheses (string s){
    stack<char>ss;
    char x;
    for(int i = 0; i < (int)s.length(); i++)
    {
        if(s[i] == '{' || s[i] == '('||s[i] == '[')
        {
            ss.push(s[i]);
            continue;
        }
        if(ss.empty()== true)
            return false;
        switch(s[i])
        {
            case ')':
            {
                x = ss.top();
                ss.pop();
                if(x=='[' || x =='{')
                    return false;
                break;
            }
            case '}':
            {
                x = ss.top();
                ss.pop();
                if(x=='[' || x =='(')
                    return false;
                break;
            }
            case ']':
            {
                x = ss.top();
                ss.pop();
                if(x == '{' || x =='(')
                {
                    return false;
                }
                break;
            }
        }
    }
    if(ss.empty() == true)
        return true;
    else
        return false;
}

int main()
{
   return 0;
}
