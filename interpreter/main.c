#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <lexer.c>

char* readFile(char* filePath);

int main(int argc, char* argv[]){
	char* fileBuffer = readFile(argv[1]);
	char* tokenBuffer[10];
	lexer(tokenBuffer, fileBuffer);
    return 0;
}

char* readFile(char* filePath){
	FILE* filePointer = fopen(filePath, "r");

	fseek(filePointer, 0L, SEEK_END);
	int fileSize = ftell(filePointer) + 1;
	rewind(filePointer);

	char* fileBuffer = malloc(fileSize);

	int c;
	char cc;
	while((c = fgetc(filePointer)) != EOF){
		cc = (char)c;
		strncat(fileBuffer, &cc, 1);
	}
  fclose(filePointer);
	return fileBuffer;
}
