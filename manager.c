#include <stdio.h>
#include <string.h>
#include "manager.h"

int listProduct(Product *p, int count){
    printf("\n********************* Mini Project *********************\n");

    for (int i = 0; i < count; i++){
        if (p[i].price == -1)continue;
        printf("%2d ", i + 1); // NO 숫자
        readProduct(&p[i]);
        printf("\n");
    }
    printf("\n");
    return 0;
}

int selectDataNo(Product *p, int count){
    int no;
    listProduct(p, count);
    printf("번호는 (취소 :0)?");
    scanf("%d", &no);
    return no;
}

int selectMenu(){
    int menu;
    printf("\n");
    printf("1. 메뉴조회\n");
    printf("2. 메뉴추가\n");
    printf("3. 메뉴수정\n");
    printf("4. 메뉴삭제\n");
    printf("5. 파일저장 \n");
    printf("6. 이름검색\n");
    printf("7. 가격검색\n");
    printf("8. 배송방법검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}


