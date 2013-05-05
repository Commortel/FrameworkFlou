#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include "../Expression.h"
#include "../Binary/BinaryExpression.h"
#include "../Unary/UnaryExpression.h"
#include "../Binary/BinaryExpressionModel.h"
#include "../Unary/UnaryExpressionModel.h"
#include "../Nary/NaryExpressionModel.h"
#include <set>

namespace Core
{
	template <class T> 
	class ExpressionFactory
	{
		public:
			ExpressionFactory();
			virtual ~ExpressionFactory();

			Expression<T>* Hold(Expression<T> *);

		protected:
			Expression<T>* NewUnary(UnaryExpression<T> *, Expression<T> *);
			Expression<T>* NewBinary(BinaryExpression<T> *, Expression<T> *, Expression<T> *);
			Expression<T>* NewNary(NaryExpression<T>* , std::vector<Expression<T>* > *);

		private:
			std::set<Expression<T> *> * memory;
	};

	template <class T>
	ExpressionFactory<T>::ExpressionFactory(): memory(new std::set<Expression<T>* >){}

	template <class T>
	ExpressionFactory<T>::~ExpressionFactory() 
	{
		delete this->memory;
	}

	template <class T>
	Expression<T>* ExpressionFactory<T>::Hold(Expression<T> * o)
	{
		this->memory->insert(o);
		return o;
	}

	template <class T>
	Expression<T>* ExpressionFactory<T>::NewUnary(UnaryExpression<T> * o, Expression<T> * operands)
	{
		return (UnaryExpressionModel<T>*)this->Hold(new UnaryExpressionModel<T>(o,operands));
	}

	template <class T>
	Expression<T>* ExpressionFactory<T>::NewBinary(BinaryExpression<T> * o, Expression<T> * left,Expression<T> * right)
	{
		return (BinaryExpressionModel<T>*)this->Hold(new BinaryExpressionModel<T>(o,right,left));
	}

	template<class T>
	Expression<T>* ExpressionFactory<T>::newNary(NaryExpression<T>* o, std::vector<Expression<T>*> operands)
	{
		return hold(new NaryExpressionModel<T>(o, operands));
	}
}

#endif