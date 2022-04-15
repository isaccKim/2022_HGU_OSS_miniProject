#include <stdio.h>
#include <string.h>
#include "manager.h"
#include <stdlib.h>

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


void searchProductName(Product *p, int count){
    int scnt = 0;
    char search[20];

    printf("검색할 이름?");
    scanf(" %s", search);
    
    printf("\n********************* Mini Project *********************\n");
    for(int i=0; i<count; i++){
        if(p[i].price == -1)continue;
        if(strstr(p[i].name,search)){
            printf("%2d ", i+1);
            readProduct(&p[i]);
            scnt++;
        }
    }
    if(scnt ==0)printf("=> 검색된 데이터 없음!");
    printf("\n");
}// 제품이름 검색

void searchProductPrice(Product *p, int count){
    int scnt = 0;
    int search = 0;

    printf("검색할 제품가격?");
    scanf(" %d", &search);
    
    printf("\n********************* Mini Project *********************\n");
    for(int i=0; i<count; i++){
        if(p[i].price == -1)continue;
        if(p[i].price == search){
            printf("%2d ", i+1);
            readProduct(&p[i]);
            scnt++;
        }
    }
    if(scnt ==0)printf("=> 검색된 데이터 없음!");
    printf("\n");
} // 제품가격 검색

void searchProductShipping(Product *p, int count){
    int scnt = 0;
    int search = 0;

    printf("검색할 배송방법?");
    scanf(" %d", &search);
    
    printf("\n********************* Mini Project *********************\n");
    for(int i=0; i<count; i++){
        if(p[i].price == -1)continue;
        if(p[i].shipping == search ){
            printf("%2d ", i+1);
            readProduct(&p[i]);
            scnt++;
        }
    }
    if(scnt == 0)printf("=> 검색된 데이터 없음!");
    printf("\n");
    }// 배송방법 검색

void saveProduct(Product *p, int count){
    FILE *fp ;
    fp = fopen("Product.txt","wt");
    for(int i=0; i<count; i++){
        if(p->price == -1)continue;
        fprintf(fp,"%s,  %s,  %s,  %d,  %d\n",p[i].name, p[i].contents,p[i].weight,p[i].price, p[i].shipping);
    }
    fclose(fp);
    printf("=>저장됨!\n");
} //데이터를 파일에 저장 하는 함수

int loadProduct(Product *p){
    int count = 0;
    FILE *fp;
    int i = 0;
    char buf[3000];
    char *wBuf;
    int nBuf;
    fp = fopen("Product.txt","rt");
    printf("\n");

    if(fp == NULL){
        printf("=> 파일 없음");
    }
    else{
            while(!feof(fp)){
                if((!fgets(buf, sizeof(buf), fp))) break;
                wBuf = strtok(buf,",");
                strcpy(p[i].name, wBuf);
                
                wBuf = strtok(NULL,",");
                strcpy(p[i].contents, wBuf);
                
                wBuf = strtok(NULL,",");
                strcpy(p[i].weight, wBuf);

                wBuf = strtok(NULL,",");
                nBuf = atoi(wBuf);
                p[i].price = nBuf;

                wBuf = strtok(NULL,",");
                nBuf = atoi(wBuf);
                p[i].shipping = nBuf;
                i++;
            count++;
            }
        fclose(fp);
        printf("=> 로딩 성공\n");
        }
    return count;
}// 저장된 데이터를 불러오는 함수


