#ifndef ISTRAPEZERIGHT_H
#define ISTRAPEZERIGHT_H

#include "Is.h"

namespace Fuzzy 
{
	template<class T> 
	class IsTrapezeRight: public Is<T>
	{
		public:
			IsTrapezeRight(T,T,T);
			virtual ~IsTrapezeRight(){};

			T Evaluate(Core::Expression<T>*) const;
		private:
			T min,mid,max;
	};

	template<class T>
	IsTrapezeRight<T>::IsTrapezeRight(T _min,T _mid,T _max): min(_min),mid(_mid),max(_max){}

	template<class T>
	T IsTrapezeRight<T>::Evaluate(Core::Expression<T>* value) const
	{
		T v = value->Evaluate();

		if (v <= this->min || v >= this->max) return 0;

		else if (v >= this->mid && v <= this->max) return (this->max - v)/(this->max - this->mid);
		
		else return 1;
	}
}

#endif