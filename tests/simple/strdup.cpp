#include <cstring>
#include <cassert>
#include <iostream>

extern "C" {
	char	*ft_strdup(const char *);
}

void test_strdup()
{
	char    *systemCall;
	char	*betonicCall;
	char	str[] = "Hello World";

	systemCall = strdup(str);
	betonicCall = ft_strdup(str);

	std::cout << systemCall << std::endl;
	std::cout << betonicCall << std::endl;

	// assert(!memcmp(systemCall, betonicCall, size));
}
