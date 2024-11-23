// 덱의 연산들을 구현하시오.

//  - initDeque : 덱 초기화

//  - isEmpty : 공백 상태 검출

//  - isFull : 포화 상태 검출

//  - addFront : front 삽입 함수

//  - addRear : rear 삽입 함수

//  - deleteFront : front 삭제 함수

//  - deleteRear : rear 삭제 함수

//  - getFront : front get 함수

//  - getRear : rear get 함수



// 입출력 예시 : 명령어 입력 후 덱 연산

// 1 : front 삽입

// 2 : rear 삽입

// 3 : front 삭제

// 4 : rear 삭제

// 5 : front get

// 6 : rear get

// 7 : exit

#include <stdio.h>
#include <stdlib.h>

#define MAX_DEQUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_DEQUE_SIZE];
	int front, rear;
} DequeType;

// 오류 함수
void error(char *message) {
	puts(message);
	return;
}

// 초기화
void initDeque(DequeType* q) {
	
}

// 공백 상태 검출 함수
int isEmpty(DequeType* q) {
	
}

// 포화 상태 검출 함수
int isFull(DequeType* q) {
	
}

// 덱 출력 함수(원형 큐 출력과 동일)
void printDeque(DequeType* q){
	int i;
	printf("DEQUE(front=%d rear=%d) = ",q->front, q->rear);
	if (isEmpty(q)) {
		printf("덱은 공백상태입니다.\n");
		return;
	}
	 i = q->front;
	do{
		i = (i+1)% (MAX_DEQUE_SIZE);
		printf("%d | ",q->data[i]);
		if(i == q->rear) break;
	}while(i!=q->front);
	printf("\n");
}

// front 삽입 함수
void addFront(DequeType* q, element item) {
	
}

// rear 삽입 함수
void addRear(DequeType* q, element item) {
	
}

// front 삭제 함수
element deleteFront(DequeType* q) {
	
}

// rear 삭제 함수
element deleteRear(DequeType* q) {
	
}

// front get 함수
element getFront(DequeType* q) {
	
}

// rear get 함수
element getRear(DequeType* q) {
	
}

int main() {
	DequeType deque;
	int command;
	element idata;
	
	initDeque(&deque);
	while(1) {
		printf("명령어 입력\n1: front 삽입   2: rear 삽입   3: front 삭제   4: rear 삭제   5: front get   6: rear get   7: exit\n");
		scanf("%d",&command);
		switch(command) {
			case 1:
				printf("삽입할 데이터 입력 : ");
				scanf("%d",&idata);
				addFront(&deque,idata);
				printDeque(&deque);
				break;
			case 2:
				printf("삽입할 데이터 입력 : ");
				scanf("%d",&idata);
				addRear(&deque,idata);
				printDeque(&deque);
				break;
			case 3:
				printf("삭제한 데이터 : %d\n",deleteFront(&deque));
				printDeque(&deque);
				break;
			case 4:
				printf("삭제한 데이터 : %d\n",deleteRear(&deque));
				printDeque(&deque);
				break;
			case 5:
				printf("얻은 데이터 : %d\n",getFront(&deque));
				printDeque(&deque);
				break;
			case 6:
				printf("얻은 데이터 : %d\n",getRear(&deque));
				printDeque(&deque);
				break;
			case 7:
				return 0;
		}
		printf("\n");
	}
	
	return 0;
}