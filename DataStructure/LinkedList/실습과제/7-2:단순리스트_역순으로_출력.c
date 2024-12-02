// 단순연결 리스트를 역순으로 생성하여 출력하는 프로그램을 작성하시오.
// (1) 50,40,30,20,10  데이터가 저장된 노드를 연결리스트로 생성 하시오.
//   Node* insertFirst(Node* head);

// (2) 연결 리스트를 head부터 순서대로  출력하시오.

// (3) 연결리스트를 역순으로 생성하는 함수를 작성하시오. 
//   Node* reverse(Node* head);

// (4) 역순으로 생성된 연결리스트를 출력하시오.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;

void printList(Node *head){
	Node* p = head;//
  while(p != NULL) {
		printf("%d", p->data);
		if(p->next!=NULL) printf("->");
		p=p->next;
	}
	printf("\n");
}
Node* reverse(Node *head){
	Node *p,*q, *r;
	p = head;
	q = NULL;
  // 연결 리스트를 역순으로 연결하는 함수 작성
	while(p != NULL) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
}
// 첫번째 노드로 삽입하는 연산
Node*  insertFirst(Node *head, int data ){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = head;
	return newNode;
}

int main(){
	Node* head = NULL ;
	for(int i=10;i<=50;i+=10){
		head = insertFirst(head, i);
		printList( head );
	}
	head = reverse(head);//역순으로 연결하는 함수 호출
	printf("역순으로 출력\n");
	printList( head );	
	return 0;
}
