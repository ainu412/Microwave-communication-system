#pragma once
#include <iostream>
using namespace std;
/*
ʵ�֣�����Ƶ�ʣ�txFreq-frequence����
����Ƶ�ʣ�rxFreq����
���书�ʣ�txPower-transmit power����
�Ķ�ȡ�����ã�
���յ�ƽ��rxL-receive level)
�Ķ�ȡ��
��������heartBeat��
���ڹ��������빤��״̬�Ļ�ȡ��
��ȡ�豸���ƣ�name�����豸���ͣ�type��
��ʼ��:
	txFre = 34400;
	rxFre = 31100;
	txPower = 20;
	rxL = 0;
	type = ODU_TYPE::ODU_TYPE_331;
*/
enum class ODU_TYPE {
	ODU_TYPE_331,
	ODU_TYPE_335,
	ODU_TYPE_FUTURE
};
#define ODU_TYPE_331_FLAG "331"
#define ODU_TYPE_335_FLAG "335"

class ODU
{
public:
	ODU(ODU_TYPE oduType = ODU_TYPE::ODU_TYPE_331);
	int getTxFreq();
	void setTxFreq(int);
	int getRxFreq();
	void setRxFreq(int);
	int getTxPower();
	void setTxPower(int);
	int getRxLevel();

	virtual bool heartBeat();
	virtual string name();

	ODU_TYPE type;

private://��Ϊprotected??--Ψһ������������Ȩ��,����(ODU335)����Ҫ����(ODU331)
	int txFreq;
	int rxFreq;
	int txPower;
	int rxLevel;

};

