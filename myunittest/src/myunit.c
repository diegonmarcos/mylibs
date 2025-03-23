/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myunit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:12:14 by dnepomuc          #+#    #+#             */
/*   Updated: 2025/03/23 16:49:01 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc.h"

int	tests(int file, char mode)
{
	char	*program_name = "get_next_line.out";

	///Files Initialization
	int		number_of_tests = 16;
	char	*files[16] = {\
				"41_no_nl", \
				"41_with_nl", \
				"42_no_nl", \
				"42_with_nl", \
				"43_no_nl", \
				"43_with_nl", \
				"alternate_line_nl_no_nl", \
				"alternate_line_nl_with_nl", \
				"big_line_no_nl", \
				"big_line_with_nl", \
				"empty", \
				"multiple_line_no_nl", \
				"multiple_line_with_nl", \
				"multiple_nlx5", \
				"nl",\
				"variable_nls"
				};
	char	*address_in = "tests/gnl/tests/";
	char	*address_out = "tests/gnl/tests/";
	char 	filename_in[256] = {0};
	char 	filename_out[256] = {0};
	char 	filename_out_vlg[256] = {0};
	char	filename_report[256] = {0};
	int		fd_in;
	FILE	*fd_out;
	char	*line;

	ft_snprintf(filename_report, 256, "gnl_report.md", address_out);
	// Valgrind
	if (mode == 'v')
	{
		// Valgrind
		char	command3[512];
		char	command4[512];
		int		result;
		char	valgrind_c[256] = "valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s";
		char	valgrind_e[256] = " --log-file=";
		char	valgrind[256];
		char	valg_grep[512] = "grep -e \"All heap blocks were freed -- no leaks are possible\" -e \"ERROR SUMMARY: 0 errors from 0 contexts\" -e \"Invalid\" -e \"SIG\""; 
		file = 0;
		
		ft_fprintf2("a", filename_report, "\n\n### Valgrind:\n", number_of_tests);
		for (int i = 0; i < number_of_tests; i++)
		{
			ft_snprintf(filename_out_vlg, 256, "%s%s_vlg", address_out, files[i]);
			ft_snprintf(valgrind, sizeof(valgrind), "%s%s%s", valgrind_c, valgrind_e, filename_out_vlg);
			ft_snprintf(command3, sizeof(command3), "%s ./%s %d r", valgrind, program_name, i);
			result = system(command3);
			if (!result)
				ft_fprintf1(filename_report, "- ✔ [%d] %s: **Ok**  \n", i, files[i]);
			else
			{
				ft_fprintf1(filename_report, "- ❗ [%d] %s: `NoK : %d`  \n", i, files[i], result);
				ft_snprintf(command4, sizeof(command4), "%s %s >> %s", valg_grep, filename_out_vlg, filename_report);
				result = system(command4);
			}
		}
	}
	else if (mode == 'r')
	{
		ft_snprintf(&filename_in[file], 256, "%s%s", address_in, files[file]);
		fd_in = open(&filename_in[file], O_RDONLY);

		while ((line = get_next_line(fd_in)))
			free(line);
		close(fd_in);
	}
	else if (mode != 'v')
	{
		/// Tests
		ft_fprintf2("w", filename_report, "# GNL - TEST REPORT\n > Test of [%d] files  \n\n### Tests:\n", number_of_tests);
		for (int i = 0; i < number_of_tests; i++)
		{
			/// Run Input
			ft_snprintf(&filename_in[i], 256, "%s%s", address_in, files[i]);
			fd_in = open(&filename_in[i], O_RDONLY);
			ft_snprintf(&filename_out[i], 256, "%s%s_out", address_out, files[i]);
			fd_out = fopen(&filename_out[i], "w");

			while ((line = get_next_line(fd_in)))
			{
				ft_fprintf(fd_out, "%s", line);
				free(line);
			}
			close(fd_in);
			fclose(fd_out);

			/// Copy Debug File
			char	command0[512];

			ft_snprintf(command0, sizeof(command0), "cp gnl_debug.log %s_dbg", &filename_out[i]);
			system(command0);
			ft_fprintf2("w", "gnl_debug.log", "");

			/// File Report
			char	command1[512];
			int		result;

			ft_snprintf(command1, sizeof(command1), "diff -u %s %s", &filename_in[i], &filename_out[i]);
			result = system(command1);
			if (!result)
				ft_fprintf1(filename_report, "- ✔ [%d] %s: **Ok**  \n", i, files[i]);
			else
				ft_fprintf1(filename_report, "- ❗ [%d] %s: `NoK`  \n", i, files[i]);
		}
	}
	return (0);
}

void	help(void)
{
	ft_printf("Usage:\n");
	ft_printf("        ./program \n");
	ft_printf("        or \n");
	ft_printf("        ./program [number] [option]\n");
	ft_printf("Number:\n");
	ft_printf("        0: dummy var for user add any number\n");
	ft_printf("Option:\n");
	ft_printf("        t: only tests\n");
	ft_printf("        v: only valgrind\n");
	ft_printf("        b: both\n");
	exit(0);
}
void	static_analysis(void)
{
	char	command0[512];
	char	command1[512];
	char	command2[512];
	char	command3[512];
	char	command4[512];

	ft_snprintf(command0, sizeof(command0), "(cd tests/gnl ; clang -c -Wall -Wextra tsrc/get_next_line.c -Iinc -o gnl.o > gnl_w0.log 2>&1)");
	system(command0);
	ft_snprintf(command1, sizeof(command1), "(cd tests/gnl ; clang -c -Wformat -Warray-bounds -Wnull-dereference -Wvla -ftrapv src/get_next_line.c -Iinc -o gnl.o > gnl_w1.log 2>&1)");
	system(command1);
	ft_snprintf(command2, sizeof(command2), "(cd tests/gnl ; clang -c -Weverything src/get_next_line.c -Iinc -o gnl.o > gnl_w2.log 2>&1)");
	system(command2);
	ft_snprintf(command3, sizeof(command3), "(cd tests/gnl ; clang -c --analyze -Xanalyzer -analyzer-checker=core src/get_next_line.c -Iinc -o gnl.o > gnl_w3.log 2>&1)");
	system(command3);
//	ft_snprintf(command4, sizeof(command4), "(cd tests/gnl ; scan-build -o > gnl_w4.log 2>&1)");
//	system(command4);
//	ft_snprintf(command4, sizeof(command4), "(cd tests/gnl ; clang-tidy > gnl_w4.log 2>&1)");
//	system(command4);
}


/**
 * @brief Tester - ./program [number] [option]
 *
 * @param number dummy for user, add 0, usage for recursive valgrind
 * @param option t for only tests, v for only valgrind, b for both
 */
