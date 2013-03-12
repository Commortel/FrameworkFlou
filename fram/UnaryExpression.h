#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

#include "Expression.h"

namespace core
{
	template <class T>
	class UnaryExpression
	{
		public:
			virtual ~UnaryExpression() {}
			virtual T Evaluate(Expression<T>*) = 0;
	};
}

#endif