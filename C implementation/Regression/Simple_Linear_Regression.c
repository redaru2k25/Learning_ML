#include <stdio.h>
#include <math.h>
#define MAX 100000
/*
    Linear Regression assumes that Y = A + BX.
    So we find A and B values by using statistical techniques.
    It only works when X and Y are highly correlated linearly.
*/
int main (){
    printf("Enter dataset size:");
    int n = 0;
    int sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;
    scanf("%d",%n);
    int ax[n],int ay[n];
    printf("Enter %d X values:\n",n);
    for (int i = 0;i < n;i++){
        scanf("%d",&ax[i]);
        sum_x = sum_x + ax[i];
        sum_x2 = sum_x2 + (int) pow(ax[i],2);
    }
    printf("Enter %d Y values:\n ",n);
     for (int i = 0;i < n;i++){
        scanf("%d",&ay[i]);
        sum_y = sum_y + ay[i];
        sum_xy = sum_xy + ax[i]*ay[i];
     }
     /*
        Now we got the values of sum of values of x, x*y, x^2 and y.
        sum(Y) = n*a + b*sum(X)
        sum(XY) = a*sum(X) + b*sum(X^2);
        We have to find the values of a and b from these 2 equations to the obtain the equation:
                Y = A + BX
     */
    float B = (n*sum_xy - sum_x * sum_y) / (n*sum_x2 - sum_x * sum_x);
    float A = (sum_y - b * sum_x) / n;
    printf("Regression line is:\nY = %.3f + %.3fX",A,B);
    return 0;
}