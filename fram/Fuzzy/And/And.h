#ifndef AND_H
#define AND_H

#include "../../Core/Binary/BinaryExpression.h"
#include "../../Core/Expression.h"

namespace Fuzzy
{
	template <class T>
	class And : public Core::BinaryExpression<T>
	{
		public:
			virtual T Evaluate(Core::Expression<T>*,Core::Expression<T>*) const=0;
	};
}

#endif