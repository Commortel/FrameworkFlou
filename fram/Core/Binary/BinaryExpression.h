#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "../Expression.h"

namespace Core
{
	template <class T>
	class BinaryExpression
	{
		public:
			virtual ~BinaryExpression() {}
			virtual T Evaluate(Expression<T>*,Expression<T>*) const = 0;
	};
}

#endif