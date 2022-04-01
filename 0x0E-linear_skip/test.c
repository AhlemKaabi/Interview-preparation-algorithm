#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
int main()
{
	srand(time(0));

	bool randbool;
	randbool = rand() & 1;
	printf("randbool is %b", randbool);
	return 0;
}
