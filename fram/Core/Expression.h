#ifndef EXPRESSION_H
#define EXPRESSION_H

namespace Core
{
	template <class T>
	class Expression
	{
		public:
			virtual ~Expression() {}
			virtual T Evaluate() const=0;
	};
}

#endif