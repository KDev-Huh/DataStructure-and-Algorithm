// ADT(추상데이터타입) Stack

// object : 0개 이상의 원소를 가지는 유한 순서 리스트

// public 
//          - push( data ) : 스택이 full이 아닐 때 data를 스택에 삽입

//          - pop( ) : 스택이 empty가 아닐 때 top의 data를 반환 후 제거

//          - isFull( ) : 스택이 가득 차 있는가?

//          - isEmpty() : 스택이 공백상태인가?

//          - peek() : 스택의 원소 출력(반환)

// 실습 내용
// 1. 스택을 구조체 변수로 정의하여 구현하는 프로그램을 작성하시오.
// 1) 변수 및 구조체 정의
//  typedef int element;    // int를 element자료형으로 재정의

// typedef struct{
//      int  top;
//     element  data[MAX_STACK_SIZE];
// } Stack;

// 2) 구조체 변수 선언 : Stack  s;

// 3) 구현함수
// void initStack(); //스택 top 변수 초기화
// init isEmpty(); //스택이 비어있는지 true,false로 return
// init  isFull(); //스택이 가득찼는지 true,false로 return
// void push(element item); //스택에 데이터 삽입
// element pop(); // //스택 데이터 반환후 삭제
// element peek();  //스택 데이터 반환

// 3) 스택의 공백 조건 :   top == -1
// 4) 스택의 오버플로 조건: top == stack_size-1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 100

// 스택 초기화하는 방법은 top의 값을 변경해주어야 한다.

typedef int element;

//int를 element로 재정의
//문제) 스택 구조체 변수 정의 
typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
}Stack;
//문제) 전역변수로 스택 구조체 선언선언
Stack s;
void initStack(){
	 s.top = -1;
}
bool isEmpty(){
	return s.top == -1;
}
bool isFull(){
	return s.top + 1 == MAX_STACK_SIZE;
}	 
void push(element item){
	if(isFull())	return;
	s.data[++s.top] = item;
}
element pop(){ //반환후 제거
	if(isEmpty())	return 0;
	else return s.data[s.top--];
}
element peek(){//반환만
	if(isEmpty())	return 0;
	else return s.data[s.top];
}
int main(){
	initStack();
	push(1);
	push(2);
	push(3);
	printf("%d\n",pop());
	printf("%d\n",peek());
	printf("%d\n",pop());
	return 0;
}