#include <stdio.h>
#include <stdlib.h>


//行列式计算
extern double HLS0( double **, int);
extern int HLS1( double **, int,int);
extern double HLS_D( double **, int);

//矩阵
extern int input(double **, int,int);
extern void BH_H(double **, int, int, double, int);
extern void BH_L(double **L, int a, int b, double JZ, int c);
extern void BH_ZS(double** ZS,int c);

int main() {
    while(1) {
        int c = 0;
        int n = 0;
        printf("请输入矩阵行列数(输入-214678退出)\n");
        scanf("%d", &c);
        if(c==-214678) exit(0);
        double **FZ = malloc(c * sizeof(double *));
        if(FZ == NULL) exit(0);
        for (int i = 0; i < c; i++) {
            FZ[i] = (double *)malloc(c * sizeof(double));
        }
       if(  input(FZ,c,c)==0) /*暂作调试*/{
            printf("已从新开始\n");
           for (int i = 0; i < c; i++) {
               free(FZ[i]);
           }
           free(FZ);
           continue;
       }
        printf("结果为\n%.20lf\n%.20lf\n",HLS_D(FZ, c),HLS0(FZ,c));
        for (int i = 0; i < c; i++) {
            free(FZ[i]);
        }
        free(FZ);
        while(getchar() != '\n');
    }
}
