#include <stdio.h>
#include<string.h>
 
#define MAXCHAR 1000


void print_line(char *str){
    char delim[] = ",";
    char *ptr = strtok(str, delim);
    int count =0;
	while(ptr != NULL)
	{
        if(count<=3)
        {
            printf("%s\t", ptr);
            count++;
        }
        else{
            
            printf(" %s", ptr);
        }
		
		ptr = strtok(NULL, delim);
	}
}

int main() {    
    FILE *fp;
    char str[MAXCHAR];
    char* filename = "menu.txt";
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL)
        print_line(str);

    fclose(fp);
 
    return 0;
}

