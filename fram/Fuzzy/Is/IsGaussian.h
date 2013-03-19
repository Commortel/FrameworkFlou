#ifndef ISGAUSSIAN_H
#define ISGAUSSIAN_H

#include "Is.h"
#include <math.h>

namespace Fuzzy 
{
	template<class T> 
	class IsGaussian: public Is<T>
	{
		public:
			IsGaussian(T, T);
			virtual ~IsGaussian(){};

			T Evaluate(Core::Expression<T>*) const;
		private:
			T mu, sigma;
	};

	template<class T>
	IsGaussian<T>::IsGaussian(T _mu, T _sigma): mu(_mu), sigma(_sigma){}

	template<class T>
	T IsGaussian<T>::Evaluate(Core::Expression<T>* value) const
	{
		T v = value->Evaluate();
		T coef = (v-this->mu)/this->sigma;

		return exp(-0.5*coef*coef);
	}
}

#endif