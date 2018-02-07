/**
 * An example of converting a hexadecimal 
 * to decimal
 *
 * Created by bmcculley
 * Find this and other c snippets here:
 * https://github.com/bmcculley/c-clowning
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char num[] = "0x6f0";
	long n = strtol(num, NULL, 16);
	printf("%ld\n", n);
	return 0;
}
