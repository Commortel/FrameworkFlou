#include "main.h"

void Test_Operator()
{
	Core::ValueModel<double> v1(1);
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

	Fuzzy::NotMinus<double> notMinus;
	Core::ValueModel<double> notMinusValue = notMinus.Evaluate(&v1);
	assert(notMinusValue.Evaluate() == -1);
}

void Test_Operator_Unary()
{
	Core::ValueModel<double> v1 ( 1 );
	Core::ValueModel<double> v2 ( 3 );
	Core::ValueModel<double> v3 ( 5 );
	Core::ValueModel<double> v4 ( 7 );
	assert(1 == v1.Evaluate());
	assert(3 == v2.Evaluate());
	assert(5 == v3.Evaluate());
	assert(7 == v4.Evaluate());

	Fuzzy::IsTriangle<double> isTriangle(0,5,10);
	Core::ValueModel<double> isTriangleValueMin = isTriangle.Evaluate(&v1);
	Core::ValueModel<double> isTriangleValueMax = isTriangle.Evaluate(&v4);
	assert(isTriangleValueMin.Evaluate() == 0.2);
	assert(isTriangleValueMax.Evaluate() == 0.6);

	Fuzzy::IsTrapeze<double> IsTrapeze(0,2,4,6);
	Core::ValueModel<double> IsTrapezeValueMin = IsTrapeze.Evaluate(&v1);
	Core::ValueModel<double> IsTrapezeValueMid = IsTrapeze.Evaluate(&v2);
	Core::ValueModel<double> IsTrapezeValueMax = IsTrapeze.Evaluate(&v3);
	Core::ValueModel<double> IsTrapezeValueOut = IsTrapeze.Evaluate(&v4);
	assert(IsTrapezeValueMin.Evaluate() == 0.5);
	assert(IsTrapezeValueMid.Evaluate() == 1);
	assert(IsTrapezeValueMax.Evaluate() == 0.5);
	assert(IsTrapezeValueOut.Evaluate() == 0);
}

int main()
{
	cout << "Starting Test...." << endl;
	Test_Operator();
	Test_Operator_Unary();
	cout << "....Ending Test" << endl;
	return 0;
}