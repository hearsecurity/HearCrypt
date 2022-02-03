#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

void list_cyphers() {

   printf("\n1 -> Cesar Cypher\n\n"); 

}

void banner() {

  system("clear");
  printf(" ██╗  ██╗███████╗ █████╗ ██████╗ ███████╗███████╗ ██████╗ \n");
  printf(" ██║  ██║██╔════╝██╔══██╗██╔══██╗██╔════╝██╔════╝██╔════╝ \n");
  printf(" ███████║█████╗  ███████║██████╔╝███████╗█████╗  ██║      \n");
  printf(" ██╔══██║██╔══╝  ██╔══██║██╔══██╗╚════██║██╔══╝  ██║      \n");
  printf(" ██║  ██║███████╗██║  ██║██║  ██║███████║███████╗╚██████╗ \n");
  printf(" ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚═════╝ \n");
  printf("\n");
  printf(" Tool: HearCrypt\n");
  printf(" Author: HearSecurity\n"); 
  printf(" Github: https://github.com/hearsecurity\n"); 
  printf(" Website: https://hearsecurity.000webhostapp.com/\n\n");                                                  
}

void dec_cesar_cypher(char *message) { 

    for(int i = 0; i < strlen(message); i++) {
      message[i] = message[i] - 3; 
    }
    
    printf("Decrypted message: %s\n", message); 

}

void en_cesar_cypher(char *message) {

    for(int i = 0; i < strlen(message); i++) {
    	message[i] = message[i] + 3; 
    }
    printf("Encrypted message: %s\n", message); 
}

int main(void) {
    
   char message[100]; 
   int cypher; 
   int crypt; 

   banner(); 
   printf("All Available Cyphers: \n"); 
   list_cyphers();

   printf("Select an cypher from list: "); 
   scanf("%d", &cypher);
   printf("\n1 -> Encrypt\n");
   printf("2 -> Decrypt\n\n"); 
   printf("Select an option: "); 
   scanf("%d", &crypt);
   printf("Type your message: ");
   scanf("%s", message); 

   if(crypt == 1) {

     switch(cypher) {

        case 1: en_cesar_cypher(message);
        break; 
        default: printf("Cypher not found!\n");
     }  
   }

   if(crypt == 2) {

      switch(cypher) {

        case 1: dec_cesar_cypher(message);
        break; 
        default: printf("Cypher not found!\n");
      }  
   }
return 0; 
}

