#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "ValueModel.h"
#include <vector>

namespace Core 
{
	template<class T> class Evaluator
	{
		public:
			typedef std::pair<std::vector<T>, std::vector<T>> Shape;

			static Shape BuildShape (const T&, const T&, const T&, Core::ValueModel<T>*, Core::Expression<T>*);
	};

	template<class T>
	typename Evaluator<T>::Shape Evaluator<T>::BuildShape (const T& min, const T& max, const T& step, Core::ValueModel<T>* v, Core::Expression<T>* e)
	{
		std::vector<T> x,y;
		for (T i=min; i <= max; i+= step)
		{
			v->SetValue(i);
			x.push_back(i);
			y.push_back(e->Evaluate());
		}
		return Shape(x,y);
	}
}

#endif