#include<stdio.h>
struct pcb{
    int pid,arrival,burst,turnaround;
};
void pline(int x);
int main(){
    int num,i,j;
    float avg=0.0,sum=0.0;
    struct pcb p[10],temp;
    printf("enter the total number of process :");
    scanf("%d", &num);
    //enter arrival and burst time;
    for(i=0;i<num;i++){
        printf("enter the arrival time and burst time for process %d\n", i+1);
        scanf("%d %d", &p[i].arrival,&p[i].burst);
        p[i].pid = i+1;
    }
    //sorting according to arrival time
    for (i = 0 ; i < num - 1 ; i++) {
        for ( j = 0 ; j < num-i-1; j++){
            if(p[j].arrival>p[j+1].arrival){
            temp = p[j];
            p[j] = p[j+1];
            p[j+1] = temp;
            }
        }
    }
    //turnaround time calculation
    for(int i=0;i<num;i++){
        sum = sum + p[i].burst;
        p[i].turnaround = sum;
    }

    sum = 0;
    pline(44);
    printf("PID\tArrival\tBurst\tTurnaround\n");
    pline(44);
    for(i=0;i<num;i++){
        printf("%d\t%d\t%d\t%d\n",p[i].pid,p[i].arrival,p[i].burst,p[i].turnaround);
        sum += p[i].turnaround;
    }
    pline(44);
    //    average turn around time
    avg = sum/(float)num;
    printf("\ntotal turn around time : %f",sum);
    printf("\n Average turn around time : %f",avg);
    return 0;
}
void pline(int x){
    int i;
    for(i=0;i<x;i++){
        printf("-");
    }
    printf("\n");
}