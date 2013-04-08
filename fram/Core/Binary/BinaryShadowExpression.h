#ifndef BINARYSHADOWEXPRESSION_H
#define BINARYSHADOWEXPRESSION_H

#include "BinaryExpression.h"
#include "../Expression.h"

namespace Core
{
	template <class T>
	class BinaryShadowExpression : public BinaryExpression<T>
	{
		public:
			BinaryShadowExpression(BinaryExpression<T>*);
			~BinaryShadowExpression();

			virtual void SetTarget(BinaryExpression<T>*);
			BinaryExpression<T>* GetTarget() const;
			virtual T Evaluate(Core::Expression<T>* ,Core::Expression<T>* ) const;

		private:
			Core::BinaryExpression<T>* Target;
	};

	template <class T>
	BinaryShadowExpression<T>::BinaryShadowExpression(Core::BinaryExpression<T>* t):Target(t){}

	template <class T>
	BinaryShadowExpression<T>::~BinaryShadowExpression()
	{
		this->Target->~BinaryExpression();
	}

	template <class T>
	void BinaryShadowExpression<T>::SetTarget(BinaryExpression<T>* target)
	{
		this->Target = target;
	}

	template <class T>
	BinaryExpression<T>* BinaryShadowExpression<T>::GetTarget() const
	{
		return this->Target;
	}	

	template <class T>
	T BinaryShadowExpression<T>::Evaluate(Core::Expression<T> * left,Core::Expression<T> * right) const
	{
		if(this->Target != NULL)
			return this->Target->Evaluate(left,right);
		return NULL;
	}
}

#endif