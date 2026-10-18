#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	res_ft;
	int	res_std;
	void	*ptr;

	ptr = &res_ft;
	printf("=========================================\n");
	printf("           TESTING FT_PRINTF          \n");
	printf("=========================================\n\n");

	// 1. Test za %c
	printf("--- %%c (Character) ---\n");
	res_ft = ft_printf("My ftprint: [%c]\n", 'A');
	res_std = printf("std printf: [%c]\n", 'A');
	printf("Return -> My ftprint: %d | std printf: %d\n\n", res_ft, res_std);

	// 2. Test za %s
	printf("--- %%s (String) ---\n");
	res_ft = ft_printf("My ftprint: [%s]\n", "HELLO 42!");
	res_std = printf("std printf: [%s]\n", "HELLO 42!");
	printf("Return -> My ftprint: %d | std printf: %d\n\n", res_ft, res_std);

	// Zameniti linije za NULL test sa ovim:
	char *null_str = NULL;
	res_ft = ft_printf("My ftprint (NULL): [%s]\n", null_str);
	res_std = printf("std printf (NULL): [%s]\n", null_str);
	printf("Return -> My ftprint: %d | std printf: %d\n\n", res_ft, res_std);

	// 3. Test za %p
	printf("--- %%p (Pointer) ---\n");
	res_ft = ft_printf("My ftprint: [%p]\n", ptr);
	res_std = printf("std printf: [%p]\n", ptr);
	printf("Return -> My ftprint: %d | std printf: %d\n\n", res_ft, res_std);

	// 4. Test za %d i %i
	printf("--- %%d / %%i (Numbers) ---\n");
	res_ft = ft_printf("My ftprint: [%d] [%i]\n", (int)-2147483648, 2147483647);
	res_std = printf("std printf: [%d] [%i]\n", (int)-2147483648, 2147483647);
	printf("Return -> Mine  ft_printf: %d | std printf: %d\n\n", res_ft, res_std);

	// 5. Test za %u
	printf("--- %%u (Unsigned) ---\n");
	res_ft = ft_printf("My ftprint: [%u]\n", 4294967295U);
	res_std = printf("std printf: [%u]\n", 4294967295U);
	printf("Return -> Mine ft_printf: %d | std printf: %d\n\n", res_ft, res_std);

	// 6. Test za %x i %X
	printf("--- %%x / %%X (Hex) ---\n");
	res_ft = ft_printf("My ftprint: [%x] [%X]\n", 255, 255);
	res_std = printf("std printf: [%x] [%X]\n", 255, 255);
	printf("Return -> My ftprint: %d | std printf: %d\n\n", res_ft, res_std);

	// 7. Test za %%
	printf("--- %%%% (Procentage) ---\n");
	res_ft = ft_printf("My ftprint: [%%]\n");
	res_std = printf("std printf: [%%]\n");
	printf("Return -> My ftprint: %d | std printf: %d\n\n", res_ft, res_std);

	return (0);
}