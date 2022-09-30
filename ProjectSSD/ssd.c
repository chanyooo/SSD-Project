#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc,char* argv[])
{
	FILE *fp = fopen("nand.txt","rb");
	char line[20];
	char data[100][20];
	while(fgets(line,20,fp) != NULL)
	{
		for(int i=0; line[i];i++)
		{
			if(line[i]==' ')
			{
				line[i]='?';
			}
		}
		char *adress = strtok(line,"?");
		char *value = strtok(NULL,"?");
		int adressN = atoi(adress);
		strcpy(data[adressN],value);
	}
	fclose(fp);

	if(!strcmp(argv[1],"W"))
	{
		int adress = atoi(argv[2]);
		sprintf(argv[3],"%s\n",argv[3]);
		strcpy(data[adress],argv[3]);
		FILE *fp = fopen("nand.txt","wb");
		for(int i=0; i<100; i++)
		{
			adress = i;
			char result[25];
			sprintf(result,"%d %s",adress,data[adress]);
			fputs(result,fp);
		}
		fclose(fp);
	}
	else if(!strcmp(argv[1],"R"))
	{
		FILE *fp = fopen("nand.txt","rb");
		int adress = atoi(argv[2]);
		for(int i=0; i<100; i++)
		{
			char data[20];
			fgets(data,20,fp);
			if(i==adress)
			{
				for(int j=0; data[j]; j++)
				{
					if(data[j]==' ') data[j]='?';
				}
				char* ad = strtok(data,"?");
				char* da = strtok(NULL,"?");
				FILE *ffp = fopen("result.txt","wb");
				char result[25];
				sprintf(result,"%d %s",i,da);
				fputs(result,ffp);
				fclose(ffp);
			}
		}
		fclose(fp);
	}
	else
	{
		printf("명령어를 입력하세요!\n");
	}

	return 0;
}
