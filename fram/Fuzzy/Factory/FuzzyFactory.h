#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

#include "../Not/Not.h"
#include "../And/And.h"
#include "../Or/Or.h"
#include "../Then/Then.h"
#include "../Agg/Agg.h"
#include "../Is/Is.h"
#include "../Mamdani/CogDefuzz.h"
#include "../Sugeno/SugenoDefuzz.h"
#include "../Sugeno/SugenoConclusion.h"

#include "../../Core/Factory/ExpressionFactory.h"
#include "../../Core/Binary/BinaryShadowExpression.h"
#include "../../Core/Unary/UnaryShadowExpression.h"
#include "../../Core/Nary/NaryShadowExpression.h"

namespace Fuzzy 
{
	template <class T>
	class FuzzyFactory : public Core::ExpressionFactory<T> 
	{
		public:
			FuzzyFactory(Not<T>*, And<T>*, Or<T>*, Then<T>*, Agg<T>*, CogDefuzz<T>*, SugenoDefuzz<T>* , SugenoConclusion<T>*);

			Core::Expression<T>* NewAnd(Core::Expression<T>*, Core::Expression<T>*);
			Core::Expression<T>* NewOr(Core::Expression<T>*, Core::Expression<T>*);
			Core::Expression<T>* NewThen(Core::Expression<T>*, Core::Expression<T>*);
			Core::Expression<T>* NewAgg(Core::Expression<T>*, Core::Expression<T>*);
			Core::Expression<T>* NewNot(Core::Expression<T>*);
			Core::Expression<T>* NewIs(Core::Expression<T>*, Fuzzy::Is<T>*);
			Core::Expression<T>* NewDefuzz(Core::Expression<T>*, Core::Expression<T>*);
			Core::Expression<T>* NewSugeno(std::vector<const Core::Expression<T>*> *);
			Core::Expression<T>* NewConclusion(std::vector<const Core::Expression<T>*> *);

			void ChangeAnd(And<T>*);
			void ChangeOr(Or<T>*);
			void ChangeThen(Then<T>*);
			void ChangeAgg(Agg<T>*);
			void ChangeNot(Not<T>*);
			void ChangeDefuzz(CogDefuzz<T>*);
			void ChangeSugeno(SugenoDefuzz<T>*);
			void ChangeConclusion(SugenoConclusion<T>*);

		private:
			Core::UnaryShadowExpression<T> oNot;
			Core::BinaryShadowExpression<T> oAnd, oOr, oThen, oAgg, oDefuzz;
			Core::NaryShadowExpression<T> oSugeno, oConclusion;
	};

	template<class T>
	FuzzyFactory<T>::FuzzyFactory(
		Not<T>* _Not, 
		And<T>* _And, 
		Or<T>* _Or, 
		Then<T>* _Then, 
		Agg<T>* _Agg,
		CogDefuzz<T>* _Defuzz, 
		SugenoDefuzz<T>* _Sugeno,
		SugenoConclusion<T>* _Conclusion)
	: oNot(new Core::UnaryShadowExpression<T>(_Not)),
	  oAnd(new Core::BinaryShadowExpression<T>(_And)),
	  oOr(new Core::BinaryShadowExpression<T>(_Or)),
	  oThen(new Core::BinaryShadowExpression<T>(_Then)),
	  oAgg(new Core::BinaryShadowExpression<T>(_Agg)),
	  oDefuzz(new Core::BinaryShadowExpression<T>(_Defuzz)),
	  oSugeno(new Core::NaryShadowExpression<T>(_Sugeno)),
	  oConclusion(new Core::NaryShadowExpression<T>(_Conclusion)){}

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
		return this->NewBinary(&oDefuzz,left,right);
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::NewSugeno(std::vector<const Core::Expression<T>*> *operands)
	{
		return this->NewNary(&oSugeno, operands);
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::NewConclusion(std::vector<const Core::Expression<T>*> *operands)
	{
		return this->NewNary(&oConclusion, operands);
	}

	template<class T>
	void FuzzyFactory<T>::ChangeAnd(And<T>* o)
	{
		oAnd.SetTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::ChangeOr(Or<T>* o)
	{
		oOr.SetTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::ChangeThen(Then<T>* o)
	{
		oThen.SetTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::ChangeAgg(Agg<T>* o)
	{
		oAgg.SetTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::ChangeNot(Not<T>* o)
	{
		oNot.SetTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::ChangeDefuzz(CogDefuzz<T>* o)
	{
		opDefuzz.SetTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::ChangeSugeno(SugenoDefuzz<T>* o)
	{
		oSugeno.SetTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::ChangeConclusion(SugenoConclusion<T>* o)
	{
		oConclusion.SetTarget(o);
	}
}
#endif
