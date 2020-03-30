#include <stdio.h>
#include<string.h>
 
#define MAXCHAR 1000



 



void print_line(char *str){
    char delim[] = ",";
    char *ptr = strtok(str, delim);
    int count =0;
    char *id;
    char *name;
    char *category;
    char *ingredients;
  


	while(ptr != NULL)
	{


        if(count==0)
        {
            id = ptr;
        }
        if(count==1)
        {
            name = ptr;
        }
        if(count==2)
        {
            category = ptr;
        }
        if(count>=3)
        {
           ingredients =  ptr;
           //strcat(ingredients,ptr);
        }
        // strcpy(menu[0], ptr);
        count++;
      
		
		ptr = strtok(NULL, delim);
	}
    printf("|      %s      |     %s      |     %s     |     %s      \n",id,name,category,ingredients);
}

int read_Ingredients()
{
FILE *fp;

    char str[MAXCHAR];
    char* filename = "menu.txt";
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    printf("|     ID      |                 NAME             |     CATEGORY     |     INGREDIENTS    | \n");
    while (fgets(str, MAXCHAR, fp) != NULL)
        print_line(str);

    fclose(fp);
}

int scan_new_ingredients(){
      char id[10];
    char name[100];
    char category[100];
    char ingredients[200];
    printf("Enter Id for the Ingredient: ");
    scanf("%s",id);
    printf("Enter Ingredient Name:");
    scanf("%s",name);
    printf("Enter Category:");
    scanf("%s",category);
    printf("Enter Ingredients:");
    scanf("%s",ingredients);
    


    FILE *fptr;

 
   fptr = fopen("menu.txt","a");

   if(fptr == NULL)
   {
      printf("Error!");   
      return 1;            
   }

   
   fprintf(fptr,"\n%s,",id);
    fprintf(fptr,"%s,",name);
     fprintf(fptr,"%s,",category);
      fprintf(fptr,"%s",ingredients);
   fclose(fptr);

  
}

     

int main() {    
    
    read_Ingredients();
    scan_new_ingredients();
    getchar();
    return 0;
}

