#ifndef IS_H
#define IS_H

#include "../../Core/Unary/UnaryExpression.h"
#include "../../Core/Expression.h"

namespace Fuzzy 
{
	template<class T> 
	class Is: public Core::UnaryExpression<T>
	{
		public:
			virtual T Evaluate(Core::Expression<T>*) const=0;
	};

}

#endif