#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

void full_read(){
	char res[50];

	FILE *fp = fopen("nand.txt", "r");

	while(fgets(res, sizeof(res), fp)){
			printf("%s", res);
	}

	fclose(fp);
}

int main(){

	while(1){
		char str[50];
		char cmd[10];
		char run[50];
		int idx;
		uint32_t value;
		int flag = 1;

		printf(">> ");
		gets(str);

		if(strcmp(str, "") == 0) continue;

		sscanf(str, "%s %d %X", cmd, &idx, &value);

		if(strcmp(cmd, "exit") == 0) break;
		
		if(strcmp(cmd, "write") == 0){
			sprintf(run, "ssd W %d 0x%X", idx, value);	
		}
		else if(strcmp(cmd, "read") == 0){
			sprintf(run, "ssd R %d", idx);
		}
		else if(strcmp(cmd, "help") == 0){
			printf("HELP\n");
			continue;
		}
		else if(strcmp(cmd, "fullwrite") == 0){
			sscanf(str, "%s %X", cmd, &value);
			for(int i=0; i<100; i++){
				sprintf(run, "ssd W %d 0x%X", i, value);
			}
		}
		else if(strcmp(cmd, "fullread") == 0){
			full_read();
			continue;
		}
		else{
			printf("INVALID COMMAND\n");
			continue;
		}
		if(idx < 0 || idx > 99){
			printf("INVALID COMMAND\n");
			continue;
		}
		printf(run);
	}	


	return 0;
}
