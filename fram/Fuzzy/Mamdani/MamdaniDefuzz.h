#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H

#include "../../Core/Binary/BinaryExpression.h"

namespace Fuzzy
{
	template<class T>
	class MandaniDefuzz : public Core::BinaryExpression<T>
	{
		public:
			virtual T Evaluate(Core::Expression<T>*) const=0;
	};
}

#endif