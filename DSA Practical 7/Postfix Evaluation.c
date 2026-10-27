#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[100];
    int i, V1, V2, result;
    printf("Enter postfix expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit((unsigned char)exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            V2 = pop();
            V1 = pop();
            switch (exp[i])
            {
            case '+':
                result = V1 + V2;
                break;

            case '-':
                result = V1 - V2;
                break;

            case '*':
                result = V1 * V2;
                break;

            case '/':
                result = V1 / V2;
                break;

            default:
                printf("Invalid operator!\n");
                return 1;
            }
            push(result);
        }
    }
    printf("Result = %d\n", pop());
    
    return 0;
}
