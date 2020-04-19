#include "ODU335.h"

ODU335::ODU335(ODU_TYPE oduType) :ODU(oduType)
{
	cout << name() << __FUNCTION__ << endl;
}

bool ODU335::heartBeat()
{
	cout << __FUNCTION__ << endl;
	cout << name() << "ģ�⴮��Э���ȡ���ݣ���ȡ�������ķ���..."
		<< "��" << ODU_TYPE_335_FLAG << "��" << endl;
	string response;
	cin >> response;

	if (ODU_TYPE_335_FLAG == response) {
		type = ODU_TYPE::ODU_TYPE_335;
		return true;
	}

	return false;
}

string ODU335::name()
{
	return ODU_TYPE_335_FLAG;
}