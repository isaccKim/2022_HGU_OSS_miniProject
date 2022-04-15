#include <stdio.h>
#include <string.h>
#include "product.h"

void readProduct(Product *p){
    printf("%s  %s  %s  %d  %d\n",p->name, p->contents,p->weight,p->price, p->shipping);
} // 하나의 제품 출력 함수

int ceateProduct(Product *p){
    getchar();
    printf("제품명은? ");
    fgets(p->name,sizeof(p->name),stdin);
    p->name[strlen(p->name)-1] = '\0';
    //scanf(" %[^\n]s",p->name);

    printf("설명은? ");
    fgets(p->contents,sizeof(p->contents),stdin);
    p->contents[strlen(p->contents)-1] = '\0';
    //scanf(" %[^\n]s", p->contents);

    printf("중량은? ");
    fgets(p->weight,sizeof(p->weight),stdin);
    p->weight[strlen(p->weight)-1] = '\0';
    //scanf(" %[^\n]s", p->weight);
    
    printf("판매가격은? ");
    scanf("%d",&p->price);
    printf("배송방법은?(1:새벽배송/2:택배배송) ");
    scanf("%d",&p->shipping);
    return 1;
} // 제품을 추가하는 함수

int updateProduct(Product *p){
    getchar();
    printf("제품명은? ");
    fgets(p->name,sizeof(p->name),stdin);
    p->name[strlen(p->name)-1] = '\0';
    //scanf(" %[^\n]s",p->name);

    printf("설명은? ");
    fgets(p->contents,sizeof(p->contents),stdin);
    p->contents[strlen(p->contents)-1] = '\0';
    //scanf(" %[^\n]s", p->contents);

    printf("중량은? ");
    fgets(p->weight,sizeof(p->weight),stdin);
    p->weight[strlen(p->weight)-1] = '\0';
    //scanf(" %[^\n]s", p->weight);
    
    printf("판매가격은? ");
    scanf("%d",&p->price);
    printf("배송방법은?(1:새벽배송/2:택배배송) ");
    scanf("%d",&p->shipping);
    return 0;
} // 제품을 수정하는 함수

int deleteProduct(Product *p){
    p->price = -1;
    printf("삭제됨\n");
    return 0;
} // 제품을 삭제하는 함수
