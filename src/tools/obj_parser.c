/**
 * @file obj_parser.c
 * 
 * @author Donald Isaac (https://www.opensourceryumd.com)
 * 
 * @brief Implementation of obj_parser.h
 * 
 * @version 0.1
 * @date 2019-05-18
 * 
 * @copyright Copyright (c) 2019 Open Sourcery. See the LICENSE file for details
 * 
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <unistd.h>
#include "obj_parser.h"
#include "../common.h"

/**
 * @brief Scans a file, turning each line into an array of tokens.
 * 
 * This functions reads a file, and will write a null-terminated token array
 * to the `out` pipe. If a line is empty, it is skipped and not 
 * written to the `out` pipe. This function ignores all leading and trailing
 * whitespace.
 * 
 * @param[out] out 				File descriptor of the write pipe where token 
 * 								arrays will be written to
 * @param file 					The file to read
 * 
 * @return int 					0 if the file was scanned successfully, or a 
 * 								non-zero error code if it was not.
 */
int scan_file(int out, FILE *file)
{
	/* Buffer for storing parsed data */
	char buffer[OBJ_BUFFER_SIZE][MAX_STR_LEN];	
	/* String where the raw line from the file will be stored */
	char line[MAX_STR_LEN];
	/* The pointer used to iterate over the string and the 
	   pointer to the beginning of a token */
	char *ptr, *start = NULL;
	/* Number of tokens in a line */
	int num_tokens = 0;	
	int token_len;	

	while(fgets(line, MAX_LINE_LEN, file))
	{
		/* Skip all of the whitespace */
		while(isspace(ptr) && ptr != '\0') ptr++;
		/* If the string is empty after trimming, skip the line */
		if(!strlen(ptr)) continue;

		/* Iterate over the line */
		for(ptr = line; ptr != '\0'; ptr++)
		{
			/* Put start at the beginning of the token */
			if (!start && !isspace(ptr)) start = ptr;
			/* The end of the token was found, put it into the buffer array */
			else if(start && isspace(ptr))
			{
				token_len = ptr - start;	/* Length of the token string */
				assert(token_len != 0);		/* Sanity check */
				strncpy(buffer[num_tokens], start, token_len);
				start = NULL;
				num_tokens++;
			}
		}
		/* If there was no trailing whitespace, the above loop will not have
		   handled the last token. We have to handle this token manually */
		if (start && start != ptr)
		{
				token_len = ptr - start;	/* Length of the token string */
				assert(token_len != 0);		/* Sanity check */
				strncpy(buffer[num_tokens], start, token_len);
				num_tokens++;
		}

		/* Add an empty string to the end of the buffer to mark the end of
		   the token array */
		strcpy(buffer[num_tokens], "");
		write(out, buffer, sizeof(buffer));
		/* Clear the buffer */
		memset(buffer, "\0", OBJ_BUFFER_SIZE * MAX_STR_LEN);
	}

	return 0;
}
