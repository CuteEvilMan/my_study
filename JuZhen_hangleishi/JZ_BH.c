
#include <stdio.h>
#include <stdlib.h>
//矩阵行变换
void BH_H(double **H, int a, int b, double JZ, int c) {
    if (JZ == 0.0) {//行交换
        double* tempRow= H[a];
        H[a] = H[b];
        H[b] = tempRow;

    } else {//将一行的倍数加到另一行
        for (int j = 0; j < c; j++) {
            H[a][j] +=  H[b][j] * JZ ;
        }
    }
}
//矩阵列变换
void BH_L(double **L, int a, int b, double JZ, int c) {
    if (JZ == 0.0) {
        double *L_ = malloc(sizeof(double) * (c));
        for (int j = 0; j < c; j++) {
            L_[j] = L[j][a];
        }
        for (int j = 0; j < c; j++) {
            L[j][a] = L[j][b];
        }
        for (int j = 0; j < c; j++) {
            L[j][b] = L_[j];
        }

            free(L_);
    }
    else {
        for (int j = 0; j < c; j++) {
            L[j][a] += L[j][b] * JZ;
        }
    }
}
//矩阵转置
void BH_ZS(double** ZS,int c) {
    for (int j = 0; j < c; j++) {
        for (int k = 0; k < j; k++) {
        double temp = ZS[k][j];
            ZS[k][j] = ZS[j][k];
            ZS[j][k] = temp;

        }
    }
}

//矩阵输入
int input(double **H, int c,int a) {
    printf("本程序按行输入\n");
    for (int j = 0; j < c; j++) {
        int l_q_W =0;
        printf("正在输入第%d行(连续输入1行零自动结束)\n", j + 1);
        for (int i = 0; i < a; i++) {
            //printf("%d:", i + 1);
            scanf("%lf", H[j] + i);
            if(H[j][i] == 0) {
                l_q_W++;
            }   else l_q_W=0;
        }
        if(l_q_W == c) return 0;
    }
    printf("您输入的矩阵为\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < a; j++) {
            printf("%lf ", H[i][j]);
        }
        putchar('\n');
    }
    return 1;

}
