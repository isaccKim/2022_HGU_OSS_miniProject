#include <stdio.h>

typedef struct {
    char name[100];
    char contents[100];
    char weight[100];
    int price;
    int shipping;
}Product;

//CRUD
int ceateProduct(Product *p); // 제품을 추가하는 함수
void readProduct(Product *p); // 하나의 제품 출력 함수
int updateProduct(Product *p); // 제품을 수정하는 함수
int deleteProduct(Product *p); // 제품을 삭제하는 함수





