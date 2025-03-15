#include <stdio.h>
#include <signal.h>
#include <unistd.h> 
#include <sys/types.h>
int main()
{
	// char i = 'a';// a = 97    11000001
	// int x = 10; //00001010
	// int y = 6;  //00000110

	// int z = 0;  //00000010 
	// int j = 7;
	// int b = 0;
	//  z = x & y;
	//  printf("in & z = %d\n",z);

	// // z = x | y;
	// // printf("in | z = %d\n",z);

	// // z = x ^ y;
	// // printf("in ^ z = %d\n",z);
	// // z = 1;
	// // z = z << 4;
	// // printf("z >> 2 = %d\n",z);

	// while(j >= 0)
	// {
	// 	if(((i >> j) & 1) == 0)
	// 		printf("0");
	// 	else
	// 		printf("1");
	// 	j--;
	// }

	pid_t num = getpid();
	printf("%d",num);
}