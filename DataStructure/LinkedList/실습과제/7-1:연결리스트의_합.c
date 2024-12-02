// 단순 연결리스트에 정수가 저장되어 있다. 연결 리스트에 있는 모든 노드의 데이터 값을 합한 결과를 출력하는 프로그램을 작성하시오.
// [출력]
// 노드의 개수 : 3
// 노드  #1 데이터 : 5
// 노드  #2 데이터 : 6
// 노드  #3 데이터 : 7
// 연결 리스트 데이터의 합 : 18

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node { 	// 노드 타입
	element data;
	struct Node *next;
} Node;
Node* insertFirst(Node *head, element value)
{
  	//(1)동적할당
	Node* newNode = (Node*)malloc(sizeof(Node));
		// (2) 값저장
	newNode->data=value;
	// 헤드 포인터의 값을 복사	//(3)
	newNode->next = head;
	// 헤드 포인터 변경		//(4)
	// 변경된 헤드 포인터 반환
	return newNode;
}

// 노드 pre 뒤에 새로운 노드 삽입
Node*  insert(Node *head,Node *pre, element value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data=value;
	if(head==NULL || pre==NULL) {
		newNode->next = NULL;
		head = newNode;
	}
	else {
		newNode->next = pre->next;
		pre->next = newNode;
	}
	return head;
}

Node* deleteFirst(Node *head)
{
	Node* removed = head;
	Node* newhead = removed->next;
	free(removed);
	return newhead;
}
// pre가 가리키는 노드의 다음 노드를 삭제한다. 
Node* delete(Node *head, Node *pre)
{
	if(head != NULL && pre != NULL) {
		Node* removed = pre->next;
		pre->next = removed->next;
		free(removed);
	}
	return head;
}

void printList(Node *head)
{
	Node* p = head;
	while(p != NULL) {
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL");
}
int getSum(Node *head)
{
	int sum = 0;

	//노드의 데이터를 더하는 코드 작성
	Node* p = head;
	while(p != NULL) {
		sum+=p->data;
		p = p->next;
	}
	return sum;
}


int main(void)
{
	Node *head = NULL; //;NULL로 초기화
	int count, data;

	printf("노드의 개수: ");
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		printf("노드 #%d 데이터: ", i+1);
		scanf("%d", &data);
		head = insertFirst(head, data);
		//head 에 insertFirst실행결과 저장
	}
	printf("\n연결 리스트 데이터의 합 : %d", getSum(head));
	return 0;
}