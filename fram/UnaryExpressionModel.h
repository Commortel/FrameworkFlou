#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H

#include "Expression.h"
#include "UnaryExpression.h"

namespace core
{
	template <class T>
	class UnaryExpressionModel:public UnaryExpression<T>, public Expression<T>
	{
		public:
			UnaryExpressionModel();
			UnaryExpressionModel(UnaryExpression<T>*,Expression<T>*);
			virtual ~UnaryExpressionModel(){}

			virtual T Evaluate() const;
			virtual T Evaluate(Expression<T>*) const;

			UnaryExpression<T>* getOperator();
			Expression<T>* getOperand();

			void setOperator(UnaryExpression<T>*);
			void setOperand(Expression<T>*);

		private:
			Expression<T> *operand;
			UnaryExpression<T> *ope;
	};

	template <class T>
	UnaryExpressionModel<T>::UnaryExpressionModel():operand(NULL), ope(NULL){}

	template <class T>
	UnaryExpressionModel<T>::UnaryExpressionModel(UnaryExpression<T>* _ope,Expression<T>* _operand):operand(_operand), ope(_ope){}

	template <class T>
	T UnaryExpressionModel<T>::Evaluate() const
	{
		if(this->operand == NULL)
			throw new NullPointerException("operand expression missing !");
		return Evaluate(this->operand);
	}

	template <class T>
	T UnaryExpressionModel<T>::Evaluate(Expression<T>* _operand) const
	{
		if (this->ope == NULL)
			throw NullPointerException("operator is nul");
		return this->ope->Evaluate(_operand);
	}

	template <class T>
	UnaryExpression<T>* UnaryExpressionModel<T>::getOperator(){ return this->ope; }

	template <class T>
	Expression<T>* UnaryExpressionModel<T>::getOperand(){ return this->operand; }

	template <class T>
	void UnaryExpressionModel<T>::setOperator(UnaryExpression<T>* _ope) { this->ope = _ope; }

	template <class T>
	void UnaryExpressionModel<T>::setOperand(Expression<T>* _operand) { this->operand = _operand; }

}

#endif