#ifndef UTILS_H
#define UTILS_H

#ifndef ASSERT_ON
	#define ASSERT(x)
#else
	#define ASSERT(x) \
	if (!(x)) \
	{ \
	std::cout << std ::endl << "ASSERT ERROR "<< #x << " failed" << std::endl; \
	std::cout << "on line " << __LINE__ << std::endl; \
	std::cout << "in file " << __FILE__ << std::endl; \
	}
#endif
#endif