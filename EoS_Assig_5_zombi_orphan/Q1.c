#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{   int ret , i , s;
    for(i=0;i<5;i++)
    {   ret=fork();
        if(ret==0)
        {    for (int count= 1; count <= 5; count++)
        {
           printf("child process %d count %d \n",getpid(),count);
           sleep(1);
        }
        
            
            exit(i);
        }
        }
	
     for(i=0;i<5;i++)
     {   waitpid(-1,&s,0);
            printf("child exit -> %d \n ", WEXITSTATUS(s));
            }
         
            return 0;


}
