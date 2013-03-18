#ifndef ISTRAPEZE_H
#define ISTRAPEZE_H

#include "Is.h"

namespace Fuzzy 
{
	template<class T> 
	class IsTrapeze: public Is<T>
	{
		public:
			IsTrapeze(T, T, T, T);
			virtual ~IsTrapeze(){};

			T Evaluate(Core::Expression<T>*) const;
		private:
			T min,mid1,mid2,max;
	};

	template<class T>
	IsTrapeze<T>::IsTrapeze(T _min, T _mid1, T _mid2, T _max): min(_min),mid1(_mid1),mid2(_mid2),max(_max){}

	template<class T>
	T IsTrapeze<T>::Evaluate(Core::Expression<T>* value) const
	{
		T v = value->Evaluate();

		if (v <= this->min || v >= this->max) return 0 ;

		else if (v >= this->mid1 && v <= this->mid2) return 1 ;

		else if (v >= this->min && v <= this->mid1) return (v - this->min)/(this->mid1 - this->min) ;
		
		else return (this->max - v)/(this->max - this->mid2) ;
	}
}

#endif