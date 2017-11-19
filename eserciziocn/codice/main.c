#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>  
#include<unistd.h>
#include<string.h>
#include<limits.h>
//#define _DEBUG
const char *menu="*********************************************MENU'*********************************************\nQuale esercizio vuoi svolgere?\n\n>Premere 1 per l'esercizio uno\n\n>Premere 2 per l'esercizio 2\n\n>Premere 3 per l'esercizio 3\n\n>Premere 4 per inserimento dati libero\n\n>Premere 0 per uscire\n\n\n\n\n\ncomando>";
const char *matricola="4380663";
void custom_fail(int *exit_state);
int main()
{
    int scelta=-1,exit_state,size;
    int pid,status,pid2,status2;
    char *current_directory;

    
while(scelta!=0)
{
    printf("%s",menu);
    fflush(stdin);
    scanf("%d",&scelta);
    pid=fork();
    if(pid<0){perror("ERROR:fork failed");}
    if(pid==0)
    {
        
        current_directory=(char*)malloc(sizeof(char)*250);
        if(!current_directory){perror("ERRORE:unable to allocate enough memory ");}
        current_directory=getcwd(current_directory,250);
        if((size=strlen(current_directory)+strlen("/esercizio2_autorun.out\0"))>=250)
        {
            current_directory=(char*)realloc(current_directory,size+1);
            if(!current_directory){perror("ERRORE:unable to reallocate enough memory ");}
        }
        if(!current_directory){perror("ERRORE:unable to get current directory name");}
        #ifdef _DEBUG
        printf("Directory:%s;\n",current_directory);
        #endif
        switch(scelta)
        {   
            case 0:break;
            case 1:
                pid2=fork();
                if(pid2==0)/*esercizio1 a*/
                {
                    strcat(current_directory,"/bin/esercizio1a.out\0");
                    printf("\nEseguo esercizio1a:\n");
                    exit_state=execl(current_directory,"esercizio1a.out",(char*)NULL);
                    custom_fail(&exit_state);return 0;
                }
                else{waitpid(pid2,&status2,0);}
                pid2=fork();
                if(pid2==0)/*esercizio1 b*/
                {
                    strcat(current_directory,"/bin/esercizio1b.out\0");
                    printf("\nEseguo esercizio1b:\n");
                    exit_state=execl(current_directory,"esercizio1b.out",(char*)NULL);
                    custom_fail(&exit_state);return 0;
                }
                else{waitpid(pid2,&status2,0);}
                pid2=fork();
                if(pid2==0)/*esercizio1 c*/
                {
                    strcat(current_directory,"/bin/esercizio1c.out\0");
                    printf("\nEseguo esercizio1c:\n");
                    exit_state=execl(current_directory,"esercizio1c.out",(char*)NULL);
                    custom_fail(&exit_state);return 0;
                }
                else{waitpid(pid2,&status2,0);}
                return 0;/*kill first child(pid)*/
                break;
            case 2:
                strcat(current_directory,"/bin/esercizio2_autorun.out\0");
                exit_state=execl(current_directory,"esercizio2_autorun.out",(char*)NULL);
                break;
            case 3:
                strcat(current_directory,"/bin/esercizio2_autorun.out\0");
                exit_state=execl(current_directory,"esercizio2_autorun.out",matricola,(char*)NULL);
                break;
            case 4:
                strcat(current_directory,"/bin/esercizio2_autorun.out\0");
                exit_state=execl(current_directory,"esercizio2_autorun.out",(char*)NULL);
                break; 
            default:
            printf("Comando non valido!!\n\n");
            system("clear");
            break;
        }
        custom_fail(&exit_state);
        free(current_directory);
        return 0;
    }
    else{waitpid(pid,&status,0);}
}
return 0;
}



void custom_fail(int *exit_state)
{
    if(exit_state<0){perror("ERRORE:unable to execute esercizio2_autorun.out ");}
    return;
}
