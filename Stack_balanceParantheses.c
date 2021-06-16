// balanced parentheses
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
	s->top++;
	s->a[s->top] = c;
}

int pop(stack *s){
	int temp = s->top;
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
	int i,flag=-1,em=-1;
	char str[20],par;
	printf("Enter the string ");
	scanf("%[^\n]s",str);
	for(i=0;str[i] != '\0';i++){
		if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
			push(&s,str[i]);
		}
		else if(str[i] == ')' ){
			par = pop(&s);
			if(par != '('){
			//	printf("The parentheses are not balanced");
				printf("\nIn\n");
				flag++;
				break;
			}
		}
		else if(str[i] == ']'){
			par = pop(&s);
			if(par != '['){
			//	printf("The parentheses are not balanced");
				flag++;
				break;
			}
		}
		else if(str[i] == '}'){
			par = pop(&s);
			if(par != '{'){
			//	printf("The parentheses are not balanced");
				flag++;
				break;
			}
		}
	
	}
	if( isEmpty(&s) || flag != -1 ){
		printf("%d",isEmpty(&s));
		printf("The parentheses are not balanced");
		flag++;
		
	}
	if(flag == -1 ){
		printf("The parentheses are balanced");
	}
	

	return 0;
}

