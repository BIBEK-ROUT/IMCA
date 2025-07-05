#include <stdio.h>

// Function to perform arithmetic operations
double calculate(double num1, double num2, char op) {
    double result;
    switch(op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 != 0)
                result = num1 / num2;
            else {
                printf("Error: Division by zero is not allowed.\n");
                result = 0; // or some error code
            }
            break;
        case '%':
            if((int)num2 != 0)
                result = (int)num1 % (int)num2;
            else {
                printf("Error: Modulo by zero is not allowed.\n");
                result = 0;
            }
            break;
        default:
            printf("Invalid operator.\n");
            result = 0;
    }
    return result;
}

int main() {
    double num1, num2, result;
    char op, choice;

    do {
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter an operator (+, -, *, /, %%): ");
        scanf(" %c", &op);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        result = calculate(num1, num2, op);
        printf("Result: %.2lf\n", result);

        printf("Do you want to perform another operation? (y/n): ");
        scanf(" %c", &choice);

    } while(choice == 'y' || choice == 'Y');

    printf("Thank you for using the calculator.\n");
    return 0;
}
