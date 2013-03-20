#ifndef UNARYSHADOWEXPRESSION_H
#define UNARYSHADOWEXPRESSION_H

#include "UnaryExpression.h"

namespace Core
{
	template <class T>
	class UnaryShadowExpression : public UnaryExpression<T>
	{
		public:
			UnaryShadowExpression(UnaryExpression<T>*);

			void SetTarget(UnaryExpression<T>*);
			UnaryExpression<T>* GetTarget() const;
			T Evaluate(Expression<T>* ) const;
		private:
			UnaryExpression<T>* Target;
	};

	template <class T>
	UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T>* target):Target(target){}

	template <class T>
	void UnaryShadowExpression<T>::SetTarget(UnaryExpression<T>* target)
	{
		this->Target = target;
	}

	template <class T>
	UnaryExpression<T>* UnaryShadowExpression<T>::GetTarget() const
	{
		return this->Target;
	}

	template <class T>
	T UnaryShadowExpression<T>::Evaluate(Expression<T>* o) const 
	{
		return this->Target->Evaluate(o);
	}

}
#endif