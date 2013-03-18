#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

#include "../Expression.h"

namespace Core
{
	template <class T>
	class UnaryExpression
	{
		public:
			virtual ~UnaryExpression() {}
			virtual T Evaluate(Expression<T>*) const = 0;
	};
}

#endif