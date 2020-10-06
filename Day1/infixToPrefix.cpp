#include<iostream>
using namespace std;

int tos, MaxSize;
char S[100];

void initStack(int size) {
    MaxSize = size;
    tos = -1;
    cout << "stack initialiized";
    cout << "\n" << MaxSize;
}

void push(char e) {
    tos++;
    S[tos] = e;
    cout << "In push. Entry in stack: " << S[tos] << endl;
}

int isFull() {
    if (tos == MaxSize - 1)
        return 1;
    else
        return 0;
}

char pop() {
    char temp = S[tos];
    tos--;
    return temp;
}

int isEmpty() {
    if (tos == -1)
        return 1;
    else
    {
        return 0;
    }
}

char atTop() {
    return S[tos];
}

void printStack() {
    int i;
    for (i = tos; i > -1; i--) {
        cout << S[i] << "\t";
    }
}

int preced(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}


int main()
{
    string infix;
    string pre = "";
    cout << "Enter Infix: ";
    cin >> infix;
    initStack(infix.length());

    for (int i = infix.length()-1 ; i >= 0 ; i--)    //right to left
    {
        cout << "i=" << i << endl;
        char ch = infix[i];
        switch (ch)
        {
        case ')':
            push(ch);
            break;
        case '(':
            while (S[tos] != ')')
            {
                pre += pop();
            }
            pop();
            break;
        case '+':
        case '-':
        case '*':
        case '/': //Both solutions are working
            /*if(preced(ch) > preced(S[tos]))
            {
                push(ch);
            }
            else
            {
                while (preced(ch)<preced(S[tos]) && isEmpty()!= 1)
                {
                    post += pop();
                }
                push(ch);
            }
            break;
            */
            while ((preced(ch) < preced(S[tos])) && (isEmpty() != 1))
            {
                cout << "s[tos] is : " << S[tos] << endl;
                pre += pop();
            }
            push(ch);
            break;
        default:
            pre += ch;
            break;
        }
        cout << "pre = " << pre << endl;
    }

    while (isEmpty() != 1)
    {
        pre += pop();
    }

    cout << endl << "Pre : " << pre << endl;

    reverse(pre.begin(), pre.end());
    cout << "prefix: " << pre << endl;

}