#include<stdio.h>
 #include<stdlib.h>
struct process
{
      char process_481;
      int AT_481, BT_481, CT_481,WT_481,TAT_481, priority_481;
      int status;
}process_queue[10];
 
int limit_481;
 
void AT_Sorting_481()
{
      struct process temp;
      int i, j;
      for(i = 0; i < limit_481 - 1; i++)
      {
            for(j = i + 1; j < limit_481; j++)
            {
                  if(process_queue[i].AT_481 > process_queue[j].AT_481)
                  {
                        temp = process_queue[i];
                        process_queue[i] = process_queue[j];
                        process_queue[j] = temp;
                  }
            }
      }
}
 
void main()
{
      int i, time_481 = 0, BT_481 = 0, largest_481;
      char c_481;
      float WT_481 = 0, TAT_481 = 0, avg_TAT_481, avg_WT_481;
      printf("\nEnter the  Number of Processes:\t");
      scanf("%d", &limit_481);
      for(i = 0, c_481 = 'A'; i < limit_481; i++, c_481++)
      {
            process_queue[i].process_481 = c_481;
            printf("\nEnter arrival time,burst time and priority For Process[%C]:\n", process_queue[i].process_481);
            printf("Enter Arrival Time:\t");
            scanf("%d", &process_queue[i].AT_481 );
            printf("Enter Burst Time:\t");
            scanf("%d", &process_queue[i].BT_481);
            printf("Enter Priority:\t");
            scanf("%d", &process_queue[i].priority_481);
            process_queue[i].status = 0;
            BT_481 = BT_481 + process_queue[i].BT_481;
      }
      AT_Sorting_481();
      process_queue[9].priority_481 = -9999;
      printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
      for(time_481 = process_queue[0].AT_481; time_481 < BT_481;)
      {
            largest_481 = 9;
            for(i = 0; i < limit_481; i++)
            {
                  if(process_queue[i].AT_481 <= time_481 && process_queue[i].status != 1 && process_queue[i].priority_481 > process_queue[largest_481].priority_481)
                  {
                        largest_481 = i;
                  }
            }
            time_481 = time_481 + process_queue[largest_481].BT_481;
            process_queue[largest_481].CT_481 = time_481;
            process_queue[largest_481].WT_481 = process_queue[largest_481].CT_481 - process_queue[largest_481].AT_481 - process_queue[largest_481].BT_481;
            process_queue[largest_481].TAT_481 = process_queue[largest_481].CT_481 - process_queue[largest_481].AT_481;
            process_queue[largest_481].status = 1;
            WT_481 = WT_481 + process_queue[largest_481].WT_481;
            TAT_481 = TAT_481 + process_queue[largest_481].TAT_481;
            printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d", process_queue[largest_481].process_481, process_queue[largest_481].AT_481, process_queue[largest_481].BT_481, process_queue[largest_481].priority_481, process_queue[largest_481].WT_481);
      }
      avg_WT_481= WT_481 / limit_481;
      avg_TAT_481 = TAT_481 / limit_481;
      printf("\n\nAverage waiting time:\t%f\n", avg_WT_481);
      printf("Average Turnaround Time:\t%f\n", avg_TAT_481);
}