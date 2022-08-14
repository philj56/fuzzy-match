#define _GNU_SOURCE /* Required for getline with -std=c99 */
#include <stdio.h>
#include <stdlib.h>
#include "fuzzy_match.h"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "%s: Filter newline-separated entries from stdin.\n\n", argv[0]);
		fprintf(stderr, "Usage: %s <pattern>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	char *entry = NULL;
	ssize_t bytes_read;
	size_t n = 0;
	const char *pattern = argv[1];
	while ((bytes_read = getline(&entry, &n, stdin)) != -1) {
		/* Strip newline included by getline. */
		entry[bytes_read - 1] = '\0';
		int32_t score = fuzzy_match(pattern, entry);
		if (score != INT32_MIN) {
			printf("%d|%s\n", score, entry);
		}
	}
	free(entry);
	return EXIT_SUCCESS;
}
