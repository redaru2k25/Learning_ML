#include <stdio.h>
#include <math.h>

float mean(int arr[], int n){
    float sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];

    return sum / n;
}

float sum_d2(int arr[], int n, float m){
    float sum = 0;

    for(int i = 0; i < n; i++){
        float d = arr[i] - m;
        sum += d * d;
    }

    return sum;
}

float dx_dy(int x[], int y[], int n, float mx, float my){ // (X - mean) * (Y - mean)
    float sum = 0;

    for(int i = 0; i < n; i++)
        sum += (x[i] - mx) * (y[i] - my);

    return sum;
}

float std_dev(int arr[], int n, float m){
    return sqrt(sum_d2(arr,n,m) / n);
}

float correlation(int x[], int y[], int n){
    float mx = mean(x,n);
    float my = mean(y,n);

    float numerator = dx_dy(x,y,n,mx,my);
    float denom = sqrt(sum_d2(x,n,mx) * sum_d2(y,n,my));

    return numerator / denom;
}

int main(){
    int n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int x[n], y[n];

    printf("Enter values of X:\n");
    for(int i = 0; i < n; i++)
        scanf("%d",&x[i]);

    printf("Enter values of Y:\n");
    for(int i = 0; i < n; i++)
        scanf("%d",&y[i]);

    float mx = mean(x,n);
    float my = mean(y,n);

    float sx = std_dev(x,n,mx);
    float sy = std_dev(y,n,my);

    float r = correlation(x,y,n);

    printf("\nMean of X: %f", mx);
    printf("\nMean of Y: %f", my);

    printf("\nStandard Deviation of X: %f", sx);
    printf("\nStandard Deviation of Y: %f", sy);

    printf("\nKarl Pearson Correlation Coefficient: %f\n", r);

    return 0;
}