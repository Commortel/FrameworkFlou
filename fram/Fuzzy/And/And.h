#ifndef AND_H
#define AND_H

#include "../../core/Binary/BinaryExpression.h"
#include "../../core/Expression.h"

namespace Fuzzy
{
	template <class T>
	class And : public core::BinaryExpression<T>
	{
		public:
			virtual T Evaluate(core::Expression<T>*,core::Expression<T>*) const=0;
	};
}

#endif