#include <stdio.h>
#include <unistd.h>
#include <string.h>

const char* USER_ID= "xxxxxxxx";
const char* PASS= "Pass1234";
const char* HOSTNAME="hostname";
const char* DOMNAME="example.com";

int main(){
 FILE *file;
 char buffer[128];
 char *pcmd;
 file=popen("curl ifconfig.io -4","r");
 if (file==NULL){
	 printf("ERROR!! Can't reach \"ifconfig.io\"\n");
	 return -1;
	 }
 fgets(buffer, 128, file);
 pclose(file);
 buffer[strlen(buffer)-1]='\0';
 file=popen("openssl s_client -connect ddnsclient.onamae.com:65010 -quiet","w");
 sleep(1);
 fprintf(file,"LOGIN\nUSERID:%s\nPASSWORD:%s\n.\n",USER_ID,PASS);
 sleep(1);
 fprintf(file,"MODIP\nHOSTNAME:%s\nDOMNAME:%s\nIPV4:%s\n.\n",HOSTNAME,DOMNAME,buffer);
 sleep(1);
 fprintf(file,"LOGOUT\n.\n");
 pclose(file);
 printf("\n%s\n",buffer);
 return 0;
}
