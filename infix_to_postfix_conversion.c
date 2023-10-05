//Code to convert any infix expression into a postfix expression using stack in C language 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPRESSION_SIZE 100

struct Stack {
    int top;
    char items[MAX_STACK_SIZE];
};

void push(struct Stack *s, char c) {
    if (s->top == MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++s->top] = c;
}

char pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

char peek(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[s->top];
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    else
        return -1;
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infix_to_postfix(char *infix, char *postfix) {
    struct Stack s;
    s.top = -1;
    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        else if (is_operator(infix[i])) {
            while (s.top != -1 && precedence(infix[i]) <= precedence(peek(&s))) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
        else if (infix[i] == '(') {
            push(&s, infix[i]);
        }
        else if (infix[i] == ')') {
            while (s.top != -1 && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            if (s.top == -1) {
                printf("Invalid Expression\n");
                exit(1);
            }
            pop(&s);
        }
    }
    while (s.top != -1) {
        if (peek(&s) == '(') {
            printf("Invalid Expression\n");
            exit(1);
        }
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main(void) {
    char infix[MAX_EXPRESSION_SIZE], postfix[MAX_EXPRESSION_SIZE];
    printf("Enter infix expression: ");
    fgets(infix, MAX_EXPRESSION_SIZE, stdin);
    infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
