#ifndef ISTRIANGLE_H
#define ISTRIANGLE_H

#include "Is.h"

namespace Fuzzy 
{
	template<class T> 
	class IsTriangle: public Is<T>
	{
		public:
			IsTriangle(T, T, T);
			virtual ~IsTriangle(){};

			T Evaluate(Core::Expression<T>*) const;
		private:
			T min,mid,max;
	};

	template<class T>
	IsTriangle<T>::IsTriangle(T _min, T _mid, T _max): min(_min),mid(_mid),max(_max){}

	template<class T>
	T IsTriangle<T>::Evaluate(Core::Expression<T>* value) const
	{
		T v = value->Evaluate();

		if (v <= this->min || v >= this->max)	
			return 0;
		else 
			return ( v <= this->mid )? (v - this->min)/(this->mid - this->min) : (this->max - v)/(this->max - this->mid);
	}
}

#endif