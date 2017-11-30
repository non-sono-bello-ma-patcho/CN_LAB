#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>  
#include<unistd.h>
#include<string.h>
#define _DEBUG
const char *menu="*********************************************MENU'*********************************************\nQuale esercizio vuoi svolgere?\n\n>Premere 1 per l'esercizio uno\n\n>Premere 2 per l'esercizio 2\n\n>Premere 3 per l'esercizio 3\n\n>Premere 4 per inserimento dati libero\n\n>Premere 0 per uscire\n\n\n\n\n\ncomando>";
const char *matricola="4380663";
int main()
{
    int scelta=-1,exit_state,size;
    int pid,status;
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
        strcat(current_directory,"/esercizio2_autorun.out\0");
        #ifdef _DEBUG
        printf("Directory:%s;\n",current_directory);
        #endif
        switch(scelta)
        {   
            case 0:break;
            case 1:
                printf("to be implemented");
                break;
            case 2:
                exit_state=execl(current_directory,"esercizio2_autorun.out",(char*)NULL);
                break;
            case 3:
                exit_state=execl(current_directory,"esercizio2_autorun.out",matricola,(char*)NULL);
                break;
            case 4:
                exit_state=execl(current_directory,"esercizio2_autorun.out",(char*)NULL);
                break; 
            default:
            printf("Comando non valido!!\n\n");
            system("clear");
            break;
        }
        if(exit_state<0){perror("ERRORE:unable to execute esercizio2_autorun.out ");}
        scelta=0;
        free(current_directory);
    }
    else{waitpid(pid,&status,0);}
}
return 0;
}
