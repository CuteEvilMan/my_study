#include <stdio.h>

void ShuRu(double*, double*,double*);//掌管数字输入
int PanDuan(double*, double* ,double*);//缩小待选择区间
double HanShuo(double a); //待求解函数

double a,b,C,FuZhu,A,B;
int main(void)
{
    while(1)
    {
        printf("请给出两个数字，代表所要求解的零点所在区间\n");

        ShuRu(&a,&b,&C);
        while (getchar() != '\n');
        A = HanShuo(a);
        B = HanShuo(b);
        if(a==b) break;
        else if(A==0) {
            printf("%lf\n",a);
            continue;
        }   else if(B==0) {
            printf("%lf\n",b);
            continue;
        } else if( A*B>0 ) {
            printf("错误\n");
            continue;
        }
        while((a-b >0 ? a-b :b-a) >=C ) {
            if(PanDuan(&a,&b,&FuZhu)==0) {
                printf("%lf\n",a);  return 0;
            }
        }
    printf("%lf     %lf\n",a,b);
    }

    return 0;
}

void ShuRu(double *a_1, double *b_1,double* C_1)   //输入函数
{

    scanf("%lf%lf%lf",a_1,b_1,C_1);
}

double HanShuo(double a_2)//待求解函数
{
    return a_2 * a_2 / 2   - 1;
}

int PanDuan(double *a_3, double *b_3,double *FuZhu_3)//缩小区间函数
{
   *FuZhu_3 =(*a_3 + *b_3)/2;
    double FUZHU_3=HanShuo(*FuZhu_3);
    if(FUZHU_3==0) {
        *a_3 = *FuZhu_3;
        return 0;
    } else if(FUZHU_3 * A<0)
        *b_3 = *FuZhu_3;
    else *a_3 = *FuZhu_3;
    return 1;

}