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
			T Evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const;

		private:
			T min,max,step;
	};

	template<class T>
	CogDefuzz<T>::CogDefuzz():min(0),max(0),step(0){}
	
	template<class T>
	CogDefuzz<T>::CogDefuzz(const T& _min, const T& _max, const T& _step):
	min(_min),max(_max),step(_step){}

	template<class T>
	T CogDefuzz<T>::Evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const
	{
		return Defuzz( Core::Evaluator<T>::BuildShape(min, max, step, (Core::ValueModel<T> *) l, r) );
	}

	template<class T>
	T CogDefuzz<T>::Defuzz(const typename Core::Evaluator<T>::Shape& s) const
	{
		T result, temp1, temp2;
		temp1=0;
		temp2=0;
		for(T i=min; i < max ; i+= step)
		{
			//std::cout << s.second.at(i) << "-" ;
			temp1 += s.second.at(i)*s.first.at(i) ;
			temp2 += s.second.at(i) ;
		}
		//std::cout << std::endl ;
		result = temp1 / (temp2);
		
		return result;
	}
}

#endif