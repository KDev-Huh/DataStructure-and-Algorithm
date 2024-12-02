// 과일의 이름을 저장하는 단순 연결 리스트를 작성하고, 특정 단어를 탐색하는 코드를 작성하시오.

// melon->null
// kiwi->melon->null
// apple->kiwi->melon->null
// apple->melon->null
// melon을 찾았습니다.

#include <stdio.h>//201p(단어입력) + 203(탐색)
#include <stdlib.h>
#include<string.h>
typedef struct Node{
	char data[100];
	struct Node* next;
}Node;
Node* insertFirst(Node* head, char* data){
	Node * newNode = (Node *)malloc(sizeof(Node));
	strcpy(newNode->data, data);
	newNode->next = head;
	return newNode;
}
Node* insert(Node* head, Node* pre, char* data){
	Node * newNode = (Node *)malloc(sizeof(Node));
	if(head == NULL || pre == NULL) {
		newNode->next = NULL;
		head = newNode;
	}
	else {
		newNode->next = pre->next;
		pre->next = newNode;
	}
	return head;
}
Node* deleteFirst(Node* head){
	if(head==NULL) return NULL;
	Node* removed = head;
	Node* newhead = head->next;
	free(removed);
	return newhead;
}
Node* delete(Node* head, Node* pre){
	//프리가 가리키는 다음 노드를 삭제
	if(head != NULL || pre != NULL) {
		Node* removed = pre->next;
		pre->next = removed;
		free(removed);
	}
	return head;
}
void printList(Node* head){

	while(head!=NULL){
		printf("%s->", head->data);
		head = head->next;
	}
	printf("NULL\n");
}
int main(){
	Node* head = NULL;
	Node* p;
  char str[3][10] ={"melon","kiwi","apple"};
	char find[10];
	//코드 작성
	head= insertFirst(head,str[0]); //melon 입력
	printList(head);
	head= insertFirst(head,str[1]);
	printList(head);
	head= insertFirst(head,str[2]);
	printList(head);
	printf("찾을 데이터를 입력하세요\n");
	scanf("%s",find);
	for(p=head;p!=NULL;p=p->next){
		//printf("%s",p->data);
		if	(strcmp(p->data,find) == 0) printf("%s을 찾았습니다.",find);
		
	}
	return 0;
}