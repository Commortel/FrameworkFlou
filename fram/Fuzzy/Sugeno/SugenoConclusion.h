#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H

#include "../../Core/Nary/NaryExpression.h"

namespace Fuzzy 
{
	template<class T>
	class SugenoConclusion : public Core::NaryExpression<T>
	{
		public:
			SugenoConclusion(){};
			SugenoConclusion(const std::vector<T> *coef);

			virtual T Evaluate(std::vector<const Core::Expression<T>*> *operands) const;
		private:
			const std::vector<T> * coef;
	};

	template<class T>
	SugenoConclusion <T>::SugenoConclusion(const std::vector<T> *_coef):coef(_coef){}

	template<class T>
	T SugenoConclusion <T>::Evaluate(std::vector<const Core::Expression<T>*> *operands) const
	{
		typename std::vector<T>::const_iterator itcoef = this->coef->begin();
		typename std::vector<const Core::Expression<T>*>::const_iterator itope = operands->begin();
		T res = 0;

		for(;itope != operands->end() && itcoef != this->coef->end(); itope++, itcoef++)
		{
			T eval = (*itope)->Evaluate();
			res += *itcoef * eval;
		}

		if(itope != operands->end())
			throw(std::exception());

		return res;
	}
}
#endif