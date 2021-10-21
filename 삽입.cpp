# include <stdio.h>
#pragma warning(disable:4996);
# define MAX_SIZE 5

// ���� ����
void insertion_sort(int list[], int n) {
    int i, j, key;

    // ���ؽ� 0�� �̹� ���ĵ� ������ �� �� �ִ�.
    for (i = 1; i < n; i++) {
        key = list[i]; // ���� ���Ե� ������ i��° ������ key ������ ����

        // ���� ���ĵ� �迭�� i-1�����̹Ƿ� i-1��°���� �������� �����Ѵ�.
        // j ���� ������ �ƴϾ�� �ǰ�
        // key ������ ���ĵ� �迭�� �ִ� ���� ũ�� j��°�� j+1��°�� �̵�
        for (j = i - 1; j >= 0 && list[j] > key; j--) {
            list[j + 1] = list[j]; // ���ڵ��� ���������� �̵�
        }

        list[j + 1] = key;
    }
}

void main() {
    int i;
    int n = MAX_SIZE;
    int list[5] = {5,3,1,4,2};

    // ���� ���� ����
    insertion_sort(list, n);

    // ���� ��� ���
    for (i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
}