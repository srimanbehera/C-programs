// infix to postfix
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>      	// for isalnum()
#include<string.h>

#define SIZE 100

typedef struct{
	int top;
	char a[SIZE];
}stack;
stack s;

void createStack(stack *s){
	s->top = -1;
}

void push(stack *s,char c){
	if(isFull(&s)){
		printf("Stack is full !");
		exit(1);
	}
	s->top++;
	s->a[s->top] = c;
}

int pop(stack *s){
	int temp;
	if(isEmpty(&s)){
		printf("Stack is empty!");
		exit(1);
	}
	temp = s->top;
	s->top--;
	return s->a[temp];
}

int precedence(char c){
	if(c == '('){
		return -1;
	}
	else if(c == '+' || c == '-'){
		return 1;
	}
	else if(c == '/' || c == '*'){
		return 2;		
	}
	else if(c == '^'){
		return 3;
	}
}
int isEmpty(stack *s){
	if(s->top == -1){
		return 1;
	}
	return 0;
}

int isFull(stack *s){
	if(s->top == SIZE -1){
		return 1;
	}
	return 0;
}

int main(){
	char exp[20],post[20];
	char *e,x;
	int i = 0;
	read:printf("Enter the infix expression ");
	scanf("%[^\n]s",exp);
//	if(strlen(exp) == 0){
//		printf("\nEnter the expression again\n");
//		goto read;
//	}
	e = exp;
	createStack(&s);
	while(*e != '\0'){
		if(isalnum(*e)){
			post[i] = *e;
			i++;
		}
		else if(*e == '('){
			push(&s,*e);
		}
		else if(*e == ')'){
			while((x = pop(&s)) != '(' ){
				post[i] = x;
				i++;
			}
		}	
		else{
			while(precedence(s.a[s.top]) >= precedence(*e)){
				post[i] = pop(&s);
				i++;
			}
			push(&s,*e);
		}	
		e++;
	}
	while(s.top != -1){
		post[i] = pop(&s);
		i++;
	}
	post[i] = '\0';
	printf("\nPostfx String: %s",post);
	return 0;
}

