#ifndef OR_H_
#define OR_H_


namespace Fuzzy {

	template<class T> class Or: public Core::BinaryExpression<T>
	{
	public:
		virtual T evaluate(Core::Expression<T>* left, Core::Expression<T>* right) const=0;
	};

}

#endif