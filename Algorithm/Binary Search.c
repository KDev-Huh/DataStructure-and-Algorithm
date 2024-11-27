#include <stdio.h>
int count=0;
int arr[6] = {1, 2, 3, 4, 5, 6};

int find(int left, int right, int key) {
    int mid;
    if(left <= right) {
        count++;
        mid = (left + right) / 2;
        if(arr[mid] == key) return count;
        else if(arr[mid] > key) return find(left, mid-1, key);
        else return find(mid+1, right, key);
    }
    return -1;
}

int main() {
    int size = sizeof(arr)/sizeof(int);
    int n;
    
    scanf("%d", &n);
    
    int result = find(0, size-1, n);
    
    if(result == -1)
        printf("탐색실패");
    else
        printf("탐색성공 %d번", count);
    
    return 0;
}