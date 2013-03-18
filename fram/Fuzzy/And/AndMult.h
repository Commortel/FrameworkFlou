#ifndef ANDMIN_H
#define ANDMIN_H

#include "And.h"

namespace Fuzzy
{
	template <class T>
	class AndMult : public And<T>
	{
		public:
			virtual T Evaluate(core::Expression<T>*,core::Expression<T>*) const;
	};

	template <class T>
	T AndMin<T>::Evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		T lv = l->evaluate();
		T lr = r->evaluate();

		return (lv >= lr)? r : l;
	}
}

#endif