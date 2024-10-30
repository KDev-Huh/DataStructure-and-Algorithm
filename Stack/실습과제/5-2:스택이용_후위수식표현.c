// 우리가 일상 생활에서 사용하는 수학식은 대부분 중위 표기법이다.
// 중위 표기법은 어떠한 이항 연산에 대해 연산 대상 사이에 연산자를 표기하는 방식이다. 예를 들면
// 3+5∗7
// (6+9)∗8 등이 있다.

// 하지만 이런 중위 표기법은 연산자 우선 순위에 따라 괄호를 해야 한다는 단점이 있다.

// 이에 반해 후위 표기법은 두 피연산자를 먼저 쓰고 그 뒤에 연산자를 표기하는 방식이다.  위의 중위 표현을 예로 들면

// 357*+

// 69+8*

// 이다.

// 후위 표기법은 연산자의 순서가 곧 계산 순서이므로 괄호가 필요 없다는 장점이 있다.
// 후위 표기법으로 된 식을 입력 받아 계산 결과를 출력하는 프로그램을 스택을 이용하여 작성하시오.(교재 126~128 참고)

// 후위표기수식 계산 알고리즘
// 0. 문자열을 탐색
//   1. 피연산자(값)이면 push
//   2. 연산자이면  값2 =pop,값1 = pop
//   3.  결과 = 값1 연산  값2
//        push(결과) 


#include <stdio.h>
#include <stdlib.h>
#define MAX 300
typedef  int element;
typedef struct{
	element data[300];
	int top;
}Stack;
void initStack(Stack* s){
 s->top = -1;
}
int isEmpty(Stack* s){
	 return s->top == -1;
}
int isFull(Stack* s){
	 return s->top+1 == MAX;
}
void push(Stack* s, element c){
	if(isFull(s)) {
		printf("stack is full\n");
		return;
	}
	s->data[++(s->top)] = c;
}
element pop(Stack* s ){
	if(isEmpty(s)) {
		printf("stack is empty\n");
		return 0;
	}
	int d = s->data[(s->top)--];
	return d;
}
int main(){
	char expr[300];
	Stack* s = malloc(sizeof(Stack));
	
	fgets(expr, sizeof(expr), stdin);
	
	for(int i = 0; expr[i]; i++) {
		if(expr[i] >= '0' && expr[i] <= '9')
			push(s, (int)expr[i]-'0');
		else if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '%'){
			int result;
			int p1 = pop(s);
			int p2 = pop(s);
			switch(expr[i]) {
				case '+':
					result = p2 + p1;
					break;
				case '-':
					result = p2 - p1;
					break;
				case '*':
					result = p2 * p1;
					break;
				case '/':
					result = p2 / p1;
					break;
				case '%':
					result = p2 % p1;
					break;
			}
			push(s, result);
		}
	}
	printf("%d", pop(s));
	return 0;
}

