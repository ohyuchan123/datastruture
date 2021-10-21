# include <stdio.h>
#pragma warning(disable:4996);
# define MAX_SIZE 5

// 삽입 정렬
void insertion_sort(int list[], int n) {
    int i, j, key;

    // 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
    for (i = 1; i < n; i++) {
        key = list[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

        // 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
        // j 값은 음수가 아니어야 되고
        // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
        for (j = i - 1; j >= 0 && list[j] > key; j--) {
            list[j + 1] = list[j]; // 레코드의 오른쪽으로 이동
        }

        list[j + 1] = key;
    }
}

void main() {
    int i;
    int n = MAX_SIZE;
    int list[5] = {5,3,1,4,2};

    // 삽입 정렬 수행
    insertion_sort(list, n);

    // 정렬 결과 출력
    for (i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
}