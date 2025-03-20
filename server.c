#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

// void func(int sig)
// {
//     static int i = 0;
//     static unsigned char c = 0;


//     if (sig == SIGUSR1)
//         c |= (1 << i);
//     else if (sig == SIGUSR2)
//         c &= (1 << i)
//     i++;
//     if (i == 8)
//     {
//         write(1, &c, 1);
//         i = 0;
//         c = 0;
//     }
// }
void	handle_signal(int sig, siginfo_t *info, void *content)
{
	static unsigned char	received_char;
	static int				bit_count;
	static int				last_pid;

	(void)content;
	if (last_pid != info->si_pid)
	{
		received_char = 0;
		bit_count = 0;
		last_pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		received_char = received_char << 1;
	else if (sig == SIGUSR2)
		received_char = (received_char << 1) | 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (received_char == '\0')
			write(1, "\n", 1);
		else
			write(1, &received_char, 1);
		received_char = 0;
		bit_count = 0;
	}
}
int main()
{
    struct sigaction	sa;

	printf("%d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();

    return 0;
}


