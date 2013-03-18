#ifndef VALUEMODEL_H
#define VALUEMODEL_H

#include "Expression.h"

namespace Core
{
	template <class T>
	class ValueModel : public Expression<T>
	{
	public:
		ValueModel();
		ValueModel(const T&);
		virtual ~ValueModel() {};

		T Evaluate() const;

		void SetValue(const T&);
		T GetValue() const;

	private:
		T Value;
	};

	template <class T>
	ValueModel<T>::ValueModel():Value(0){}

	template <class T>
	ValueModel<T>::ValueModel(const T& _value):Value(_value){}

	template <class T>
	void ValueModel<T>::SetValue(const T& _value){ this->Value = _value; }

	template <class T>
	T ValueModel<T>::GetValue() const{	return this->Value; }

	template <class T>
	T ValueModel<T>::Evaluate() const{	return this->Value; }
}
#endif