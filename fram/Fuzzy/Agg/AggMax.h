#ifndef AGGMAX_H_
#define AGGMAX_H_
#include "Agg.h"

namespace Fuzzy {

	template<class T> class AggMax: public Core::BinaryExpression<T>
	{
	public:
	
		T evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const;
	};

	template<class T>
	T AggMax<T> evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const
	{
		T l = left->evaluate();
		T r = right->evaluate();

		return (l >= r )? l : r ;
	}
}

#endif
