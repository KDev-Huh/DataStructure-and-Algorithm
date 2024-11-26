// ADT(추상데이터타입) Queue

// 0개 이상의 원소를 가지는 유한 순서 리스트

// ADT 목록
//          - initQueue(q) : 큐의 rear, front값을 초기 값으로 설정

//          - isFull( ) : 큐가 가득 차 있는가?

//          - isEmpty( ) : 큐가 공백상태인가?

//          - enQueue() : 큐의 끝에 원소를 추가한다.

//          - deQueue() : 큐의 맨 앞의 원소를 제거하여 반환한다.

#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 5
typedef int element;
//Queue 구조체 정의
typedef struct {
	int front;
	int rear;
	element data[MAX_Q_SIZE];
}Queue;
void error(char* message){
	printf("%s\n",message);
	exit(0);//메인함수 종료
}
void initQueue(Queue* q){
	q->front = -1;
	q->rear = -1;
}
int isFull(Queue* q){
	return q->rear == MAX_Q_SIZE ? 1 : 0;
}
int isEmpty(Queue* q){
	return q->rear == q->front ? 1 : 0;
}
void enQueue(Queue* q,element item){
	if(isFull(q)) error("큐가 다 찼습니다.");
	else q->data[++(q->rear)] = item;
}
element deQueue(Queue* q){
	if(isEmpty(q)) error("큐가 비어있습니다.");
	else ++(q->front);
}
void queuePrint(Queue* q){
	int i;
	for(i=0;i<MAX_Q_SIZE;i++){
		if (i<=q->front || i > q->rear){
			printf("%7c",'|');
		}
		else{
			printf("%4d%3c",q->data[i],'|');
		 }
	}
	printf("\n");
}
int main() {
	element item = 0;
	Queue q;
	initQueue(&q);
	printf("\n");
	enQueue(&q,10); queuePrint(&q);
	enQueue(&q,20); queuePrint(&q);
	enQueue(&q,30); queuePrint(&q);
	item = deQueue(&q); queuePrint(&q);
	item = deQueue(&q); queuePrint(&q);
	return 0;
}