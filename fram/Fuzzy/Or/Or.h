#ifndef OR_H
#define OR_H

#include "../../Core/Binary/BinaryExpression.h"

namespace Fuzzy 
{
	template<class T> 
	class Or: public Core::BinaryExpression<T>
	{
		public:
			virtual T Evaluate(Core::Expression<T>*, Core::Expression<T>*) const=0;
	};

}

#endif