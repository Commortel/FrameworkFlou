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

			UnaryExpression<T>* GetOperator();
			Expression<T>* GetOperand();

			void SetOperator(UnaryExpression<T>*);
			void SetOperand(Expression<T>*);

		private:
			Expression<T> *Operand;
			UnaryExpression<T> *Ope;
	};

	template <class T>
	UnaryExpressionModel<T>::UnaryExpressionModel():Operand(NULL), Ope(NULL){}

	template <class T>
	UnaryExpressionModel<T>::UnaryExpressionModel(UnaryExpression<T>* _ope,Expression<T>* _operand):Operand(_operand), Ope(_ope){}

	template <class T>
	T UnaryExpressionModel<T>::Evaluate() const
	{
		if(this->operand == NULL)
			throw new NullPointerException("operand expression missing !");
		return Evaluate(this->Operand);
	}

	template <class T>
	T UnaryExpressionModel<T>::Evaluate(Expression<T>* _operand) const
	{
		if (this->Ope == NULL)
			throw NullPointerException("operator is nul");
		return this->Ope->Evaluate(_operand);
	}

	template <class T>
	UnaryExpression<T>* UnaryExpressionModel<T>::GetOperator(){ return this->Ope; }

	template <class T>
	Expression<T>* UnaryExpressionModel<T>::GetOperand(){ return this->Operand; }

	template <class T>
	void UnaryExpressionModel<T>::SetOperator(UnaryExpression<T>* _ope) { this->Ope = _ope; }

	template <class T>
	void UnaryExpressionModel<T>::SetOperand(Expression<T>* _operand) { this->Operand = _operand; }

}

#endif