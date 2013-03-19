#ifndef ISTRAPEZELEFT_H
#define ISTRAPEZELEFT_H

#include "Is.h"

namespace Fuzzy 
{
	template<class T> 
	class IsTrapezeLeft: public Is<T>
	{
		public:
			IsTrapezeLeft(T,T,T);
			virtual ~IsTrapezeLeft(){};

			T Evaluate(Core::Expression<T>*) const;
		private:
			T min,mid,max;
	};

	template<class T>
	IsTrapezeLeft<T>::IsTrapezeLeft(T _min,T _mid,T _max): min(_min),mid(_mid),max(_max){}

	template<class T>
	T IsTrapezeLeft<T>::Evaluate(Core::Expression<T>* value) const
	{
		T v = value->Evaluate();

		if (v <= this->min || v >= this->max) return 0;

		else if (v >= this->min && v <= this->mid) return (v - this->min)/(this->mid - this->min) ;
		
		else return 1;
	}
}

#endif