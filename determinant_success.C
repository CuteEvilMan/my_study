#include <stdio.h>
#include <stdlib.h>

int input(double **, int);
double HLS0( double **, int);
int HLS1( double **, int,int);
void BH(double **, int, int, double, int);

int main() {
    while(1) {
        int c = 0;
        printf("请输入行列式阶数(输入-214678退出)\n");
        scanf("%d", &c);
        if(c==-214678) exit(0);
        double **JZ = malloc(c * sizeof(double *));
        if(JZ == NULL) exit(0);
        for (int i = 0; i < c; i++) {
            JZ[i] = (double *)malloc(c * sizeof(double));
        }
       if(  input(JZ, c)==0) {
            printf("已从新开始\n");
           for (int i = 0; i < c; i++) {
               free(JZ[i]);
           }
           free(JZ);
           continue;
       }
        HLS0(JZ, c);
        for (int i = 0; i < c; i++) {
            free(JZ[i]);
        }
        free(JZ);
        while(getchar() != '\n');
    }
}
//矩阵输入
int input(double **H, int c) {
    printf("本程序按行输入\n");
    for (int j = 0; j < c; j++) {
        int l_q_W =0;
        printf("正在输入第%d行(连续输入1行零自动结束)\n", j + 1);
        for (int i = 0; i < c; i++) {
            //printf("%d:", i + 1);
            scanf("%lf", H[j] + i);
            if(H[j][i] == 0) {
                l_q_W++;
            }   else l_q_W=0;
        }
        if(l_q_W == c) return 0;
    }
    printf("您输入的方阵为\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c; j++) {
            printf("%lf ", H[i][j]);
        }
        putchar('\n');
    }
        return 1;

}
//矩阵的行变换
void BH(double **H, int a, int b, double JZ, int c) {
    if (JZ == 0.0) {//行交换
        double* tempRow=(double *)malloc(c * sizeof(double));
        for (int j = 0; j < c; j++) {
            tempRow[j] = H[a][j];
        }
        for (int j = 0; j < c; j++) {
            H[a][j] = H[b][j];
        }
        for (int j = 0; j < c; j++) {
            H[b][j] = tempRow[j];
        }
        free(tempRow);
    } else {//将一行的倍数加到另一行
        for (int j = 0; j < c; j++) {
            H[a][j] +=  H[b][j] * JZ ;
        }
    }
}
//将矩阵化为上三角矩阵
double HLS0( double **HLS, int n) {
    double result = 1.0;
    int l_q_W = 0;
    int o_=0;
    for (int j = 0; j < n; j++) {
      o_=HLS1( HLS, n - j,j);
        if (o_ == -1) {
            printf("结果为0\n");
            return 0;
        }
            l_q_W+=o_;
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", HLS[i][j]);
        }
        putchar('\n');
    }*/
    for (int j = 0; j < n; j++) {
        result *= HLS[j][j];
    }
    if(l_q_W%2==1 )
        result = -result;
    printf("%lf\n", result);
    return result;
}
int HLS1( double **HLS_M, int v,int p) {
    int j = 0;
    for (j = 0; j < v; j++) {
        if (HLS_M[p+j][p] != 0.0)
            break;
    }
    if (j == v) return -1;
    int d=0;
    if (j != 0) {
        BH(HLS_M, p, j, 0, v+p);
        d++;
    }
    for (int s = 1; s < v; s++) {
        if (HLS_M[s+p][p] != 0.0)
            BH(HLS_M, s+p, p, -HLS_M[s+p][p]/HLS_M[p][p],v+p);
    }
    return d;

}
