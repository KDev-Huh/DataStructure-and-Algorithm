// ArrayList 구현

// 배열을 이용연결리스트를 구현해 보자.
// 배열을 이용하여 연결리스트를 구현하면 순차적인 메모리 공간이 할당되므로, 리스트의 순차적 표현이라고도 한다.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100 //리스트의 최대크기
typedef int element;
typedef struct{
	element arrary[MAX];
	int size;
}ArrayList;
//배열리스트 구조체타입 정의
void init(ArrayList* L){ //배열리스트 초기화
  L->size = 0;
}
int isEmpty(ArrayList* L){
	  return L->size ? 0 : 1;
}
int isFull(ArrayList* L){
	 return L->size == MAX ? 1: 0;
}
element getEntry(ArrayList* L, int pos){
 	 return L->arrary[pos];
}
void printList(ArrayList* L){
	int i;
	for(i = 0; i < L->size; i++) {
		printf("%d->", L->arrary[i]);
	}
	printf("\n");
}
void insertLast(ArrayList* L, element item){
	if(isFull(L)) return;
	L->arrary[L->size++] = item;
}
void insert(ArrayList* L, int pos, element item){
	if(isFull(L)) return;
	for(int i = L->size; i >= pos; i--) {
		L->arrary[i+1] = L->arrary[i];
	}
	L->arrary[pos] = item;
	L->size++;
}
element delete(ArrayList* L,int pos){
	if(isEmpty(L))	return 0;
	for(int i = pos; i <= L->size; i++) {
		L->arrary[i] = L->arrary[i+1];
	}
	L->size--;
}
int main(){
	ArrayList list;
	init(&list);
	insertLast(&list,10);
	printList(&list);
	insertLast(&list,20);
	printList(&list);
	insertLast(&list,30);
	printList(&list);
	insertLast(&list,40);
	printList(&list);
	insert(&list, 2, 100);
	printList(&list);
	delete(&list, 1);
	printList(&list);

	return 0;
}