/*
 * pnfaker.c
 *
 * Process name faker for linux/BSD/Unix
 *
 * usage: pnfaker "faked program name" real_program args
 * example: pnfaker "/bin/ls -la" /usr/bin/nc -vn 192.168.1.124 443
 *
 * by defensahacker
 *
 */


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
   char **args, buf[256];
   int i, n, len;

   n= argc-2;
   len= strlen(argv[1]);

   printf("pnfaker: Process' name faker\n\
by defensahacker\n\n");

   if (argc < 3) {
     printf("usage: pnfaker \"faked program name\" real_program args\n\
example: pnfaker \"/bin/ls -la\" /usr/bin/nc -vn 192.168.1.124 443\n");
     return -1;
   }

   memset(buf, ' ', sizeof(buf)-1); // pad the buffer
   buf[sizeof(buf)-1]= 0;
   
   args= (char**) malloc(n*sizeof(char**) + 1);

   for (i=0; i<len; i++)
     buf[i]= argv[1][i];

   args[0]=buf;
   for (i=3; i <= argc; i++)
    args[i-2]= argv[i];
  
   execv(argv[2], args);
   printf("Unexpected error! :(\n");
   return -1;
}
