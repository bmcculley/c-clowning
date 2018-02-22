/**
 * An example of FizzBuzz, when a number is divisible by 3 print Fizz,
 * divisible 5 print Buzz, divisible by both print FizzBuzz or else 
 * just print the number. 
 *
 * Created by bmcculley
 * Find this and other c snippets here:
 * https://github.com/bmcculley/c-sampling
 */
 #include <stdio.h>

int main()
{

	for (int i = 0; i < 101; i++) {
		if (i % 3 == 0 && i % 5 == 0) {
			printf("FizzBuzz\n");
		}
		else if (i % 3 == 0) {
			printf("Fizz\n");
		}
		else if (i % 5 == 0) {
			printf("Buzz\n");
		}
		else {
			printf("%d\n", i);
		}
	}
	
	return 0;
}