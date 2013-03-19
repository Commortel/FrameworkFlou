#ifndef ISBELL_H
#define ISBELL_H

#include "Is.h"
#include <math.h>

namespace Fuzzy 
{
	template<class T> 
	class IsBell: public Is<T>
	{
		public:
			IsBell(T,T,T);
			virtual ~IsBell(){};

			T Evaluate(Core::Expression<T>*) const;
		private:
			T min, center, max;
	};

	template<class T>
	IsBell<T>::IsBell(T _min, T _max, T _center): min(_min), center(_center), max(_max){}

	template<class T>
	T IsBell<T>::Evaluate(Core::Expression<T>* value) const
	{
		T v = value->Evaluate();

		return 1/(1+std::pow(std::abs((v-this->center)/this->min),(2*this->max)));
	}
}

#endif