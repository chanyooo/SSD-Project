#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
	FILE *fp = fopen("nand.txt","wb");
	for(int i=0; i<100; i++)
	{
		int index = i;
		char result[25];
		sprintf(result,"%d 0x0000000\n",index);
		fputs(result,fp);
	}
	fclose(fp);
	return 0;
}
