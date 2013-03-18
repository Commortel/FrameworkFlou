#ifndef THENMULT_H
#define THENMULT_H

#include "Then.h"

namespace Fuzzy 
{
	template<class T> 
	class ThenMult: public Then<T>
	{
		public:
			T Evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const;
	};

	template<class T>
	T ThenMult<T>::Evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const
	{
		T l = left->Evaluate();
		T r = right->Evaluate();

		return (l * r);
	}

}

#endif
