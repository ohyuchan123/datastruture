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
		printf("ã���ô� �����͸� �Է����ּ���: ");
		scanf("%d", &findData);
		i = sequentialSearch(arr, size, findData);
		if (i == -1)
		{
			printf("�����͸� ã�� ���߽��ϴ�.\n");
		}
		else
		{
			printf("�����ʹ� %d��°�� �ֽ��ϴ�.\n", i);
		}	
	}
	return 0;
}

