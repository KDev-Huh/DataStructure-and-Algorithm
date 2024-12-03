// N장의 카드가 있다. 각각의 카드는 차례로 1부터 N까지의 번호가 붙어 있으며, 1번 카드가 제일 위에, N번 카드가 제일 아래인 상태로 순서대로 카드가 놓여 있다.

// 이제 다음과 같은 동작을 카드가 한 장 남을 때까지 반복하게 된다. 우선, 제일 위에 있는 카드를 바닥에 버린다. 그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.

// 예를 들어 N=4인 경우를 생각해 보자. 카드는 제일 위에서부터 1234 의 순서로 놓여있다. 1을 버리면 234가 남는다. 여기서 2를 제일 아래로 옮기면 342가 된다. 3을 버리면 42가 되고, 4를 밑으로 옮기면 24가 된다. 마지막으로 2를 버리고 나면, 남는 카드는 4가 된다.

// N이 주어졌을 때, 버리는 단계마다 제일 위에 있는 카드부터 순서대로 출력하고, 제일 마지막에 남게 되는 카드를 구하는 프로그램을 원형 연결리스트를  이용하여 작성하시오.

// 입력
// 첫째 줄에 정수 N(1 ≤ N ≤ 500,000)이 주어진다.

// 출력
// 카드를 버리는 단계마다 남아있는 카드를 제일 위에 있는 카드부터 순서대로 출력하고, 제일 마지막에 남게되는 카드의 번호를 출력한다.

#include <stdio.h> 
#include <stdlib.h>
typedef int element;
//0)노드 구조체 작성
typedef struct {
	element data;
	struct Node* next;
} Node;

void printList(Node* head){
	Node *p = head->next;//리스트의 첫위치 저장
	int count = 0;
	if (head == NULL) return;
	do {
		if(p == NULL || p == head) break;
		printf("%d->",p->data);
		p = p->next; //다음 노드값 저장
	 
 }while(p != head);//p의 값이 첫위치가 아니면
 //}while(cnt <10);
	printf("%d->", p->data);
	printf("\n");
}
void insertFirst(Node* head, element data){
	Node* node = (Node*)malloc(sizeof(Node));//새노드 동적할당
	node->data = data;//
	if (head == NULL){//리스트에 노드가 없는경우
		head = node; //새로운 노드주소값
		head->next = head;//자신을 순환참조
	}
	else{
		node->next = head->next;//원래 리스트의 첫위치값
		head->next = node; //새로운 노드 주소값 	 
	}
	 
}
Node* insertLast(Node* head, element data){
	Node* node = (Node*)malloc(sizeof(Node));//새노드 동적할당
	node->data =data;
	if (head == NULL){
		head =  node;//새로운 노드주소값
		head->next = head;//자신을 순환참조
	}
	else{
		node->next = head->next;//리스트의 첫 위치
		head->next = node;//새노드 주소
		head = node;//새로운 head 주소 리턴
	}
	return head;
}

Node* chageCard(Node* head){
	Node* removed = head->next; //노드삭제위치 저장
  head->next =  removed->next;//삭제된 다음 위치와 연결
	head = head->next;
	free(removed);
	return head; // 새로운 헤드값으로 리턴
}
int main() {
	Node *head =NULL, *p;
	int n  ;
	printf("카드개수 입력\n");
 	scanf("%d",&n);
//	printf("마지막위치에 연결\n");
	for(int i = 1;i <= n;i++){
		head = insertLast(head, i); //노드 삽입함수 호출
	}
//	printf("head노드 = %d\n",head->data);
	while(head->next != head){
		head = chageCard(head);//카드 제거함수 호출
		printList(head);
	}
	 printf("마지막 카드번호 : %d",head->data);
	return 0;
}
