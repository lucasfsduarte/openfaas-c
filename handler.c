/*
# File:
#     handler.c
#
# Author:
#     Lucas F. Duarte
#
# Description:
#     Handler that communicates with watchdog
#
*/

#include "header.h"

#define INPUT_MAX_SIZE 15

int main() {

    char *input;
    int actLen, maxLen;

	// Allocating memory to data array;
    maxLen = INPUT_MAX_SIZE + 2;
    input = malloc(maxLen * sizeof(char));

	// Getting data from standard input;
    fgets(input, maxLen, stdin);
    actLen = strlen(input);

	// Removing '\n' from the end;
    if (input[actLen - 1] == '\n') {
        input[actLen - 1] = '\0';
        actLen = strlen(input);
    }

	// Forwarding received data;
	manager(input);
    return 0;
}
