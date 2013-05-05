#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

#include "../Not/Not.h"
#include "../And/And.h"
#include "../Or/Or.h"
#include "../Then/Then.h"
#include "../Agg/Agg.h"
#include "../Is/Is.h"
#include "../Mamdani/CogDefuzz.h"

#include "../../Core/Factory/ExpressionFactory.h"
#include "../../Core/Binary/BinaryShadowExpression.h"
#include "../../Core/Unary/UnaryShadowExpression.h"

namespace Fuzzy 
{
	template <class T>
	class FuzzyFactory : public Core::ExpressionFactory<T> 
	{
		public:
			FuzzyFactory(Not<T>*, And<T>*, Or<T>*, Then<T>*, Agg<T>*, CogDefuzz<T>*);

			Core::Expression<T>* NewAnd(Core::Expression<T>*, Core::Expression<T>*);
			Core::Expression<T>* NewOr(Core::Expression<T>*, Core::Expression<T>*);
			Core::Expression<T>* NewThen(Core::Expression<T>*, Core::Expression<T>*);
			Core::Expression<T>* NewAgg(Core::Expression<T>*, Core::Expression<T>*);
			Core::Expression<T>* NewNot(Core::Expression<T>*);
			Core::Expression<T>* NewIs(Core::Expression<T>*, Fuzzy::Is<T>*);
			Core::Expression<T>* NewDefuzz(Core::Expression<T>*, Core::Expression<T>*);

		private:
			Core::UnaryShadowExpression<T> oNot;
			Core::BinaryShadowExpression<T> oAnd, oOr, oThen, oAgg, opDefuzz;
	};

	template<class T>
	FuzzyFactory<T>::FuzzyFactory(Not<T>* _Not, And<T>* _And, Or<T>* _Or, Then<T>* _Then, Agg<T>* _Agg,CogDefuzz<T>* _Defuzz)
	: oNot(new Core::UnaryShadowExpression<T>(_Not)),
	  oAnd(new Core::BinaryShadowExpression<T>(_And)),
	  oOr(new Core::BinaryShadowExpression<T>(_Or)),
	  oThen(new Core::BinaryShadowExpression<T>(_Then)),
	  oAgg(new Core::BinaryShadowExpression<T>(_Agg)),
	  opDefuzz(new Core::BinaryShadowExpression<T>(_Defuzz)){}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::NewAnd(Core::Expression<T>* left, Core::Expression<T>* right)
	{
		return this->NewBinary(&oAnd, left, right);
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::NewOr(Core::Expression<T>* left, Core::Expression<T>* right)
	{
		return this->NewBinary(&oOr, left, right);
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::NewThen(Core::Expression<T>* left, Core::Expression<T>* right)
	{
		return this->NewBinary(&oThen, left, right);
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::NewAgg(Core::Expression<T>* left, Core::Expression<T>* right)
	{
		return this->NewBinary(&oAgg, left, right);
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::NewNot(Core::Expression<T>* o)
	{
		return this->NewUnary(&oNot, o);
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::NewIs(Core::Expression<T>* o, Fuzzy::Is<T>* is)
	{
		return this->NewUnary(is, o);
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::NewDefuzz(Core::Expression<T>* left, Core::Expression<T>* right)
	{
		return this->NewBinary(&opDefuzz,left,right);
	}
}
#endif
