// 구조체를 이용한 스택 구현

// 스택의 기본 연산을 위한 스택 구조체와 함수의 프로토 타입이 다음과 같다.
// 각각의 함수를 구현하라.

// typedef struct{
// 	element data[STACK_SIZE];
// 	int top;
// }Stack;

// void initStack( Stack *s );  //top = -1 초기화
// int isFull( Stack *s );
// int isEmpty( Stack *s );
// void Push( Stack *s, element data );
// int Pop( Stack *s );

//  스택의 공백 조건 :   top == -1
//  스택의 오버플로 조건: top ==stack_size-1


// [ 심화 ] 메인 함수를 수정하여, stack을 활용한 코드를 추가하시오.
// ex) 스택의 데이터 모두 출력하기 등
// 추가한 코드에 대한 설명을 주석으로 작성하여 제출하시오.

#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10
//Stack 구조체 구현

typedef int element;
typedef struct{
	element data[STACK_SIZE];
	int top;
}Stack;
int isFull( Stack *s );
int isEmpty( Stack *s );
void push( Stack *s, element data );
int pop( Stack *s );
void initStack(Stack* s );

int main(){
	int menu;
	element data ;
	Stack *s = malloc(sizeof(Stack));
	initStack( s );
	do{
		printf("1:push, 2:pop, 0:exit : ");
		scanf("%d", &menu);
		switch( menu ){
			case 1 :
				printf("데이터 입력 : ");
				//입력 
				scanf("%d", &data);
				//스택에 입력
				push(s, data);
				break;
			case 2 :
        data = pop(s);//스택에서 출력
        if( data )
				  printf("pop 데이터 : %d\n", data);
				break;
      case 0 :
        break;
			default :
				printf("잘못된 입력 입니다. \n");
				break;
		}
	}while( menu );
}

void initStack( Stack *s ){  // top 포인터를 -1로 초기화
	s -> top = -1;
}
int isFull( Stack *s ){   // 스택이 가득 차 있으면 true 리턴
	return s->top + 1 == STACK_SIZE;
}
int isEmpty( Stack *s ){   // 스택이 비어 있으면 true 리턴
	return s->top == -1;
}
void push( Stack *s, element data ){ //스택이 가득 차 있으면 문구 출력 후 리턴, 아니면 push
	if(isFull(s)) {
		printf("stack is full\n");
		return;
	}
	s->data[++(s->top)] = data;
}
element pop( Stack *s ){  //스택이 비어  있으면 문구 출력 후 0 리턴, 아니면 맨 위 데이터 리턴
	if(isEmpty(s)) {
		printf("stack is empty\n");
		return 0;
	}
	return s->data[(s->top)--];
}