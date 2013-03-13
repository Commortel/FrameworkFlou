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

			BinaryExpression<T>* getOperator();
			Expression<T>* getLeft();
			Expression<T>* getRight();

			void setOperator(BinaryExpression<T>*);
			void setLeft(Expression<T>*);
			void setRight(Expression<T>*);

		private:
			Expression<T> *left, *right;
			BinaryExpression<T> *ope;
	};

template <class T>
BinaryExpressionModel<T>::BinaryExpressionModel():left(null), right(null), ope(null){}

template <class T>
BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T>* _ope,Expression<T>* _left,Expression<T>* _right):left(_left), right(_right), ope(_ope){}

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
	if (this->ope == NULL)
		throw NullPointerException("operator is nul");
	return this->ope->Evaluate(_left,_right);
}

template <class T>
BinaryExpression<T>* BinaryExpressionModel<T>::BinaryExpression<T>* getOperator(){ return this->op; }

template <class T>
Expression<T>* BinaryExpressionModel<T>::getLeft(){ return this->left; }

template <class T>
Expression<T>* BinaryExpressionModel<T>::getRight(){ return this->right; }

template <class T>
void BinaryExpressionModel<T>::setOperator(BinaryExpression<T>* _ope) {	this->ope = _ope; }

template <class T>
void BinaryExpressionModel<T>::setLeft(Expression<T>* _left) { this->left = _left; }

template <class T>
void BinaryExpressionModel<T>::setRight(Expression<T>* _right) { this->right = _right; }

}

#endif