#include "ft_printf.h"
#include <stdio.h>
int main()
{
    int ret;
    int mode;
    ft_printf("ft d = %d\n", 42);
    ft_printf("ft d = %d\n", -42);
    ft_printf("ft d = %d\n", 0);
    printf("pf d = %d\n", 42);
    printf("pf d = %d\n", -42);
    printf("pf d = %d\n", 0);
    ft_printf("------------------\n");
    ft_printf("ft i = %i\n", 42);
    ft_printf("ft i = %i\n", -42);
    ft_printf("ft i = %i\n", 0);
    printf("pf i = %i\n", 42);
    printf("pf i = %i\n", -42);
    printf("pf i = %i\n", 0);
    ft_printf("------------------\n");
    ft_printf("ft u = %u\n", 42);
    ft_printf("ft u = %u\n", -42);
    ft_printf("ft u = %u\n", 0);
    printf("pf u = %u\n", 42);
    printf("pf u = %u\n", -42);
    printf("pf u = %u\n", 0);
    ft_printf("------------------\n");
    ft_printf("ft c = %c\n", '-');
    ft_printf("ft c = %c\n", 'c');
    ft_printf("ft c = %c\n", '\0');
    printf("pf c = %c\n", '-');
    printf("pf c = %c\n", 'c');
    printf("pf c = %c\n", '\0');
    ft_printf("------------------\n");
    ft_printf("ft s = %s\n", "42seoul");
    printf("pf s = %s\n", "42seoul");
    ft_printf("------------------\n");
    ft_printf("ft x = %x\n", 42);
    ft_printf("ft x = %x\n", -42);
    ft_printf("ft x = %x\n", 0);
    printf("pf x = %x\n", 42);
    printf("pf x = %x\n", -42);
    printf("pf x = %x\n", 0);
    ft_printf("------------------\n");
    ft_printf("ft X = %X\n", 42);
    ft_printf("ft X = %X\n", -42);
    ft_printf("ft X = %X\n", 0);
    printf("pf X = %X\n", 42);
    printf("pf X = %X\n", -42);
    printf("pf X = %X\n", 0);
    ft_printf("------------------\n");
    ft_printf("ft p = %p\n", &ret);
    ft_printf("ft p = %p\n", NULL);
    printf("pf p = %p\n", &ret);
    printf("pf p = %p\n", NULL);
    return (0);
}
