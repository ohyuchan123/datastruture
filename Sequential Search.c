#include <stdio.h>
#pragma warning(disable: 4996);
int sequentialSearch(int dataArr[], int length, int findData) 
{
	for (int i = 0; i < length; i++)
	{
		if (dataArr[i] == findData)
		{
			return i;
		}
	}
	return -1;
}
int main() {
	int arr[] = {23, 25, 14, 5, 66, 72, 13, 224, 51};
	int size = sizeof(arr) / sizeof(arr[0]);
	int findData = 0;
	int i = 0;
	while (1) 
	{ 
		printf("찾으시는 데이터를 입력해주세요: ");
		scanf("%d", &findData);
		i = sequentialSearch(arr, size, findData);
		if (i == -1)
		{
			printf("데이터를 찾지 못했습니다.\n");
		}
		else
		{
			printf("데이터는 %d번째에 있습니다.\n", i);
		}	
	}
	return 0;
}

