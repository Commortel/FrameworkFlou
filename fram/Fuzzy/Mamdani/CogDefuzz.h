#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include "MamdaniDefuzz.h"

namespace Fuzzy 
{
	template<class T> 
	class CogDefuzz: public MamdaniDefuzz<T>
	{
		public:
			CogDefuzz();
			CogDefuzz(const T&, const T&, const T&);
			virtual ~CogDefuzz(){};

			T Defuzz(const typename Core::Evaluator<T>::Shape& ) const;
			T Evaluate(Core::Expression<T>*, Core::Expression<T>*) const;

		private:
			T min,max,step;
	};

	template<class T>
	CogDefuzz<T>::CogDefuzz():min(0),max(0),step(0){}
	
	template<class T>
	CogDefuzz<T>::CogDefuzz(const T& _min, const T& _max, const T& _step):min(_min),max(_max),step(_step){}

	template<class T>
	T CogDefuzz<T>::Evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const
	{
		return Defuzz(Core::Evaluator<T>::BuildShape(min, max, step, (Core::ValueModel<T> *) left, right));
	}

	template<class T>
	T CogDefuzz<T>::Defuzz(const typename Core::Evaluator<T>::Shape& s) const
	{
		T num = 0, denum = 0;

		for(T i = min; i < max; i += step)
		{
			num += s.second.at(i)*s.first.at(i) ;
			denum += s.second.at(i) ;
		}
		
		return num / denum;
	}
}

#endif