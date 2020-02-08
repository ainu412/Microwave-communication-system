#pragma once
#include <iostream>
using namespace std;
/*
实现：发射频率（txFreq-frequence），
接收频率（rxFreq），
发射功率（txPower-transmit power），
的读取与设置；
接收电平（rxL-receive level)
的读取；
心跳包（heartBeat）
正在工作类型与工作状态的获取；
获取设备名称（name）与设备类型（type）
初始化:
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

private://设为protected??--唯一差别是子类访问权限,子类(ODU335)不需要访问(ODU331)
	int txFreq;
	int rxFreq;
	int txPower;
	int rxLevel;

};

