#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char op;
    int a, b, status;

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        int result;

        switch(op)
        {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;

            case '/':
                if (b == 0)
                {
                    printf("Division by zero!\n");
                    exit(1);
                }
                result = a / b;
                break;

            default:
                printf("Invalid operator!\n");
                exit(1);
        }

        printf("Child: Result = %d\n", result);
        exit(0);
    }
    else
    {
        waitpid(pid, &status, 0);

        if (WIFEXITED(status))
        {
            printf("Parent: Child terminated successfully.\n");
        }
    }

    return 0;
}