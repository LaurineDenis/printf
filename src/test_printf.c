/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_printf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 15:58:09 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2021/02/08 11:34:05 by mhouppin         ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/*
 * Default settings for 2019 students' printf.
 * Change defines to 1 to enable flag handling.
 */

#define ENABLE_SHARP	0
#define ENABLE_ZERO		1
#define ENABLE_MINUS	1
#define ENABLE_SPACE	0
#define ENABLE_PLUS		0

#define ENABLE_WIDTH		1
#define ENABLE_PRECISION	1
#define ENABLE_WILDCARD		1

#define ENABLE_h	0
#define ENABLE_l	0
#define ENABLE_L	0
#define ENABLE_j	0
#define ENABLE_z	0
#define ENABLE_t	0

#define ENABLE_di	1
#define ENABLE_o	0
#define ENABLE_u	0
#define ENABLE_xX	0
#define ENABLE_eE	0
#define ENABLE_fF	0
#define ENABLE_gG	0
#define ENABLE_aA	0
#define ENABLE_c	0
#define ENABLE_s	0
#define ENABLE_p	0

enum
{
	MinTestI,
	MaxTestI,
	ZeroTestI,
	OneTestI,
	MinusOneTestI,
	GenMaxI = 10
};

int		ft_printf(const char *fmt, ...);

char	*g_stdout_filename = "tmp.txt";
int		g_stdout_fd;

