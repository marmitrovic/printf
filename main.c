#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	res_ft;
	int	res_std;
	void	*ptr;

	ptr = &res_ft;
	printf("=========================================\n");
	printf("           TESTIRANJE FT_PRINTF          \n");
	printf("=========================================\n\n");

	// 1. Test za %c
	printf("--- %%c (Karakter) ---\n");
	res_ft = ft_printf("Moj  : [%c]\n", 'A');
	res_std = printf("Pravi: [%c]\n", 'A');
	printf("Return -> Moj: %d | Pravi: %d\n\n", res_ft, res_std);

	// 2. Test za %s
	printf("--- %%s (String) ---\n");
	res_ft = ft_printf("Moj  : [%s]\n", "Pozdrav 42!");
	res_std = printf("Pravi: [%s]\n", "Pozdrav 42!");
	printf("Return -> Moj: %d | Pravi: %d\n\n", res_ft, res_std);

	// Zameniti linije za NULL test sa ovim:
	char *null_str = NULL;
	res_ft = ft_printf("Moj  (NULL): [%s]\n", null_str);
	res_std = printf("Pravi(NULL): [%s]\n", null_str);
	printf("Return -> Moj: %d | Pravi: %d\n\n", res_ft, res_std);

	// 3. Test za %p
	printf("--- %%p (Pokazivac) ---\n");
	res_ft = ft_printf("Moj  : [%p]\n", ptr);
	res_std = printf("Pravi: [%p]\n", ptr);
	printf("Return -> Moj: %d | Pravi: %d\n\n", res_ft, res_std);

	// 4. Test za %d i %i
	printf("--- %%d / %%i (Brojevi) ---\n");
	res_ft = ft_printf("Moj  : [%d] [%i]\n", (int)-2147483648, 2147483647);
	res_std = printf("Pravi: [%d] [%i]\n", (int)-2147483648, 2147483647);
	printf("Return -> Moj: %d | Pravi: %d\n\n", res_ft, res_std);

	// 5. Test za %u
	printf("--- %%u (Unsigned) ---\n");
	res_ft = ft_printf("Moj  : [%u]\n", 4294967295U);
	res_std = printf("Pravi: [%u]\n", 4294967295U);
	printf("Return -> Moj: %d | Pravi: %d\n\n", res_ft, res_std);

	// 6. Test za %x i %X
	printf("--- %%x / %%X (Hex) ---\n");
	res_ft = ft_printf("Moj  : [%x] [%X]\n", 255, 255);
	res_std = printf("Pravi: [%x] [%X]\n", 255, 255);
	printf("Return -> Moj: %d | Pravi: %d\n\n", res_ft, res_std);

	// 7. Test za %%
	printf("--- %%%% (Procenat) ---\n");
	res_ft = ft_printf("Moj  : [%%]\n");
	res_std = printf("Pravi: [%%]\n");
	printf("Return -> Moj: %d | Pravi: %d\n\n", res_ft, res_std);

	return (0);
}