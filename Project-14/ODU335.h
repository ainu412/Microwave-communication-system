#pragma once
#include "ODU.h"
class ODU335 : public ODU
{
public:
	ODU335(ODU_TYPE oduType = ODU_TYPE::ODU_TYPE_335);
	virtual bool heartBeat();//��д�麯��ʱע��!�����Ƿ���ͬ!

	string name();
};

