#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H

#include "../../Core/Binary/BinaryExpression.h"
#include "Evaluator.h"

namespace Fuzzy 
{
	template<class T> 
	class MamdaniDefuzz: public Core::BinaryExpression<T>
	{
		public:
			MamdaniDefuzz();
			MamdaniDefuzz(const T&, const T&, const T&);
			virtual ~MamdaniDefuzz(){};

			T Evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const;

		protected:
			virtual T Defuzz(const typename Core::Evaluator<T>::Shape& ) const = 0;

		private:
			T min, max, step;
	};
	
	template<class T>
	MamdaniDefuzz<T>::MamdaniDefuzz():min(0),max(0),step(0){}

	template<class T>
	MamdaniDefuzz<T>::MamdaniDefuzz(const T& _min, const T& _max, const T& _step):
	min(_min),max(_max),step(_step){}

	// cast de l obligatoire
	template<class T>
	T MamdaniDefuzz<T>::Evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const
	{
		return Defuzz( Core::Evaluator<T>::BuildShape(min, max, step, (Core::ValueModel<T> *) left, right) );
	}
}

#endif