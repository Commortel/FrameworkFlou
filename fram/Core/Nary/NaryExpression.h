#ifndef NARYEXPRESSION_H
#define NARYEXPRESSION_H

#include "../Expression.h"
#include <vector>

namespace Core 
{
	template<class T>
	class NaryExpression 
	{
		public:
			virtual T Evaluate(std::vector<const Expression<T>*> *) const =0;
	};

}

#endif 