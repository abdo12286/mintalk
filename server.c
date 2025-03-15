#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main()
{
	pid_t num;
	
	num = getpid();
	printf("%d",num);

	static unsigned char a;
	static int	i;
	int j;

	i = 0;
	a = 0;
	j = 7;

	if(i == 8)
		i = 0;
	while (i < 8)
	{
		if()

	}
	

}