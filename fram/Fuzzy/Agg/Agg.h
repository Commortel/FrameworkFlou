#ifndef AGG_H
#define AGG_H

#include "../../Core/Binary/BinaryExpression.h"

namespace Fuzzy 
{
	template<class T> 
	class Agg: public Core::BinaryExpression<T>
	{
		public:	
			virtual T Evaluate(Core::Expression<T>*, Core::Expression<T>*) const=0;
	};

}

#endif
