#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "Expression.h"

namespace core
{
	template <class T>
	class BinaryExpression
	{
		public:
			virtual ~BinaryExpression() {}
			virtual T Evaluate(Expression<T>*,Expression<T>*) = 0;
	};
}

#endif