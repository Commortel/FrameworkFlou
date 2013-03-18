#include "main.h"

void Test_Operator()
{
	Core::ValueModel<double> v1 ( 1 );
	Core::ValueModel<double> v2;
	v2.SetValue(2);
	assert(1 == v1.Evaluate());
	assert(2 == v2.Evaluate());

	Fuzzy::AndMin<double> andMin;
	Core::ValueModel<double> andMinValue = andMin.Evaluate(&v1,&v2);
	assert(andMinValue.Evaluate() == 1);

	Fuzzy::AndMult<double> andMult;
	Core::ValueModel<double> andMultValue = andMult.Evaluate(&v1,&v2);
	assert(andMultValue.Evaluate() == 2);

	Fuzzy::AggMax<double> aggMax;
	Core::ValueModel<double> aggMaxValue = aggMax.Evaluate(&v1,&v2);
	assert(aggMaxValue.Evaluate() == 2);

	Fuzzy::AggPlus<double> aggPlus;
	Core::ValueModel<double> aggPlusValue = aggPlus.Evaluate(&v1,&v2);
	assert(aggPlusValue.Evaluate() == 3);

	Fuzzy::OrMax<double> orMax;
	Core::ValueModel<double> orMaxValue = orMax.Evaluate(&v1,&v2);
	assert(orMaxValue.Evaluate() == 2);

	Fuzzy::OrPlus<double> orPlus;
	Core::ValueModel<double> orPlusValue = orPlus.Evaluate(&v1,&v2);
	assert(orPlusValue.Evaluate() == 1);

	Fuzzy::ThenMin<double> thenMin;
	Core::ValueModel<double> thenMinValue = thenMin.Evaluate(&v1,&v2);
	assert(thenMinValue.Evaluate() == 1);

	Fuzzy::ThenMult<double> thenMult;
	Core::ValueModel<double> thenMultValue = thenMult.Evaluate(&v1,&v2);
	assert(thenMultValue.Evaluate() == 2);
}

int main()
{
	cout << "Starting Test...." << endl;
	Test_Operator();
	cout << "....Ending Test" << endl;
	return 0;
}