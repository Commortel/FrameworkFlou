#include "main.h"
#define ASSERT_ON

void Test_Operator()
{
	Core::ValueModel<double> v1 ( 1 );
	Core::ValueModel<double> v2;
	v2.SetValue(2);
	ASSERT(2 == v1.Evaluate());
	cout << v1.Evaluate() << endl;
	cout << v2.Evaluate() << endl;

	Fuzzy::AndMin<double> andMin;
	Core::ValueModel<double> andMinValue = andMin.Evaluate(&v1,&v2);
	ASSERT(andMinValue.Evaluate == 1);

	Fuzzy::AndMult<double> andMult;
	Core::ValueModel<double> andMultValue = andMult.Evaluate(&v1,&v2);
	ASSERT(andMultValue.Evaluate == 2);

	Fuzzy::AggMax<double> aggMax;
	Core::ValueModel<double> aggMaxValue = aggMax.Evaluate(&v1,&v2);
	ASSERT(aggMaxValue.Evaluate == 2);

	Fuzzy::AggPlus<double> aggPlus;
	Core::ValueModel<double> aggPlusValue = aggPlus.Evaluate(&v1,&v2);
	ASSERT(aggPlusValue.Evaluate == 3);
}

int main()
{
	cout << "Starting Test...." << endl;
	Test_Operator();
	cout << "....Ending Test" << endl;
	return 0;
}