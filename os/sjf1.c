#include<stdio.h>
struct pcb{
    int pid,burst,wait,turnaround;
};
void pline(int);
int main(){
    struct pcb p[10],temp;
    int sum=0,i,j,num,w_total=0,t_total=0;
    float w_avg = 0.0, t_avg = 0.0;

    printf("enter total process :\n");
    scanf("%d", &num);

    //burst time
    for(i = 0;i<num;i++){
        printf("enter burst time of process : %d",i+1);
        scanf("%d", &p[i].burst);
        p[i].pid = i+1;
    }

    //sort according to burst time;
    for(i=0;i<num-1;i++){
        for(j=0;j<num-i-1;j++){
            if(p[j].burst >p[j+1].burst){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    //calculate wait time and turnaround time;
    for(i = 0;i<num;i++){
        p[i].wait = sum;
        sum = sum + p[i].burst;
        p[i].turnaround = sum;
    }

    pline(35);
    printf("PID\tburst\twait\tturnaround\n");
    pline(35);
    for(i=0;i<num;i++){
        printf("%d\t%d\t%d\t%d\n", p[i].pid,p[i].burst,p[i].wait,p[i].turnaround);
        w_total  += p[i].wait;
        t_total  += p[i].turnaround; 
    }
    pline(35);
    w_avg = w_total/(float)num;
    t_avg = t_total/(float)num;
    printf("total wait time : %d\n average wait time : %f\n",w_total,w_avg);
    printf("total turnaround time : %d\n average turnaround time : %f\n",t_total,t_avg);
    return 0;

}
void pline(int x){
    int i;
    for(i=0;i<x;i++){
        printf("-");
    }
    printf("\n");
}
