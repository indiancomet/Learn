// Excercise1-3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main(int argc, char * argv[])
{
	if(argc != 3){
		printf("Usage: Excercise1-3 file1 file2\n");
		return 1;
	}
	FILE *fIn, *fOut;
	fIn = fopen(argv[1], "rb");
	if(fIn == NULL){
		printf("Error opening input file.");
		return 2;
	}

	fOut = fopen(argv[1], "w");
	if(fOut == NULL){
		printf("Error opening output file.");
		return 3;
	}

	const int bufSize = 8;
	char buf[bufSize];
	int bytesRead = 0;
	int bytesWritten = 0;
	
	while((bytesRead = fread(buf, sizeof(char), bufSize, fIn))>0){
		bytesWritten = fwrite(buf, sizeof(char), bytesRead, fOut);
		if(bytesRead != bytesWritten){
			printf("Fatal error while copying file");
			return 4;
		}
	}
	fclose(fIn);
	fclose(fOut);
	return 0;
}

