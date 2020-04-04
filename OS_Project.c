//In this we are taking input for arrival time and burst time from the user and printimg them
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
int n,p;                                     //Declaring the variable
printf("Enter the number of Processes: ");
scanf("%d",&n);                  			  //Asking value from user
int process[n];                			     //Declaring the variable
double complition_time[n], turnaround_time[n], waiting_time[n], arrival_time[n], burst_time[n];  //Declaring the variable
printf("\n");
for(int i=0;i<n;i++)       			      //Asking burst time and arrival time from user
	{
	 	printf("Enter the value of arrival time for process %d: ",i);
		scanf("%d",&p);
		if(p==0)                //if-else condition as if the user enter arrival time as 0 it will display an error
		{					
		printf("zero not allowed\n");
		printf("Re-enter the arrival time: ");
		scanf("%lf",&arrival_time[i]);
		}
		else
			arrival_time[i]=p;
		printf("Enter the value of burst time for process %d: ",i);
		scanf("%lf",&burst_time[i]);
		printf("\n");
		process[i]=i+1; 
	}
printf("---------------------values that are enterd---------------------------\n\n");
printf("\t\t\t_________________________________________________________________\n");
printf("\t\t\t|	Process	|	Arrival Time	|	Burst Time	|\n");
printf("\t\t\t_________________________________________________________________\n");

for(int i=0;i<n;i++)       		      //Printing the values
	{
	
	printf("\t\t\t|	P%d	|	   %0.00lf	   	|	%0.00lf		|\n",process[i], arrival_time[i], burst_time[i]);
	printf("\t\t\t_________________________________________________________________\n");
	}
}
