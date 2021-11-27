#include <stdio.h>
#pragma warning(disable: 4996);
int BinarySearch(int dataArr[], int size, int findData) 
{
	int low = 0, high = size - 1, mid; 
	while (low <= high) {
		mid = (low + high) / 2;
		if (dataArr[mid] > findData)
		{
			high = mid - 1;
		}
		else if (dataArr[mid] < findData)
		{
			low = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
} 
int main() 
{ 
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
		11, 12, 13, 14, 15, 17, 21, 24, 26, 27, 28};
	int size = sizeof(arr) / sizeof(arr[0]);
	int i, ret; 
	while (1) { 
		scanf("%d", &i);
		ret = BinarySearch(arr, size, i);
		if (ret != -1) 
			printf("찾으려는 데이터는 %d번째에 있습니다.\n", ret + 1);
		else 
			printf("데이터를 찾을 수 없습니다.\n");
	} 
	return 0;
}

