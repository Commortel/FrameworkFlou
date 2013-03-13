#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H

#include "BinaryExpression.h"
#include "Expression.h"

namespace core
{
	template <class T>
	class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T>
	{
		public:
			BinaryExpressionModel();
			BinaryExpressionModel(BinaryExpression<T>*,Expression<T>*,Expression<T>*);
			virtual ~BinaryExpressionModel() {}

			virtual T Evaluate() const;
			virtual T Evaluate(Expression<T>*,Expression<T>*) const;

			BinaryExpression<T>* GetOperator();
			Expression<T>* GetLeft();
			Expression<T>* GetRight();

			void SetOperator(BinaryExpression<T>*);
			void SetLeft(Expression<T>*);
			void SetRight(Expression<T>*);

		private:
			Expression<T> *Left, *Right;
			BinaryExpression<T> *Ope;
	};

template <class T>
BinaryExpressionModel<T>::BinaryExpressionModel():Left(null), Right(null), Ope(null){}

template <class T>
BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T>* _ope,Expression<T>* _left,Expression<T>* _right):Left(_left), Right(_right), Ope(_ope){}

template <class T>
T BinaryExpressionModel<T>::Evaluate() const
{
	if(right == null)
		throw new NullPointerException("right expression missing !");
	if(left == null)
		throw new NullPointerException("left expression missing !");
	return Evaluate(this->left,this->right);
}

template <class T>
T BinaryExpressionModel<T>::Evaluate(Expression<T>* _left,Expression<T>* _right) const
{
	if (this->Ope == NULL)
		throw NullPointerException("operator is nul");
	return this->Ope->Evaluate(_left,_right);
}

template <class T>
BinaryExpression<T>* BinaryExpressionModel<T>::BinaryExpression<T>* GetOperator(){ return this->Ope; }

template <class T>
Expression<T>* BinaryExpressionModel<T>::GetLeft(){ return this->Left; }

template <class T>
Expression<T>* BinaryExpressionModel<T>::GetRight(){ return this->Right; }

template <class T>
void BinaryExpressionModel<T>::SetOperator(BinaryExpression<T>* _ope) {	this->Ope = _ope; }

template <class T>
void BinaryExpressionModel<T>::SetLeft(Expression<T>* _left) { this->Left = _left; }

template <class T>
void BinaryExpressionModel<T>::SetRight(Expression<T>* _right) { this->Right = _right; }

}

#endif