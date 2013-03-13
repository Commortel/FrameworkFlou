#ifndef ANDMIN_H
#define ANDMIN_H

#include "And.h"

namespace fuzzy
{
	template <class T>
	class AndMin : public And<T>
	{
		public:
			virtual T Evaluate(core::Expression<T>*,core::Expression<T>*) const;
	};

	template <class T>
	T AndMin<T>::Evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		T lv = l->Evaluate();
		T lr = r->Evaluate();

		return (lv >= lr)? r : l;
	}
}

#endif