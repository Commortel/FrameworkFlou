#ifndef SUGENODEFUZZ_H
#define SUGENODEFUZZ_H

#include "../../Core/Nary/NaryExpression.h"
#include "../../Core/Binary/BinaryExpressionModel.h"
#include "SugenoThen.h"

namespace Fuzzy 
{
	template<class T>
	class SugenoDefuzz : public Core::NaryExpression<T>
	{
		public:
			SugenoDefuzz ();
			virtual ~SugenoDefuzz () {}; 

			virtual T Evaluate(std::vector<const core::Expression<T>*> *operands) const;
	};

	template<class T>
	SugenoDefuzz<T>::SugenoDefuzz (){}

	template<class T>
	T SugenoDefuzz<T>::Evaluate(std::vector<const Core::Expression<T>*> *operands) const
	{
		typename std::vector<const Core::Expression<T>*>::const_iterator it ;
		T num = 0, denum = 0;

		for(it = operands->begin(); it != operands->end(); it++)
		{
			num += (*it)->Evaluate();
		}

		for(it = operands->begin(); it != operands->end(); it++)
		{
			Core::BinaryExpressionModel<T> *bem = (Core::BinaryExpressionModel<T>*) (*it);
			Core::BinaryShadowExpression<T> *bse = (Core::BinaryShadowExpression<T>*) bem->GetOperator();
			SugenoThen<T> *st = (SugenoThen<T>*) bse->GetTarget();

			denum += st->GetPremiseValue();
		}

		if(denum != 0)
			return num/denum;
		else
			return 0;
	}

}
#endif 