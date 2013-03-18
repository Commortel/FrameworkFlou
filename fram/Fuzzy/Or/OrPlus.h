#ifndef ORPLUS_H_
#define ORPLUS_H_
#include "Or.h"

namespace Fuzzy {

	template<class T> class OrPlus: public Or<T>
	{
	public:
		OrPlus(){};
		virtual ~OrPlus(){};

		T evaluate(Core::Expression<T>*, Core::Expression<T>*) const;
	};

	template<class T>
	T OrPlus<T>::evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const
	{
		T l = left->evaluate();
		T r = right->evaluate();
		T res = l+r;
		return (res<1)? res:1;
	}
}

#endif