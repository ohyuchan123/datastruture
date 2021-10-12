//��������Ʈ ���α׷�
#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996);
#define MAX 100 //�迭�� ũ��

int list[MAX] = { 0 };
int n = 0; //�������� ����

void print_header(); //���α׷� ����
void menu(); //�޴�
void insert(int num2); //����
void del(int num2); //����
void search(int num2); //Ž��
void print(); //���
void end(); //����

int main() {

    int num1 = 0;
    int num2 = 0;

    while (num1 != 5) {
        print_header();
        menu();

        printf("\n�޴��� �����ϼ���...");
        scanf_s("%d", &num1);


        // ���� ���� Ž�� ��� ���� switch�� Ȱ��
        switch (num1) {
        case 1:
            printf("�����͸� �Է��ϼ���...");
            scanf_s("%d", &num2);
            insert(num2);
            break;
        case 2:
            printf("�����͸� �Է��ϼ���...");
            scanf_s("%d", &num2);
            del(num2);
            break;
        case 3:
            printf("�����͸� �Է��ϼ���...");
            scanf_s("%d", &num2);
            search(num2);
            break;
        case 4:
            print();
            break;
        case 5:
            end();
            break;
        }
    }

    return 0;
}

void print_header() {
    printf("\n\n==================================================\n");
    printf(" \t��������Ʈ(Linear List) ���α׷�         \n");
    printf("==================================================\n\n");
    printf("\n");
}

void menu() {
    printf("\n==========================================\n\n");
    printf(" \t\t1. ���� \n");
    printf(" \t\t2. ���� \n");
    printf(" \t\t3. Ž�� \n");
    printf(" \t\t4. ��� \n");
    printf(" \t\t5. ���� \n\n");
    printf("==========================================\n\n");

}

void insert(int num2) {
    //�������α׷�
    //�ϳ��� �Է¹޾� �迭�� ũ���� ����
    int i, j, k = 0;

    //�迭�� �� ���ִ��� ����ִ��� Ȯ�� �� ERROR ��
    //������ �����͸� �����Ϸ��� �� ERROR ���
    if (n == MAX) {
        printf("ERROR!! �� �̻� ���ڸ� ���� �� �����ϴ�.\n\n");
        system("PAUSE");
        system("cls");
        return;
    }
    for (i = 0; i < n; i++) {
        if (list[i] == num2) {
            printf("ERROR!! ���� �����̹Ƿ� ���� �� �����ϴ�.\n\n");
            system("PAUSE");
            system("cls");
            return;
        }
    }
    //0��°�� 1��°�� ������ ���� �ְ�, �� �Ŀ� �޴� �����ʹ� ũ�⸦ �����Ͽ� ���� 
    switch (n) {
    case 0:
        list[0] = num2;
        n++;
        system("cls");
        return;
    case 1:
        if (num2 < list[0]) {
            list[1] = list[0];
            list[0] = num2;
            n++;
            system("cls");
            return;
        }
        else {
            list[1] = num2;
            n++;
            system("cls");
            return;
        }
    default:
        for (i = 0; i < n; i++) {
            if (list[i] < num2 && num2 < list[i + 1]) {
                for (j = n; j > i + 1; j--) {
                    list[j] = list[j - 1];
                }
                list[i + 1] = num2;
                n++;
                system("cls");
                return;
            }
            else if (num2 < list[i]) {
                for (j = n; j >= i + 1; j--) {
                    list[j] = list[j - 1];
                }
                list[i] = num2;
                n++;
                system("cls");
                return;
            }
        }
        if (num2 > list[n - 1]) {
            list[n] = num2;
            n++;
            system("cls");
            return;
        }
        break;
    }
}
void del(int num2){
    //���� ���α׷�

    int cnt = 0;
    int i, j = 0;

    //���� �迭�� ����ִ��� Ȯ�� �� ����ִٸ� ERROR ���
    if (n == 0) {
        printf("ERROR!! �迭�� ����ֽ��ϴ�.\n\n");
        system("PAUSE");
        system("cls");
        return;
    }
    //������ �� �˻�, �����Ͱ� �迭�� ������ ����, ������ ERROR ���
    for (i = 0; i < n; i++) {
        if (list[i] == num2) {
            list[i] = 0;
            n--;
            for (j = i; j < n; j++) {
                list[j] = list[j + 1];
            }
            printf("�����Ǿ����ϴ�.\n\n");
            system("PAUSE");
            system("cls");
            return;
        }
        cnt++;
    }
    if (cnt == n) {
        printf("ERROR!! �� �����Ͱ� �迭�� ������� �ʽ��ϴ�.\n\n");
        system("PAUSE");
        system("cls");
        return;
    }
}

void search(int num2) {
    //Ž�� ���α׷�
    //Ư�� ������ �� ã�� �迭�� ������ ��� ��ġ�� �ִ��� ���,
    //������ ERROR �޼��� ���
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (list[i] == num2) {
            printf("%d�� �迭 list[%d]�� ����ֽ��ϴ�.\n\n", num2, i);
            system("PAUSE");
            system("cls");
            return;
        }
        cnt++;
    }
    if (cnt == n) {
        printf("ERROR!! %d�� �迭�� ������� �ʽ��ϴ� !!\n\n", num2);
        system("PAUSE");
        system("cls");
        return;
    }
}

void print() {
    //��� ���α׷�
    printf("\n���� ����Ʈ�� ������ ������ �� %d���̸�, ���ҵ��� ������ ����.\n\n", n);

    for (int i = 0; i < n; i++) {
        printf("%d  ", list[i]);
    }
    printf("\n\n");
    system("PAUSE");
    system("cls");
    return;
}

void end() {
    //���� ���α׷�
    printf("\n\n==================================\n");
    printf("\t  ���Ḧ �����ϼ̽��ϴ�.\n");
    printf("==================================\n");

}
