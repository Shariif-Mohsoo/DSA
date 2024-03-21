#include <iostream>
using namespace std;
int top = -1;
char stack[0];
void push(char i)
{
    top++;
    stack[top] = i;
}
char pop()
{
    char res;
    if (top == -1)
    {
        cout << "The stack is empty " << endl;
    }
    else
    {
        res = stack[top];
        top--;
    }
    return res;
}
int main()
{
    char exp[20] = "ab+";
    // cout << exp << endl;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        cout << exp[i] << endl;
        if (exp[i] >= 'A' & exp[i] <= 'Z' || exp[i] >= 'a' & exp[i] <= 'z')
        {
            push(exp[i]);
        }
        else
        {
            char opt = exp[i];
            char A = pop();
            char B = pop();
            cout << B << opt << A << endl;
        }
    }
    return 0;
}