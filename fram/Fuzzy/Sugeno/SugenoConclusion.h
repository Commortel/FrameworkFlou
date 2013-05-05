#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H

#include "../../Core/Nary/NaryExpression.h"

namespace Fuzzy 
{
	template<class T>
	class SugenoConclusion : public core::NaryExpression<T>
	{
		public:
			SugenoConclusion(){};
			SugenoConclusion(const std::vector<T> *coef);

			virtual T Evaluate(std::vector<const Core::Expression<T>*> *operands) const;
		private:
			const std::vector<T> *coef;
	};

	template<class T>
	SugenoConclusion <T>::SugenoConclusion(const std::vector<T> *_coef):coef(_coef){}

	template<class T>
	T SugenoConclusion <T>::Evaluate(std::vector<const Core::Expression<T>*> *operands) const
	{
		if(coefs.size() >= operands.size()+1)
		{
			T oper = T(0);
			std::vector<core::Expression<T>*>::iterator itOperands= operands.begin();
			std::vector<T>::const_iterator itCoefs= coefs.begin();
			for(; itOperands!=operands.end(); ++itOperands, ++itCoefs)
			{
				oper += *itCoefs * (*itOperands)->evaluate();
			}
			return oper+ *itCoefs;
		}
		throw(std::exception());
	}
}
#endif