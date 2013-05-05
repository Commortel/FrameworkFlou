#ifndef NOT_H
#define NOT_H

#include "../../Core/Unary/UnaryExpression.h"

namespace Fuzzy
{
	template <class T>
	class Not : public Core::UnaryExpression<T>
	{
		public:
			virtual T Evaluate(Core::Expression<T>*) const=0;
	};
}

#endif