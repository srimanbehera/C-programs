// check whether pallindrome or not using stack
#include<stdio.h>
#define SIZE 100
typedef struct {
	int top;
	char a[SIZE];
}stack;

stack s;

void createStack(stack *s){
	s->top = -1;
}

void push(stack *s,char c){
	s->top = s->top + 1;
	s->a[s->top] = c;
}

int pop(stack *s){
	int temp;
	temp = s->top;
	s->top--;
	return s->a[temp];
}

int isEmpty(stack *s){
	if(s->top == -1){
		return 1;
	}
	return 0;
}

int main(){
	int i,flag=-1;
	char str[20],ch;
	createStack(&s);
	printf("Enter the string ");
	scanf("%[^\n]s",str);
	for(i=0;str[i] != '\0';i++){
		push(&s,str[i]);
	}
	for(i=0;str[i] != '\0' || !isEmpty(&s);i++){
		ch = pop(&s);
		if(ch != str[i]){
			flag++;
			printf("The string is not pallindrome");
			break;
		}
	}
	if(flag == -1){
		printf("The string is pallindrome");
	}

	return 0;
}

