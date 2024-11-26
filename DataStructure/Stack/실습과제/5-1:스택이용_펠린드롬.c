// 스택을 이용하여 문자열(대소문자를 구분하지 않음)이 입력되면 회문(palindrome)인지 검사하는 코드를 작성하여 제출하시오.
// 대소문자를 구분하지 않고 검사한다.

// 금지키워드 : strlen

#include <stdio.h>
#define MAX 100

typedef char element;
typedef struct{
	element data[MAX];
	int top;
}Stack;

void initStack(Stack *s){
//초기화코드
	s->top = -1;
}

int isFull(Stack *s){
 return s->top + 1 == MAX;
}

int empty(Stack *s){
 return s->top == -1;
}

void push(Stack* s, char c){
 if(isFull(s)) {
	 printf("stack is full\n");
	 return;
 }
 else
	s->data[++(s->top)] = c;
}

element pop(Stack *s){
 if(empty(s)){
  printf("stack is empty");
  return 0;
 }
	return s->data[(s->top)--];
}

int palindrome(char String[]){
	Stack* s = malloc(sizeof(Stack));
	
	for(int i = 0; String[i]; i++) {
		push(s, String[i]);
	}
	for(int i = 0; String[i]; i++) {
		if(pop(s) != String[i]) {
			return 0;
		}
	}
	return 1;
}

int main(void){
 char str[MAX];
 scanf("%s",str);

 if(palindrome(str))
  printf("TRUE");
 else
  printf("FALSE");
 return 0;
}