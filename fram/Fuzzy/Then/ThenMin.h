#ifndef THENMIN_H_
#define THENMIN_H_
#include "Then.h"

namespace Fuzzy {

	template<class T> class ThenMin: public Core::BinaryExpression<T>
	{
	public:
	
		T evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const;
	};

	template<class T>
	T ThenMult<T> evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const
	{
		T l = left->evaluate();
		T r = right->evaluate();

		return (l >= r )? r : l ;
	}
}

#endif
