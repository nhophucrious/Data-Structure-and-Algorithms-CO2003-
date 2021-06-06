//Remove duplicate character from a given string
#include<iostream>
#include<stack>
#include<string>
string removeDuplicates(string S){
    /*TODO*/
    stack<char>st;
    //iterate the string, then pushing each element 
    //into a stack, if the stack is empty or that
    // element is not now at top of stack => push that
    // element to stack 
    // if not => pop top element;
    for(auto x: S)
    {
        if(st.empty() == true || st.top()!=x)
        {   
            st.push(x);
        }
        else
        {   
            st.pop();
        }
    }
    string str1 ="", str2="";
    while(st.empty()==false)
    {
        char s = st.top();
        str1+=s;
        st.pop();
    }
    while(str1.empty() == false)
    {
        char s = str1.back();
        str2+=s;
        str1.pop_back();
    }
    return str2;
}
int main()
{
  cout << removeDuplicates("abbaca");
  return 0;
}
