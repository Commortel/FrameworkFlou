#ifndef NARYEXPRESSIONMODEL_H
#define NARYEXPRESSIONMODEL_H

#include "NaryExpression.h"


namespace Core 
{
	template <class T>
	class NaryExpressionModel : public Core::NaryExpression<T>, public Core::Expression<T> 
	{
		public:
			NaryExpressionModel(Core::NaryExpression<T>*, std::vector<const Core::Expression<T>*>*);
			virtual ~NaryExpressionModel() {};

			T Evaluate() const;
			T Evaluate(std::vector<const Expression<T>*> *) const;

		private:
			std::vector<const Expression<T>*> * operands;
			NaryExpression<T> * op;
	};

	template<class T>
	NaryExpressionModel<T>::NaryExpressionModel(Core::NaryExpression<T>* _op, std::vector<const Core::Expression<T>*> *_operands)
	: op(_op), operands(_operands){}

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
