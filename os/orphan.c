/*Orphan process -> whose parent proces has finished or terminated through itself remains running. A process can become orphaned during remote invocation when the client process crashes after making a request to server*/
#include<stdio.h>
#include<unistd.h>
int main(){
    pid_t pid;
    pid = fork();//calling fork to create a child process;
    if(pid ==0){
        sleep(6);
        printf("\n i m child. My PID = %d And PPID = %d", getpid(),getppid());
    }
    else{
        printf(" I m parent. My child PID = %d And my PID = %d", pid,getpid());
    }
    printf("\n terminating PID = %d\n",getpid());
    
    return 0;

}