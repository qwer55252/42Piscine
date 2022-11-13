/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c07main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyuhong <gyuhong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:18:10 by gyuhong           #+#    #+#             */
/*   Updated: 2022/06/04 20:29:45 by gyuhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00/ft_strdup.c"
#include "ex01/ft_range.c"
#include "ex02/ft_ultimate_range.c"
#include "ex03/ft_strjoin.c"
#include "ex04/ft_convert_base.c"
#include "ex04/ft_convert_base2.c"
#include "ex05/ft_split.c"
#include <stdio.h>
#include <string.h> 

int main()
{
	{
		printf("--------ex00-------\n\n");
		char *strdup_str1 = "hello ";
		char *strdup_str2 = "";

		printf("strdup_str 1 = hello "); 
		printf("strdup = %s\n", strdup(strdup_str1));
		printf("ft_strdup = %s\n", ft_strdup(strdup_str1));
		printf("\n");
		printf("strdup_str 2= ""\n"); 
		printf("strdup = %s\n", strdup(strdup_str2));
		printf("ft_strdup = %s\n", ft_strdup(strdup_str2));
	}
	{
		printf("------ex01------\n");
		printf("min = 3, max = 10\n");
		int	*arr;
		arr = ft_range(3, 10);
		for(int i = 0; i < 9; i++)
		{
			printf("%d ", arr[i]);
		}
		free(arr);
		printf("\nmin = 10, max = 3\n");
		arr = ft_range(10, 3);
		printf("%p \n", arr);
		free(arr);
		printf("\nmin = 3, max = 3\n");
		arr = ft_range(3, 3);
		printf("%p \n", arr);
		free(arr);
	}
	{

		printf("-----ex02-----\n");
		int *ultimate_range_p = 0;
		int value;

		printf("ft_ultimate_range min : 3 max : 42\n");
		value = ft_ultimate_range(&ultimate_range_p , 3, 42);
		for (int i = 0; i < 50; i++)
		{
			printf("%d ", ultimate_range_p[i]);
		}
		printf("return value = %d\n", value);
		free(ultimate_range_p);
		ultimate_range_p = 0;
		printf("ft_ultimate_range min : 3 max : 3\n");
		value = ft_ultimate_range(&ultimate_range_p, 3, 3);
		printf("return value = %d\n", value);
		free(ultimate_range_p);
		ultimate_range_p = 0;
		printf("ft_ultimate_range min : 3 max : 2\n");
		value = ft_ultimate_range(&ultimate_range_p, 3, 2);
		printf("return value = %d\n", value);
		free(ultimate_range_p);
		ultimate_range_p = 0;
	}
	{
		{
			printf("-------ex03-------\n");
			char *str_join[] = {"hello","my", "name","is", "gyuhong"};
			char str_join_sep[10] = " ** ";
			int	size = 5;
			printf("str = hello, my, name, is, gyuhong\t size = %d, sep = %s\n\n", size, str_join_sep);
			printf("%s\n", ft_strjoin(size, str_join, str_join_sep));
		}
		{
			printf("\n");
			printf("case 1 : sep = ""\n");
			char *str_join[] = {"hello","my", "name","is", "gyuhong"};
			char str_join_sep[10] = "";
			int	size = 5;
			printf("str = hello, my, name, is, gyuhong\t size = %d, sep = %s\n\n", size, str_join_sep);
			printf("%s\n", ft_strjoin(size, str_join, str_join_sep));
			printf("\n");
		}
		{
			printf("\n\n");
			printf("case 2 : not correct size\n");
			char *str_join[] = {"hello","my", "name","is", "gyuhong"};
			char str_join_sep[10] = "";
			int	size = 3;
			printf("str = hello, my, name, is, gyuhong\t size = %d, sep = %s\n\n", size, str_join_sep);
			printf("%s\n", ft_strjoin(size, str_join, str_join_sep));
			printf("\n");
		}
		{
			printf("\n\n");
			printf("case 3 : size = 1\n");
			char *str_join[] = {"hello","my", "name","is", "gyuhong"};
			char str_join_sep[10] = " ** ";
			int	size = 1;
			printf("str = hello, my, name, is, gyuhong\t size = %d, sep = %s\n\n", size, str_join_sep);
			printf("%s\n", ft_strjoin(size, str_join, str_join_sep));
			printf("\n");
		}
		{
			printf("\n\n");
			printf("case 4 : size = 2\n");
			char *str_join[] = {"hello","my", "name","is", "gyuhong"};
			char str_join_sep[10] = " ** ";
			int	size = 2;
			printf("str = hello, my, name, is, gyuhong\t size = %d, sep = %s\n\n", size, str_join_sep);
			printf("%s\n", ft_strjoin(size, str_join, str_join_sep));
			printf("\n");
			printf("-------ex03-------\n");
		}
	}
	{
		{
			printf("--------ex04---------\n");
			char *str = "0";
			char *base_from = "0123456789";
			char *base_to = "01";
			printf("%s\n", ft_convert_base(str, base_from, base_to));
		}
		{
			char *str = "-1";
			char *base_from = "0123456789";
			char *base_to = "01";
			printf("%s\n", ft_convert_base(str, base_from, base_to));
		}
		{
			char *str = "-2";
			char *base_from = "0123456789";
			char *base_to = "01";
			printf("%s\n", ft_convert_base(str, base_from, base_to));
		}
		{
			char *str = "2";
			char *base_from = "0123456789";
			char *base_to = "01";
			printf("%s\n", ft_convert_base(str, base_from, base_to));
		}
		{
			char *str = "-2147483648";
			char *base_from = "0123456789";
			char *base_to = "01";
			printf("%s\n", ft_convert_base(str, base_from, base_to));
		}
		{
			char *str = "101";
			char *base_from = "";
			char *base_to = "24";
			printf("base error check\n\n");
			printf("case 1.  base is empty or size of 1 \2n");
			printf("base size = 0\n");
			printf("result = ");
			printf("%s\n", ft_convert_base(str, base_from, base_to));
		}
		{
			char *str = "101";
			char *base_from = "1";
			char *base_to = "23";
			printf("base size = 1\n");
			printf("result = ");
			printf("%s\n", ft_convert_base(str, base_from, base_to));
		}
	}
	{
		char *str = "101";
		char *base_from = "01";
		char *base_to = "012345667";
		printf("\ncase 2. base contains the same character twice\n\n");
		printf("base = 012345667\n");
		printf("result = ");
		printf("%s\n", ft_convert_base(str, base_from, base_to));
	}
	{
		char *str = "101";
		char *base_from = "01";
		char *base_to = "-01234567";
		printf("\ncase 3.base contains + or - \n\n");
		printf("base = -01234567\n");
		printf("result = ");
		printf("%s\n", ft_convert_base(str, base_from, base_to));
	}
	{
		char *str = "101";
		char *base_from = "01";
		char *base_to = "0123 4567";
		printf("\ncase 4 whitespaces\n\n");
		printf("base = 0123 4567\n");
		printf("result = ");
		printf("%s\n", ft_convert_base(str, base_from, base_to));
	}
	{
		printf("------ex05-----\n");
		printf("-----case01-----\n");
		printf("eog-gga test\n");
		printf("str = "        ", charset = " "\n");
		char charset[10] = " ";
		char *str = "            ";
		char **strs = ft_split(str, charset);
		int i = 0;
		while (strs[i] != NULL)
		{
			printf("%s\n", strs[i]);
			i++;
		}
	}	
	{
		printf("-----case02-----\n");
		printf("general case\n");
		printf("str = hello!@#this@is@#general!@#test!@#, charset = !@#$\n");
		char charset[10] = "!@#$";
		char *str = "hello!@#this@is@#general!@#test!@#";
		char **strs = ft_split(str, charset);
		int i = 0;
		while (strs[i] != NULL)
		{
			printf("%s\n", strs[i]);
			i++;
		}
	}	
	{
		printf("-----case03-----\n");
		printf("charset start test\n");
		printf("str = !@#$!@#hello!@#this@is@#general!@#test!@#, charset = !@#$\n");
		char charset[10] = "!@#$";
		char *str = "!@#!@#hello!@#this@is@#general!@#test!@#";
		char **strs = ft_split(str, charset);
		int i = 0;
		while (strs[i] != NULL)
		{
			printf("%s\n", strs[i]);
			i++;
		}
	}	
	{
		printf("-----case04-----\n");
		printf("charset == str test\n");
		printf("str = abcd, charset = abcd");
		char charset[10] = "abcd";
		char *str = "abcd";
		char **strs = ft_split(str, charset);
		int i = 0;
		while (strs[i] != NULL)
		{
			printf("%s\n", strs[i]);
			i++;
		}
	}	
		printf("\n-----case05-----\n");
		printf("charset > str test\n");
		printf("str = abcd, charset = abcdefg");
		char charset[10] = "abcdefg";
		char *str = "abcd";
		char **strs = ft_split(str, charset);
		int i = 0;
		while (strs[i] != NULL)
		{
			printf("%s\n", strs[i]);
			i++;
		}
		
		{
			printf("\nDeepthought\n");
			printf("str = fx9PXm5k64d6bBkIRxxXFoylRhnGcbqIAM    7pc0xHMT, charset = """);
			char charset[10] = "";
			char *str = "fx9PXm5k64d6bBkIRxxXFoylRhnGcbqIAM    7pc0xHMT";
			char **strs = ft_split(str, charset);
			int i = 0;
			while (strs[i] != NULL)
			{
				printf("%s\n", strs[i]);
				i++;
			}
		}
}
