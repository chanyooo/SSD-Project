CC=gcc
CFLAGS=-g
TARGET=TestShellApp.c
RESULT=Test

app: 
	$(CC) -o $(RESULT) $(TARGET)

clean:
	rm $(RESULT)

TestApp1:
	(echo fullwrite 0x12345; echo fullread;  echo exit) | ./Test 

TestApp2:
	(for((i=0; i<3; i++)) do\
   	 echo read $i\
	done; echo exit	) | ./Test
