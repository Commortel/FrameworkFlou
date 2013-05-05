#ifndef NARYEXPRESSIONMODEL_H_
#define NARYEXPRESSIONMODEL_H_

#include "../Expression.h"
#include "NaryExpression.h"


namespace Core 
{
	template <class T>
	class NaryExpressionModel : public Core::NaryExpression<T>, public Core::Expression<T> 
	{
		public:
			NaryExpressionModel(std::vector<const Core::Expression<T>*>*, Core::NaryExpression<T>*);
			virtual ~NaryExpressionModel() {};

			T Evaluate() const;
			T Evaluate(std::vector<const Expression<T>*> *) const;

		private:
			std::vector<const Expression<T>*> * operands;
			NaryExpression<T> * op;
	};

	template<class T>
	NaryExpressionModel<T>::NaryExpressionModel(std::vector<const Core::Expression<T>*> *_operands, Core::NaryExpression<T>* _op)
	: operands(_operands), op(_op){}

	template<class T>
	T NaryExpressionModel<T>::Evaluate() const
	{
		if(this->operands != NULL)
			return this->Evaluate(this->operands);

		throw(std::exception());
	}

	template<class T>
	T NaryExpressionModel<T>::Evaluate(std::vector<const Core::Expression<T>*> *_operands) const
	{
		if(this->op != NULL)
			return this->op->Evaluate(_operands);

		throw(std::exception());
	}
}

#endif 
