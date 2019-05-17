/**
 * @file engine.c
 * @author Donald Isaac (www.opensourceryumd.com)
 * @brief Entry point for the system.
 * @version 0.1
 * @date 2019-05-16
 * 
 * @copyright Copyright (c) 2019 Open Sourcery. Licensed under the MIT License.
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <sysexits.h>
#include <unistd.h>
#include "common.h"

/**
 * @brief Raytracer entry point. The command line options are as follows:
 * 
 * 	Usage: raytrace [output] [input]
 * 		output  				The file where the final image will be written to.
 * 								If not provided, the image is sent to stdout
 * 
 * 	 	input					The file containing settings for the raytracer.
 * 								If not provided, stdin is used.
 * 
 * @return int 					0 on success; a non-zero exit code on failure.
 */
int main(int argc, char **argv)
{
	int in_fd, out_fd;

	/* Handle command line arguments */
	switch(argc) {
		case 3:	/* Redirect stdin to the input file */
			in_fd = open(argv[2]);
			if (in_fd < 0) err(EX_OSFILE, "Input file failed to open.");
			dup2(STDIN_FILENO, in_fd);
		case 2:	/* Redirect stdout to the output file */
			out_fd = open(argv[1]);
			if (out_fd < 0) err(EX_OSFILE, "Output file failed to open.");
			dup2(STDOUT_FILENO, out_fd);
			break;
		default:
			printf("Reading and writing from stdin and stdout.\n");
	}

		return 0;
}
