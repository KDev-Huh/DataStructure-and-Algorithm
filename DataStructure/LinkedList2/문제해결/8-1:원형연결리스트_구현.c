// 1. 원형연결리스트 개념: 
//   마지막 노드가 첫번째 노드를 가리키며 마지막노드의 링크가 첫번째 노드주소가 되는 리스트
// 2. 원형연결리스트의 변형  헤드포인터가 마지막노드를 가리키도록 정의한 경우 단 시간에 접근 가능
//  . 마지막위치: head주소
//  . 처음위치: head->next
//  3. 원형리스트 처음위치에 삽입
//   . 새로운 노드->next주소  = head->next주소
//   . head->next = 새로운 노드주소
// 4. 원형리스트 마지막(head위치) 에 삽입
//  . 새로운노드->next = head->next
//  . head->next = 새로운노드
//  . head 주소= 새로운노드주소

#include <stdio.h>
#include <stdlib.h>
typedef int element;
//0) Node구조체 작성
typedef struct {
	element data;
	struct Node* next;
} Node;

void printList(Node* head){
	Node *p = head->next; //1)처음위치부터 출력;
	if (head == NULL) return;
	do {
		if(p == NULL) break;
		//2)데이터 출력
		printf("%d->", p->data);
		//3)ptr을 다음 주소로 저장
		p = p->next;
	}while(p != head); //4)조건
  //5) 마지막 노드 출력
	printf("%d->", p->data);
	printf("\n");
}
Node* insertFirst(Node* head, element data){
	Node* node = (Node*)malloc(sizeof(Node));//Node 동적할당
	node->data = data;//
	if (head == NULL){
		head=node; // head의 주소로 새로운노드의 주소 저장
		node->next=head;//새로운노드의 다음 주소로 head 저장
	}
	else{
		node->next = head->next; //새로운노드의 다음 주소로 head 저장	 
		head->next = node; //head의 다음노드 주소로 새로운노드의 주소 저장
	}
	return head;
}
Node* insertLast(Node* head, element data){
	Node* node = (Node*)malloc(sizeof(Node));//노드 동적할당
	node->data =data;
	if (head == NULL){
		head= node; // head의 주소로 새로운노드의 주소 저장
		node->next= head; //새로운노드의 다음 주소로 head 저장
	}
	else{
		node->next = head->next;//
		head->next = node;//
		head =  node;//
	}
	return head;
}
int main() {
	Node *head=NULL;
	printf("처음위치에 연결\n");
	for(int i = 1;i< 5;i++){
		head = insertFirst(head, i); //첫위치에 삽잆하는 함수 호출	
	}
	printList(head);
	printf("마지막위치에 연결\n");
	for(int i = 11;i< 15;i++){
		head = insertLast(head, i); //마지막 위치에 삽입하는 함수 호출	
	}
	printList(head);

	return 0;
}