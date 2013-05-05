#ifndef THEN_H_
#define THEN_H_

#include "../../Core/Binary/BinaryExpression.h"

namespace Fuzzy 
{
	template<class T> 
	class Then: public Core::BinaryExpression<T>
	{
		public:	
			virtual T Evaluate(Core::Expression<T>*, Core::Expression<T>*) const=0;
	};

}

#endif
