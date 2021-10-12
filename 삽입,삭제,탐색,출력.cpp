//선형리스트 프로그램
#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996);
#define MAX 100 //배열의 크기

int list[MAX] = { 0 };
int n = 0; //데이터의 갯수

void print_header(); //프로그램 제목
void menu(); //메뉴
void insert(int num2); //삽입
void del(int num2); //삭제
void search(int num2); //탐색
void print(); //출력
void end(); //종료

int main() {

    int num1 = 0;
    int num2 = 0;

    while (num1 != 5) {
        print_header();
        menu();

        printf("\n메뉴를 선택하세요...");
        scanf_s("%d", &num1);


        // 삽입 삭제 탐색 출력 종료 switch문 활용
        switch (num1) {
        case 1:
            printf("데이터를 입력하세요...");
            scanf_s("%d", &num2);
            insert(num2);
            break;
        case 2:
            printf("데이터를 입력하세요...");
            scanf_s("%d", &num2);
            del(num2);
            break;
        case 3:
            printf("데이터를 입력하세요...");
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
    printf(" \t선형리스트(Linear List) 프로그램         \n");
    printf("==================================================\n\n");
    printf("\n");
}

void menu() {
    printf("\n==========================================\n\n");
    printf(" \t\t1. 삽입 \n");
    printf(" \t\t2. 삭제 \n");
    printf(" \t\t3. 탐색 \n");
    printf(" \t\t4. 출력 \n");
    printf(" \t\t5. 종료 \n\n");
    printf("==========================================\n\n");

}

void insert(int num2) {
    //삽입프로그램
    //하나씩 입력받아 배열에 크기대로 저장
    int i, j, k = 0;

    //배열이 꽉 차있는지 비어있는지 확인 후 ERROR 출
    //동일한 데이터를 삽입하려할 때 ERROR 출력
    if (n == MAX) {
        printf("ERROR!! 더 이상 숫자를 넣을 수 없습니다.\n\n");
        system("PAUSE");
        system("cls");
        return;
    }
    for (i = 0; i < n; i++) {
        if (list[i] == num2) {
            printf("ERROR!! 같은 숫자이므로 넣을 수 없습니다.\n\n");
            system("PAUSE");
            system("cls");
            return;
        }
    }
    //0번째와 1번째에 데이터 값을 넣고, 그 후에 받는 데이터는 크기를 구별하여 삽입 
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
    //삭제 프로그램

    int cnt = 0;
    int i, j = 0;

    //먼저 배열이 비어있는지 확인 후 비어있다면 ERROR 출력
    if (n == 0) {
        printf("ERROR!! 배열이 비어있습니다.\n\n");
        system("PAUSE");
        system("cls");
        return;
    }
    //데이터 값 검색, 데이터가 배열에 있으면 제거, 없으면 ERROR 출력
    for (i = 0; i < n; i++) {
        if (list[i] == num2) {
            list[i] = 0;
            n--;
            for (j = i; j < n; j++) {
                list[j] = list[j + 1];
            }
            printf("삭제되었습니다.\n\n");
            system("PAUSE");
            system("cls");
            return;
        }
        cnt++;
    }
    if (cnt == n) {
        printf("ERROR!! 이 데이터가 배열에 들어있지 않습니다.\n\n");
        system("PAUSE");
        system("cls");
        return;
    }
}

void search(int num2) {
    //탐색 프로그램
    //특정 데이터 값 찾고 배열에 있으면 어느 위치에 있는지 출력,
    //없으면 ERROR 메세지 출력
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (list[i] == num2) {
            printf("%d는 배열 list[%d]에 들어있습니다.\n\n", num2, i);
            system("PAUSE");
            system("cls");
            return;
        }
        cnt++;
    }
    if (cnt == n) {
        printf("ERROR!! %d는 배열에 들어있지 않습니다 !!\n\n", num2);
        system("PAUSE");
        system("cls");
        return;
    }
}

void print() {
    //출력 프로그램
    printf("\n선형 리스트의 데이터 갯수는 총 %d개이며, 원소들은 다음과 같다.\n\n", n);

    for (int i = 0; i < n; i++) {
        printf("%d  ", list[i]);
    }
    printf("\n\n");
    system("PAUSE");
    system("cls");
    return;
}

void end() {
    //종료 프로그램
    printf("\n\n==================================\n");
    printf("\t  종료를 선택하셨습니다.\n");
    printf("==================================\n");

}
