#include "main.h"

void Test_Operator()
{
	double i1=1 , i2=2 ,i3=3;
	Core::ValueModel<double> v1 ( 1 );
	Core::ValueModel<double> v2;
	v2.SetValue(2);
	cout << v1.Evaluate() << endl;
	cout << v2.Evaluate() << endl;
}

int main()
{
	cout << "Starting Test...." << endl;
	Test_Operator();
	cout << "....Ending Test" << endl;
	return 0;
}