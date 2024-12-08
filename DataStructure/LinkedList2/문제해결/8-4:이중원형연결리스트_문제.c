// 문제
// 1번부터 N번까지 N개의 풍선이 원형으로 놓여 있고. i번 풍선의 오른쪽에는 i+1번 풍선이 있고, 왼쪽에는 i-1번 풍선이 있다. 단, 1번 풍선의 왼쪽에 N번 풍선이 있고, N번 풍선의 오른쪽에 1번 풍선이 있다. 각 풍선 안에는 종이가 하나 들어있고, 종이에는 -N보다 크거나 같고, N보다 작거나 같은 정수가 하나 적혀있다. 이 풍선들을 다음과 같은 규칙으로 터뜨린다.

// 우선, 제일 처음에는 1번 풍선을 터뜨린다. 다음에는 풍선 안에 있는 종이를 꺼내어 그 종이에 적혀있는 값만큼 이동하여 다음 풍선을 터뜨린다. 양수가 적혀 있을 경우에는 오른쪽으로, 음수가 적혀 있을 때는 왼쪽으로 이동한다. 이동할 때에는 이미 터진 풍선은 빼고 이동한다.

// 예를 들어 다섯 개의 풍선 안에 차례로 3, 2, 1, -3, -1이 적혀 있었다고 하자. 이 경우 3이 적혀 있는 1번 풍선, -3이 적혀 있는 4번 풍선, -1이 적혀 있는 5번 풍선, 1이 적혀 있는 3번 풍선, 2가 적혀 있는 2번 풍선의 순서대로 터지게 된다.

// 입력
// 첫째 줄에 자연수 N(1 ≤ N ≤ 1,000)이 주어진다. 다음 줄에는 차례로 각 풍선 안의 종이에 적혀 있는 수가 주어진다. 종이에 0은 적혀있지 않다.

// 출력
// 첫째 줄에 터진 풍선의 번호를 차례로 나열한다.

// 예제 입력 1 
// 5
// 3 2 1 -3 -1
// 예제 출력 1 
// 1 4 5 3 2

#include <stdio.h>
#include <stdlib.h>
//이중연결 노드 구조체 정의
typedef struct DNode{
	int index;
	int data;
	struct DNode* next;
	struct DNode* prev;
}DNode;
//이중연결리스트 Head 구조체 정의
typedef struct head{
	int size;
	DNode* link;
}Head;

void insertLast(Head* head, int data);
void deleteNode(Head* head);
int main(){
	Head* head = (Head*)malloc(sizeof(head)); // 연결 리스트의 헤더 생성
	head->link = NULL;
	head->size = 0;
	// 원형 이중 연결 리스트 사이즈(풍선개수)를 입력
  int size,num;
	scanf("%d", &size);
  //숫자를 입력받아 리스트에 풍선노드 추가
	for (int i = 0; i < size; i++){
		scanf("%d", &num);
 		//리스트에 노드에 삽입 함수 호출
		insertLast(head, num);
	}
 for (int i = 0; i < size; i++){
		//리스트 노드 삭제
	 	deleteNode(head);
	}
	free(head->link);
	free(head);
  return 0;
}

void insertLast(Head* phead, int data)
{
	// 리스트에 새로 추가될 노드
	DNode* head = phead->link;
	DNode* newNode = (DNode*)malloc(sizeof(DNode));//동적할당
	newNode->data = data;
	newNode->index = phead->size+1; //리스트 크기 +1

	// 리스트 마지막 위치에 노드 삽입
	if (head == NULL){ //리스트에 최초삽입시 초기화
		phead->link = newNode; //;
		newNode->prev = newNode;//;
		newNode->next = newNode; //;
	}
	else{	
		newNode->prev = head->prev;  //(1)
    newNode->next = head; //(2)head
    head->prev->next = newNode;  //(3)
    head->prev = newNode;//       
		}
	// 리스트 사이즈를 증가시켜 인덱스로 활용
	phead->size++;
}

void deleteNode(Head* phead){
	DNode* head = phead->link; //
	int index = head->index; // / 풍선의 번호
	int count = head->data; //풍선 안에 들어 있는 숫자의 값
	printf("%d ", index);
	// 풍선이 하나 남아 있을 때 종료
	if (phead->size == 1){
		phead->size--;
		return;
	}
	// 삭제할 풍선을 가리키는 노드
	DNode* removed = head; // 삭제할 노드 주소 저장
	DNode* p = head; //순회할 시작 주소 저장
	if (count > 0){ //양수일때
		for (int i = 0; i < count; i++){
			p = p->next;//다음노드 방향으로 이동
			if (p == removed){//터트릴 풍선 skip
				p = p->next;
			}
		}
	}
	else
	{
		for (int i = 0; i < count * (-1); i++){
			p = p->prev; //음수일때 이전 노드 방향 이동
		 // 탐색 한 위치가 삭제할 노드이면  skip
			if (p == removed){
				p = p->prev;//
			}
		}
	}
	phead->link = p; //마지막 순회한 위치를 새로운 head 주소로 저장
	removed->prev->next = removed->next; //삭제할 다음노드와 연결
	removed->next->prev = removed->prev; //삭제할 이전노드와 연결  
  free(removed);
	phead->size--;
}
void printList(Head* phead){
	DNode* p = phead->link;
	do{
		printf("[%d] ->",p->data);
		p = p->next;	
	}while(p!=phead->link);
}