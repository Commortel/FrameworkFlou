#ifndef THEN_H_
#define THEN_H_

namespace Fuzzy {

	template<class T> class Then: public Core::BinaryExpression<T>
	{
	public:
	
		virtual T evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const=0;
	};

}

#endif
