#ifndef NARYSHADOWEXPRESSION_H
#define NARYSHADOWEXPRESSION_H

#include "NaryExpression.h"

namespace Core 
{
	template <class T>
	class NaryShadowExpression : public NaryExpression<T> 
	{
		public:
			NaryShadowExpression();
			NaryShadowExpression(NaryExpression<T> *);
			virtual ~NaryShadowExpression() {};

			T Evaluate(std::vector<const Core::Expression<T>*> *) const;
			void SetTarget(NaryExpression<T> *);

		private:
			NaryExpression<T>* Target;
	};

	template<class T>
	NaryShadowExpression<T>::NaryShadowExpression(){}

	template<class T>
	NaryShadowExpression<T>::NaryShadowExpression(NaryExpression<T> * t):Target(t){}

	template<class T>
	T NaryShadowExpression<T>::Evaluate(std::vector<const Expression<T>*> *_operands) const
	{
		if(this->Target != NULL)
			return this->Target->Evaluate(_operands);
		throw(std::exception());
	}

	template<class T>
	void NaryShadowExpression<T>::SetTarget(NaryExpression<T> *_Target)
	{
		this->Target = _Target;
	}
}

#endif