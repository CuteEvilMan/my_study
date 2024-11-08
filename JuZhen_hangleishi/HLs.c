
#include <stdio.h>
#include <stdlib.h>

extern void BH_H(double **, int, int, double, int);
 int HLS1( double **, int,int);
//将矩阵化为上三角矩阵
double HLS0( double **HLS, int n) {
    double result = 1.0;
    int l_q_W = 0;
    int o_=0;
    for (int j = 0; j < n; j++) {
        o_= HLS1 ( HLS, n - j,j);
        if (o_ == -1) {
            return 0;
        }
        l_q_W+=o_;
    }

    for (int j = 0; j < n; j++) {
        result *= HLS[j][j];
    }
    if(l_q_W%2==1 )
        result = -result;
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
        BH_H(HLS_M, p, j, 0, v+p);
        d++;
    }
    for (int s = 1; s < v; s++) {
        if (HLS_M[s+p][p] != 0.0)
            BH_H(HLS_M, s+p, p, -HLS_M[s+p][p]/HLS_M[p][p],v+p);
    }
    return d;

}

//对矩阵直接展开
    double HLS_D(double** HLS, int N) {
        if (N == 1) return HLS[0][0];
        double result = 0.0;
        for (int I = 0; I < N; I++) {
            double** HLS_ = malloc((N-1) * sizeof(double*));
            for (int i = 0; i < N-1; i++) {
                HLS_[i] = malloc((N-1) * sizeof(double));
            }
            for (int i = 0; i < N-1; i++) {
                for (int j = 0; j < N-1; j++) {
                    if (j < I) HLS_[i][j] = HLS[i+1][j];
                    else HLS_[i][j] = HLS[i+1][j+1];
                }
            }

            if (I % 2 == 0) result += HLS[0] [I]* HLS_D(HLS_, N-1);
            else result -= HLS[0] [I]*HLS_D(HLS_, N-1);
            for (int i = 0; i < N-1; i++) {
                free(HLS_[i]);
            }
            free(HLS_);
        }
        return result;
    }
