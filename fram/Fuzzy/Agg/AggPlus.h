#ifndef AGGPLUS_H
#define AGGPLUS_H

#include "Agg.h"

namespace Fuzzy 
{
	template<class T> 
	class AggPlus: public Agg<T>
	{
		public:	
			T Evaluate(Core::Expression<T>*, Core::Expression<T>*) const;
	};

	template<class T>
	T AggPlus<T>::Evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const
	{
		T l = left->Evaluate();
		T r = right->Evaluate();

		return (l + r );
	}
}

#endif
