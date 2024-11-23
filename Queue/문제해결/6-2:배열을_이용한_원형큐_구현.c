// 배열을 이용하여 원형 큐를 구현하시오.

// --데이터추가단계--
// 정수를입력하시오.1
// QUEUE(front=0rear=1)=1|
// 정수를입력하시오.2
// QUEUE(front=0rear=2)=1|2|
// 정수를입력하시오.3
// QUEUE(front=0rear=3)=1|2|3|
// 정수를입력하시오.4
// QUEUE(front=0rear=4)=1|2|3|4|
// 큐는포화상태입니다.

// --데이터삭제단계--
// 꺼내진정수:1
// QUEUE(front=1rear=4)=2|3|4|
// 꺼내진정수:2
// QUEUE(front=2rear=4)=3|4|
// 꺼내진정수:3
// QUEUE(front=3rear=4)=4|
// 꺼내진정수:4
// QUEUE(front=4rear=4)=큐는공백상태입니다.

#include<stdlib.h>
#include <stdio.h>
#define MAX_Q_SIZE 5
typedef int element;
typedef struct{
	int rear;
	int front;
	element data[MAX_Q_SIZE];
}Queue;

void error(char* message){
	printf("%s\n",message);
	exit(0);//메인함수 종료
}

void initQueue(Queue* q){
	//front, rear 초기화
	q->front = 0;
	q->rear = 0;
}
int isEmpty(Queue* q){
	 return q->front == q->rear ? 1 : 0;
}
int isFull(Queue* q){
	return q->front == (q->rear+1)%MAX_Q_SIZE ? 1 : 0;
}
void enQueue(Queue* q, element item){
	if (isFull(q)) error("큐가 포화상태입니다.\n");
	else{
		q->data[(++q->rear)%MAX_Q_SIZE] = item;
	}//코드작성
}
element deQueue(Queue* q){
	if(isEmpty(q)) error("큐는 공백상태입니다.\n");
	else{
		return q->data[++q->front];
	}//코드작성
	
}

element peek(Queue* q){

}

void printQueue(Queue* q){
	int i;
	printf("QUEUE(front=%d rear=%d) = ",q->front, q->rear);
	if (isEmpty(q)) {
		printf("큐는 공백상태입니다.\n");
		return;
	}
	 i = q->front;
	do{
		i = (i+1)% (MAX_Q_SIZE);
		printf("%d | ",q->data[i]);
		if(i == q->rear) break;
	}while(i!=q->front);
	printf("\n");
}

int main() {
	Queue q;
	element item;
	initQueue(&q);
	printf("--데이터 추가 단계--\n");
	while (!isFull(&q)){
		printf("정수를 입력하시오.");
		scanf("%d",&item);
		enQueue(&q,item);
		printQueue(&q);
	}
	printf("큐는 포화상태입니다.\n\n");
	printf("--데이터 삭제 단계--\n");
	while(!isEmpty(&q)){
		item = deQueue(&q);
		printf("꺼내진 정수 : %d\n",item);
		printQueue(&q);
	}
	printf("큐는 공백상태입니다.\n\n");
	
	return 0;
}
