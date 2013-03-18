#ifndef THENMIN_H
#define THENMIN_H

#include "Then.h"

namespace Fuzzy {

	template<class T> 
	class ThenMin: public Then<T>
	{
		public:
			T Evaluate(Core::Expression<T>*, Core::Expression<T>*) const;
	};

	template<class T>
	T ThenMin<T>::Evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const
	{
		T l = left->Evaluate();
		T r = right->Evaluate();

		return (l >= r )? r : l ;
	}
}

#endif
