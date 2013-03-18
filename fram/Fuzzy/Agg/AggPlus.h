#ifndef AGGPLUS_H_
#define AGGPLUS_H_
#include "Agg.h"

namespace Fuzzy {

	template<class T> class AggPlus: public Core::BinaryExpression<T>
	{
	public:
	
		T evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const;
	};

	template<class T>
	T AggPlus<T> evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const
	{
		T l = left->evaluate();
		T r = right->evaluate();

		return (l + r );
	}
}

#endif