void	__pipe_stdout(void)
{
	int		fd = open(g_stdout_filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd < 0)
	{
		perror("Unable to open tmp filename");
		exit(EXIT_FAILURE);
	}
	g_stdout_fd = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	__load_stdout(void)
{
	dup2(g_stdout_fd, STDOUT_FILENO);
	close(g_stdout_fd);
}

uint64_t	__generate_int(unsigned int bits)
{
	uint64_t	value;

	switch ((unsigned long int)random() % GenMaxI)
	{
		case MinTestI:
			return (1ul << (bits - 1));

		case MaxTestI:
			return ((1ul << (bits - 1)) - 1);

		case ZeroTestI:
			return (0);

		case OneTestI:
			return (1);

		case MinusOneTestI:
			return (-1);

		default:
			return ((uint64_t)random());
	}
}

void	__check_diffs(char *call_buf, char *real_printf, int pf_return, int your_return)
{
	int		fd = open(g_stdout_filename, O_RDONLY);

	if (fd < 0)
	{
		perror("Unable to open tmp filename");
		exit(EXIT_FAILURE);
	}

	off_t	your_size = lseek(fd, 0, SEEK_END);

	lseek(fd, 0, SEEK_SET);

	char	*your_printf = malloc(your_size);

	read(fd, your_printf, your_size);

	close(fd);

	if (pf_return != your_return || pf_return != your_size || memcmp(real_printf, your_printf, your_size))
	{
		puts(call_buf);
		if (pf_return != your_return)
			printf("Diff on return value: real %d, yours %d\n", pf_return, your_return);
		if (pf_return != your_size || memcmp(real_printf, your_printf, your_size))
		{
			printf("Diff on output:\nreal  \"");
			fwrite(real_printf, 1, pf_return, stdout);
			printf("\"\nyours \"");
			fwrite(your_printf, 1, your_size, stdout);
			printf("\"\n");
		}
		fflush(stdout);
	}
	free(your_printf);
}

void	__gen_test_int(void)
{
	uint64_t	param = __generate_int(64);
	char		fmtbuf[256];

	uint64_t	    flag_key = __generate_int(64);
	unsigned char	width = __generate_int(sizeof(char) * 7);
	unsigned char	precision = __generate_int(sizeof(char) * 7);

	strcpy(fmtbuf, "%");

#if ENABLE_SHARP
	if (flag_key & 1)
		strcat(fmtbuf, "#");
#endif
#if ENABLE_ZERO
	if (flag_key & 2)
		strcat(fmtbuf, "0");
#endif
#if ENABLE_MINUS
	if (flag_key & 4)
		strcat(fmtbuf, "-");
#endif
#if ENABLE_SPACE
	if (flag_key & 8)
		strcat(fmtbuf, " ");
#endif
#if ENABLE_PLUS
	if (flag_key & 16)
		strcat(fmtbuf, "+");
#endif
#if ENABLE_WIDTH
	if (flag_key & 32)
	{
		if (flag_key & 64)
			strcat(fmtbuf, "*");
		else
			sprintf(fmtbuf + strlen(fmtbuf), "%hhu", width);
	}
#endif
#if ENABLE_PRECISION
	if (flag_key & 128)
	{
		if (flag_key & 256)
			strcat(fmtbuf, ".*");
		else
			sprintf(fmtbuf + strlen(fmtbuf), ".%hhu", precision);
	}
#endif
	uint64_t length_value = (flag_key >> 9) & 7;
	switch (length_value)
	{
#if ENABLE_h
		case 0:
			strcat(fmtbuf, "h");
			break ;

		case 1:
			strcat(fmtbuf, "hh");
			break ;
#endif
#if ENABLE_l
		case 2:
			strcat(fmtbuf, "l");
			break ;

		case 3:
			strcat(fmtbuf, "ll");
			break ;
#endif
#if ENABLE_j
		case 4:
			strcat(fmtbuf, "j");
			break ;
#endif
#if ENABLE_z
		case 5:
			strcat(fmtbuf, "z");
			break ;
#endif
#if ENABLE_t
		case 6:
			strcat(fmtbuf, "t");
			break ;
#endif
		default:
			break ;
	}
	uint64_t conv_value = (flag_key >> 12) & 7;
	switch (length_value)
	{
#if ENABLE_o
		case 0:
			strcat(fmtbuf, "o");
			break ;
#endif
#if ENABLE_u
		case 1:
			strcat(fmtbuf, "u");
			break ;
#endif
#if ENABLE_x
		case 2:
			strcat(fmtbuf, "x");
			break ;
#endif
#if ENABLE_X
		case 3:
			strcat(fmtbuf, "X");
			break ;
#endif
#if ENABLE_p
		case 4:
			strcat(fmtbuf, "p");
			break ;
#endif
		default:
			strcat(fmtbuf, "d");
			break ;
	}

	char	*real_printf;
	int		real_printf_return;
	int		your_printf_return;
	char	call_buf[256];

	if (ENABLE_WIDTH && (flag_key & 96))
	{
		if (ENABLE_PRECISION && (flag_key & 384))
		{
			real_printf_return = asprintf(&real_printf, fmtbuf, (int)width, (int)precision, param);
			__pipe_stdout();
			your_printf_return = ft_printf(fmtbuf, (int)width, (int)precision, param);
			__load_stdout();
			sprintf(call_buf, "printf(\"%s\", %hhu, %hhu, %llu):", fmtbuf, width, precision, param);
		}
		else
		{
			real_printf_return = asprintf(&real_printf, fmtbuf, (int)width, param);
			__pipe_stdout();
			your_printf_return = ft_printf(fmtbuf, (int)width, param);
			__load_stdout();
			sprintf(call_buf, "printf(\"%s\", %hhu, %llu):", fmtbuf, width, param);
		}
	}
	else
	{
		if (ENABLE_PRECISION && (flag_key & 384))
		{
			real_printf_return = asprintf(&real_printf, fmtbuf, (int)precision, param);
			__pipe_stdout();
			your_printf_return = ft_printf(fmtbuf, (int)precision, param);
			__load_stdout();
			sprintf(call_buf, "printf(\"%s\", %hhu, %llu):", fmtbuf, precision, param);
		}
		else
		{
			real_printf_return = asprintf(&real_printf, fmtbuf, param);
			__pipe_stdout();
			your_printf_return = ft_printf(fmtbuf, param);
			__load_stdout();
			sprintf(call_buf, "printf(\"%s\", %llu):", fmtbuf, param);
		}
	}
	__check_diffs(call_buf, real_printf, real_printf_return, your_printf_return);
	free(real_printf);
}

void	__generate_one_test(void)
{
	__gen_test_int();
}

int		main(int argc, char **argv)
{
	srandom(time(NULL));

	if (argc == 1 || argc > 3)
		printf(" usage: %s test_count [tmpfile]\n", *argv);
	else
	{
		int		test_count = atoi(argv[1]);
		if (argv[2])
			g_stdout_filename = argv[2];

		for (int i = 0; i < test_count; i++)
			__generate_one_test();

		unlink(g_stdout_filename);
	}
	return (0);
}
