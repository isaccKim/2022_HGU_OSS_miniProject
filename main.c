#include <stdio.h>
#include "manager.h"

int main(){
    Product p[30];
    int count = 0, menu;
    int index = 0;
    count = loadProduct(p);
    index = count;
#ifdef DEBUG
   printf("===>DEBUG MODE!");
#endif
    while (1){
        menu = selectMenu();
        if (menu == 0)
            break;
       if (menu == 1 && count != 0){
             int ltemp = -1;
             ltemp = listProduct(p,index);
 #ifdef DEBUG
             if(ltemp == 0)printf("==>DEBUG MODE: listProduct Method runs Successfully!\n");
#endif
       }//메뉴조회
        
        else if (menu == 2){
            count += ceateProduct(&p[index++]);
        } //메뉴추가

        else if (menu == 3 && count >= 1){
            int no = selectDataNo(p, count);
            if (no == 0){
                printf("=> 취소함\n");
                continue;
            }
            int temp = -1; temp=updateProduct(&p[no-1]);
#ifdef DEBUG
          if(temp == 0)printf("\n==>DEBUG MODE: updateProduct Method runs Succesfully!\n");
#endif
        } //수정

        else if (menu == 4 && count >= 1){
            int deleteOk; //삭제
            int no = selectDataNo(p, index);
            
            if (no == 0){
                printf("=> 취소됨\n");
                continue;
            }
            printf("정말로 삭제하시겠습니까(삭제 :1)");
            scanf("%d", &deleteOk);
            if (deleteOk == 1)count -= deleteProduct(&p[no-1]);
        }

        else if(menu == 5){
           saveProduct(p,index);
           }

        else if(menu == 6){
            searchProductName(p,index);
        }

        else if(menu == 7){
            searchProductPrice(p,index);
        }

        else if(menu == 8){
            searchProductShipping(p,index);
        }
            continue;
    }
    printf("종료됨!\n");
    return 0;
}
