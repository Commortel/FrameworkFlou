#ifndef NOTMINUS_H
#define NOTMINUS_H

#include "Not.h"

namespace Fuzzy
{
	template <class T>
	class NotMinus : public Not<T>
	{
		public:
			virtual T Evaluate(Core::Expression<T>*) const;
	};

	template <class T>
	T NotMinus<T>::Evaluate(Core::Expression<T>* value) const
	{
		return -value->Evaluate();
	}
}

#endif