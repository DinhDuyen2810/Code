/*  Nhập vào số viên bi ban đầu, sau đó bạn và máy lần lượt bốc từ 1->5 viên bi lên.
    Ai bốc cuối cùng thì người đó thua. Máy đi trước
    Có 1 con đường duy nhất để thắng máy. Goodluck!!!   */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n,m,x,ran;
    do {
        printf("Nhap so vien bi(>30): ");
        scanf("%d", &n);
    } while(n < 31);
    if(n % 6 == 0){
        m = 5;
    } else if(n % 6 == 1){
        srand(time(0));
        m = (rand() % 5) + 1;
    } else {
        m = (n % 6) - 1;
    }
    n = n - m; 
    printf("May boc: %d vien    Con lai %d vien\n", m, n);
    do{
        if(n == 1) break;
        do{
            printf("Ban boc: ");
            scanf("%d", &x);
        } while((x < 1) || (x > 5));
        n -= x;
        if(n == 1){
            printf("Con lai %d vien \nGioi the may thua roi!!!", m);
            break;
        }
        if(n % 6 == 0){
            printf("May boc: 5 vien");
            n -= 5;
        } else if((n - 1) % 6 != 0){
            printf("May boc: %d vien", (n % 6) - 1);
            n -= (n % 6) - 1;
        } else {
            srand(time(0));
            printf("May boc: %d vien",ran = (rand() % 5) + 1);
            n -= ran;
        }
        printf("    Con lai %d vien\n", n);
    } while(n != 1);
    if(n == 1) printf("BAN THUA");
return 0;
}











