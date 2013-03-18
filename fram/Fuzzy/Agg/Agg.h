#ifndef AGG_H_
#define AGG_H_

namespace Fuzzy {

	template<class T> class Agg: public Core::BinaryExpression<T>
	{
	public:
	
		virtual T evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const=0;
	};

}

#endif
