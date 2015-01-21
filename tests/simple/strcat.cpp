#include <iostream>
#include <cstring>
#include <assert.h>

extern "C" {
    char *ft_strcat(char *dest, char *src);
}

void	test_strcat()
{
	char	*systemCall;
	char	*betonicCall;

	char	*dest = (char*)malloc(11);
	dest[0] = 't';
	dest[1] = 'e';
	dest[2] = 's';
	dest[3] = 't';
	dest[4] = '\0';
	char	src[] = "reussi";

	char	*dest1 = (char*)malloc(11);
	dest1[0] = 't';
	dest1[1] = 'e';
	dest1[2] = 's';
	dest1[3] = 't';
	dest1[4] = '\0';
	char	src1[] = "reussi";


	systemCall = strcat(dest, src);
	betonicCall = ft_strcat(dest1, src1);

	std::cout << systemCall << std::endl;
	std::cout << betonicCall << std::endl;

	assert(systemCall == betonicCall);
}