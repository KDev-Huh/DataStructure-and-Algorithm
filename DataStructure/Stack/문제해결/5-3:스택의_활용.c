// 스택의 기본함수를 구현하고, 문자열을 입력 받아 거꾸로 출력하도록 메인 함수를 작성하여 제출하시오.

// typedef struct{
// 	element data[STACK_SIZE];
// 	int top;
// }Stack;

#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20

//스택 구조체 작성
typedef char element;
typedef struct{
	element data[STACK_SIZE];
	int top;
}Stack;

void initStack( Stack *s );
int isFull( Stack *s );
int isEmpty( Stack *s );
void push( Stack *s, element data );
element pop( Stack *s );

int main(){
	int i;
 	Stack* s = malloc(sizeof(Stack));
	char str[20];
	printf("문자열 입력 : ");
	scanf("%s", str);
	//문자열을 입력받아 거꾸로 출력
	for(int i = 0; str[i]; i++) {
		push(s, str[i]);
	}
	while(!isEmpty(s)){
		printf("%c", pop(s));
	}
}

void initStack( Stack *s ){
	 s->top = -1;
}
int isFull( Stack *s ){
	 return s->top + 1 == STACK_SIZE;
}
int isEmpty( Stack *s ){
	return s->top == -1;
}
void push( Stack *s, element c ){
	 if(isFull(s)) {
		 printf("stack is full\n");
		 return;
	 }
	s->data[++(s->top)] = c;
}
element pop( Stack *s ){
	 if(isEmpty(s)) {
		 printf("stack is empty");
		 return 0;
	 }
	return s->data[(s->top)--];
}