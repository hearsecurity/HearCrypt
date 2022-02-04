#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <curl/curl.h>

struct string {
  char *ptr;
  size_t len;
};

void init_string(struct string *s) {
  s->len = 0;
  s->ptr = malloc(s->len+1);
  if (s->ptr == NULL) {
    fprintf(stderr, "malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s)
{
  size_t new_len = s->len + size*nmemb;
  s->ptr = realloc(s->ptr, new_len+1);
  if (s->ptr == NULL) {
    fprintf(stderr, "realloc() failed\n");
    exit(EXIT_FAILURE);
  }
  memcpy(s->ptr+s->len, ptr, size*nmemb);
  s->ptr[new_len] = '\0';
  s->len = new_len;

  return size*nmemb;
}

void print_cypher(char *string) {

  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {

    char *substring; 
    struct string s;
    init_string(&s);

    curl_easy_setopt(curl, CURLOPT_URL, string);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
    res = curl_easy_perform(curl);
    substring = strtok(s.ptr,":");
    substring=strtok(NULL,"""");
    substring = strtok(substring,",");
    printf("%s\n", substring);


    free(s.ptr);

    /* always cleanup */
    curl_easy_cleanup(curl);

  }
}


void en_md4_digest(char *message) {

  char string[] = "https://api.hashify.net/hash/md4/hex?value=";
  strcat(string, message);
  printf("Encrypted message: "); 
  print_cypher(string); 

}

void en_md5_digest(char *message) {

  char string[] = "https://api.hashify.net/hash/md5/hex?value=";
  strcat(string, message);
  printf("Encrypted message: "); 
  print_cypher(string); 

}

void en_sha1(char *message) {

  char string[] = "https://api.hashify.net/hash/sha1/hex?value=";
  strcat(string, message);
  printf("Encrypted message: "); 
  print_cypher(string); 

}

void en_sha256(char *message) {

  char string[] = "https://api.hashify.net/hash/sha256/hex?value=";
  strcat(string, message);
  printf("Encrypted message: "); 
  print_cypher(string); 

}

void en_sha512(char *message) {

  char string[] = "https://api.hashify.net/hash/sha512/hex?value=";
  strcat(string, message);
  printf("Encrypted message: "); 
  print_cypher(string); 

}

void list_cyphers() {

   printf("\n1 -> Cesar Cypher\n"); 
   printf("2 -> MD4 Digest  \n");
   printf("3 -> MD5 Digest  \n");
   printf("4 -> SHA1        \n");
   printf("5 -> SHA256      \n");
   printf("6 -> SHA512      \n\n");

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

void en_cesar_cypher(char *message) {

    for(int i = 0; i < strlen(message); i++) {
    	message[i] = message[i] + 3; 
    }
    printf("Encrypted message: %s\n", message); 
}

int main(void) {
    
   char message[100]; 
   int cypher;  

   banner(); 
   printf("All Available Cyphers: \n"); 
   list_cyphers();

   printf("Select an cypher from list: "); 
   scanf("%d", &cypher);
   printf("Type your message: ");
   scanf("%s", message); 


   switch(cypher) {

      case 1: en_cesar_cypher(message);
      break; 
      case 2: en_md4_digest(message); 
      break;
      case 3: en_md5_digest(message); 
      break;
      case 4: en_sha1(message); 
      break;
      case 5: en_sha256(message); 
      break;
      case 6: en_sha512(message); 
      break;
      default: printf("Cypher not found!\n");
   }

return 0; 
}

