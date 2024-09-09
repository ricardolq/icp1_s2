#include <errno.h> 
#include <stdio.h>
#include <string.h>
  
int main(int argc, char * argv[]) { 
    int returncode = 0;
    if (argc<2)
        returncode = -1;
    else {
        FILE* fp; 
        char * filename = argv[1];
        fp = fopen(filename, "r");
        if (fp == NULL) {
           printf("File descriptor value is NULL\n");     
            if (errno!=0){
                printf("Value of errno is %d when opening %s\n", errno, filename); 
                perror("Message from perror"); //prints on standard error
                printf("The error message opening %s is: %s\n", filename, strerror(errno));
            }
            returncode = -1;
        } else {
            printf("No errors detected when opening %s\n",filename);
            fclose(fp);
        }
    }
    return returncode;
}