int	main(int argc, char **argv)
{
	///Files Initialization
	int		file;
	char	mode;

	/// Arguments
	if (argc == 1)
	{
		file = 0;
		mode = 'b';
	}
	else if (argc == 3)
	{
		file = *argv[1];
		mode = *argv[2];
	}
	else
		help();

	/// Tests
	if (mode == 's')
		static_analysis();
	if (mode == 'b')
	{
		tests(file, 't');
		tests(file, 'v');
	}
	else
		tests(file, mode);
	return (0);
}



/* void	diff_files_2(char *filename_in, char *filename_out)
{
	FILE	*fd_in;
	FILE	*fd_out;
	char	buff_in[256] = {0};
	char	buff_out[256] = {0};
	int		i = 0;

	fd_in = fopen(filename_in, "r");
	fd_out = fopen(filename_out, "r");
	while (fgets(buff_in, 256, fd_in) && fgets(buff_out, 256, fd_out))
	{
		if (strcmp(buff_in, buff_out))
		{
			ft_fprintf2("w", GNL_OUT, "Line %d:\n%s\n%s\n", i, buff_in, buff_out);
		}
		i++;
	}
	fclose(fd_in);
	fclose(fd_out);
} */


/* 
int	main2(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	ft_fprintf2("w", GNL_OUT,"Hello Mof\n\n");
//	fd1 = open("../tester/gnlTester/files/43_with_nl", O_RDONLY);
//	fd2 = open("../tester/gnlTester/files/multiple_line_with_nl", O_RDONLY);
//	fd3 = open("../tester/gnlTester/files/multiple_nlx5", O_RDONLY);
//	fd1 = -1;
	fd3 = 102102101;
	fd2 = open("../tester/gnlTester/files/42_with_nl", O_RDONLY);
	fd1 = open("../tester/gnlTester/files/alternate_line_nl_with_nl", O_RDONLY);
//	fd4 = open("../tester/gnlTester/files/empty", O_RDONLY);
	i = 0;
	printf("##############FIRST FILE\n");
	while ((line = get_next_line(fd1)))
	{
		ft_fprintf("lines [%d]: %s", i, line);
		free(line);
		i++;
	}
	i = 0;
	printf("\n##############SECOND FILE\n");
	while ((line = get_next_line(fd2)))
	{
		ft_printf("line [%d]: %s", i, line);
		free(line);
		i++;
	}
	i = 0;
	printf("\n##############THIRD FILE\n");
	while ((line = get_next_line(fd3)))
	{
		ft_printf("line [%d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */