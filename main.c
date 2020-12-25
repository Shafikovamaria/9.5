#include <stdio.h>
void trup(int n,int m,float M[n][m])
{
    for(int j=0;j<n;j++)
    {
        int i=j;
        while (M[i][j] == 0)
            i = i + 1;
        for(int k=j;k<m;k++)
        {float c=M[i][k];
        M[i][k]=M[j][k];
        M[j][k]=c;
        }
        for (int t=j+1;t<n;t++)
        {
            float h =-M[t][j]/M[j][j];
            for(int s=j;s<m;s++)
            {
                M[t][s]+=h*M[j][s];
            }
        }

    }
}
void trdown(int n,int m,float M[n][m])
{
    for(int j=n-1;j>=0;j--)
    {
        int i=j;
        while (M[i][j] == 0)
            i = i - 1;
        for(int k=0;k<m;k++)
        {
            float c=M[i][k];
            M[i][k]=M[j][k];
            M[j][k]=c;
        }
        for (int t=j-1;t>=0;t--)
        {
            float h =-M[t][j]/M[j][j];
            for(int s=0;s<m;s++)
            {
                M[t][s]+=h*M[j][s];
            }
        }

    }
}
main()
{int n;
scanf ("%d", &n);
    const int row = n;
    const int col = n+1;
    float ma[row][col];
    int i,j;
    for (i=0;i<n;i++)
    {
        for (int k = 0; k < n + 1; ++k) {
            scanf("%f", &ma[i][k]);
        }
    }
    trup(n,n+1,ma);
    trdown(n,n+1,ma);
    for (int k = 0; k < row; ++k) {
        printf("%f\n", ma[k][n]/ma[k][k]);
    }
//    for (int k = 0; k < row; ++k) {
//        for (int l = 0; l < col; ++l) {
//            printf("%f ",ma[k][l]);
//        }
//        printf("\n");
//    }

    return 0;
}
