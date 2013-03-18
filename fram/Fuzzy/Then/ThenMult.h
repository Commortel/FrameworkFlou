#ifndef THENMULT_H_
#define THENMULT_H_
#include "Then.h"


namespace Fuzzy {

	template<class T> class ThenMult: public Core::BinaryExpression<T>
	{
	public:
	
		T evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const;
	};

	template<class T>
	T ThenMult<T> evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const
	{
		T l = left->evaluate();
		T r = right->evaluate();

		return (l * r );
	}

}

#endif
