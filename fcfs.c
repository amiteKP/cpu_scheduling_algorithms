#include<stdio.h>
#include<conio.h>
int main()
{
    int n,i,j,sum=0;
    int arr[10],bt[10],start[10];
    int comp[10],wt[10],tat[10];
    float avgtat=0.0,avgwt=0.0;
    start[0]=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the arrival time and burst time of %d process:",i+1);
        scanf("%d%d",&arr[i],&bt[i]);
    }
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<i;j++)
        sum=sum+bt[j];
        start[i]=sum;
    }
    for(i=0;i<n;i++)
    {
        comp[i]=bt[i]+start[i];
        wt[i]=tat[i]+bt[i];
        tat[i]=comp[i]-arr[i];
    }
    for(i=0;i<n;i++)
    {
        avgwt+=wt[i];
        avgtat+=tat[i];
    }
    avgwt/=n;
    avgtat/=n;
    printf("\narrival_time burst_time Start_time completion_time Wait_time Turnaroud_time\n");
    for(i=0;i<n;i++)
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",arr[i],bt[i],start[i],
    comp[i],wt[i],tat[i]);
    printf("\nAverage waiting time=%f",avgwt);
    printf("\nAverage turn around time=%f",avgtat);
    return 0;
}
