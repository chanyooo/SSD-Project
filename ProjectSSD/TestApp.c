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

void read_line(){
	char res[50];

	FILE * fp = fopen("result.txt", "r");

	printf("%s", fgets(res, sizeof(res), fp));
	fclose(fp);
}

int main(int argc, char* argv[]){
		char cmd[10];
		strcpy(cmd, argv[1]);
		char run[50];
		int idx;
		uint32_t value;

		if(strcmp(cmd, "write") == 0){
			idx = atoi(argv[2]);
			value = strtol(argv[3], NULL, 16);
			sprintf(run, "./ssd W %d 0x%X", idx, value);	
		}
		else if(strcmp(cmd, "read") == 0){
			idx = atoi(argv[2]);
			sprintf(run, "./ssd R %d", idx);
		}
		else if(strcmp(cmd, "help") == 0){
			printf("HELP\n");
			return 0;
		}
		else if(strcmp(cmd, "fullwrite") == 0){
			value = strtol(argv[2], NULL, 16);
			for(int i=0; i<100; i++){
				sprintf(run, "./ssd W %d 0x%X", i, value);
				system(run);
			}
			return 0;
		}
		else if(strcmp(cmd, "fullread") == 0){
			full_read();
			return 0;
		}
		else{
			printf("INVALID COMMAND\n");
			return 0;
		}
		if(idx < 0 || idx > 99){
			printf("INVALID COMMAND\n");
			return 0;
		}
		system(run);
		if(strcmp(cmd, "read") == 0)read_line();

	return 0;
}
