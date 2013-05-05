#ifndef SUGENOTHEN_H
#define SUGENOTHEN_H

#include "../Then/Then.h"

namespace Fuzzy 
{
	template<class T> 
	class SugenoThen: public Then<T>
	{
		public:
			SugenoThen();
			virtual ~SugenoThen(){};

			T Evaluate(Core::Expression<T>*, Core::Expression<T>*) const;
			T GetPremiseValue() const;

		private:
			mutable T PremiseValue;
	};

	template<class T>
	SugenoThen<T>::SugenoThen(): PremiseValue(0){}

	template<class T>
	T SugenoThen<T>::Evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const
	{
		this->PremiseValue = left->Evaluate();
		return this->PremiseValue * right->Evaluate();
	}

	template<class T>
	T SugenoThen<T>::GetPremiseValue() const
	{
		return this->PremiseValue;
	}
}

#endif