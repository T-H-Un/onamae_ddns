#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
 FILE *file;
 char buffer[128];
 char *pcmd;
 strcpy(buffer,"curl ifconfig.io -4 > /tmp/gbip.buff");
 pcmd=(char*)buffer;
 system(pcmd);
 file=fopen("/tmp/gbip.buff","r");
 fgets(buffer,128,file);
 fclose(file);
 buffer[strlen(buffer)-1]='\0';
 file=popen("openssl s_client -connect ddnsclient.onamae.com:65010 -quiet","w");
 sleep(1);
 fprintf(file,"LOGIN\nUSERID:12345678\nPASSWORD:pass1234\n.\n");
 sleep(1);
 fprintf(file,"MODIP\nHOSTNAME:hostname\nDOMNAME:test.com\nIPV4:%s\n.\n",buffer);
 sleep(1);
 fprintf(file,"LOGOUT\n.\n");
 pclose(file);
 printf("\n%s\n",buffer);
 return 0;

}
