#include "ODU.h"


ODU::ODU(ODU_TYPE oduType)
{
		cout << name() << __FUNCTION__ << endl;
		txFreq = 34400;
		rxFreq = 31100;
		txPower = 20;
		rxLevel = 0;
		type = oduType;
}

int ODU::getTxFreq()
{
	cout << name() << __FUNCTION__ << endl;
	return txFreq;
}

void ODU::setTxFreq(int txFreq)//ֻ�м̳еĲſ��Լ�ð��дrxFreq(rxFreq)
{
	cout << name() << __FUNCTION__ << endl;
	this->txFreq = txFreq;
}

int ODU::getRxFreq()
{
	cout << name() << __FUNCTION__ << endl;
	return rxFreq;
}

void ODU::setRxFreq(int rxFreq)
{
	cout << name() << __FUNCTION__ << endl;
	this->rxFreq = rxFreq;
}

int ODU::getTxPower()
{
	cout << name() << __FUNCTION__ << endl;
	return txPower;
}

void ODU::setTxPower(int txPower)
{
	cout << name() << __FUNCTION__ << endl;
	this->txPower = txPower;
}

int ODU::getRxLevel()
{
	cout << name() << __FUNCTION__ << endl;
	return rxLevel;
}

bool ODU::heartBeat()
{
	cout << name() << __FUNCTION__ << endl;
	cout << name() << "ģ�⴮��Э���ȡ���ݣ���ȡ�������ķ���..."
		<< "��" << ODU_TYPE_331_FLAG << "��" << endl;
	string response;
	cin >> response;

	if (ODU_TYPE_331_FLAG == response) {
		type = ODU_TYPE::ODU_TYPE_331;
		return true;
	}
	//else if (ODU_TYPE_335_FLAG == response)//�����ODU335�и�д����
	//{
	//	type = ODU_TYPE::ODU_TYPE_335;
	//	return false;
	//}
	else {
		return false;
	}
}

string ODU::name()
{
	return ODU_TYPE_331_FLAG;
}
