#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>

const char* opts = "h:i:s:a:v:d:c";

const struct option long_opts[] = {
        {"help",0,0,'h'},
        {"info",1,0,'i'},
        {"set",1,0,'s'},
        {"assign",1,0,'a'},
        {"value",1,0,'v'},
        {"del",1,0,'d'},
        {"clear",1,0,'c'},
};


int main(int argc, char *argv[]){

    if(argc <= 1){
        system("env");
    }

    int c;
    char * assign = NULL;
    char * value = NULL;
    int flag = 0;
    while ((c = getopt_long(argc,argv,opts,long_opts,NULL)) != -1){
        switch (c) {
            case 'h':{
                printf("some help\n");
            }break;
            case 'i':{
                char * env = getenv(optarg);
                if(env == NULL){
                    printf("Environ not fount\n");
                } else{
                    printf("%s = %s\n", optarg, env);
                }
            }break;

            case 's':{
                char sep[10] = "=";
                char * env = strtok(optarg,sep);
                char * val = strtok(NULL,sep);

                printf("evn = %s val = %s\n", env,val);


                int result = setenv(env,val,0);
                if(result == 0){
                    printf("Success\n");
                } else{
                    printf("some error\n");
                }
            }break;

            case 'v':{
                value = optarg;
                flag |= 0x0F;
            }break;
            case 'a':{
                assign = optarg;
                flag |= 0xF0;
            }break;
            case 'd':{
                unsetenv(optarg);
            }break;
            case 'c':{
                clearenv();
            }break;
        }
    }

    if(flag == 0xFF || flag == 0xF0){
        if(value == NULL){
            value = "";
        }
        if(setenv(assign,value,1) == 0){
            printf("Success\n");
        } else{
            printf("Some error\n");
        }
    }
    return 0;
}
