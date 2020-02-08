#include "ODU335.h"

ODU335::ODU335(ODU_TYPE oduType):ODU(oduType)
{
	cout << name() << __FUNCTION__ << endl;
	//txFreq = 33500;���������ø���,�����ø�������,�����Լ��ٴ�������.ֱ�ӽ��Լ����ݴ������༴��.��������ݴ������������
	//rxFreq = 33500;
	//txPower = 20;
	//rxLevel = 0;
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
	else {
		return false;
	}

	return false;
}

string ODU335::name()
{
	return ODU_TYPE_335_FLAG;
}
