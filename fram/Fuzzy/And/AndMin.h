#ifndef ANDMIN_H
#define ANDMIN_H

#include "And.h"

namespace Fuzzy
{
	template <class T>
	class AndMin : public And<T>
	{
		public:
			T Evaluate(Core::Expression<T>*,Core::Expression<T>*) const;
	};

	template <class T>
	T AndMin<T>::Evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const
	{
		T l = left->Evaluate();
		T r = right->Evaluate();

		return (l >= r)? r : l;
	}
}

#endif