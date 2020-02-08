#include "ODU.h"
#include "ODU335.h"
#include <Windows.h>
#include <thread>
void test(ODU& odu, int n) {
	odu.setRxFreq(n);
	cout << odu.getRxFreq() << endl;
}
ODU* odu = NULL;//全局变量才能在函数内不使用参数,就使用
void oduMonitorHandler() {
	while (1) {
		if ( odu->heartBeat() == false) {//只要输出不为对象对应类,就会返回false,故包含设备输错不属于331也不属于335状况
			switch (odu->type) {
			case ODU_TYPE::ODU_TYPE_331:
				//odu->type = ODU_TYPE::ODU_TYPE_335;
				delete odu;
				odu = new ODU335;
				break;
			case ODU_TYPE::ODU_TYPE_335:
				//odu->type = ODU_TYPE::ODU_TYPE_331;
				delete odu;
				odu = new ODU;
				break;
				//default:
				//	odu = NULL;
				//	return;
			}
		}
		Sleep(1000);
	}
}
int main() {
	ODU odu331;
	ODU335 odu335;

	test(odu331, 1000);
	test(odu335, 5000);
	//不断发送心跳包，若一个的心跳包响应为false停止发送这一类型心跳包，开启另一类型并发送另一类型的心跳包
	//即只发送活跃ODU的心跳包，死后再切另一类型
	//ODU* odu = new ODU;//记得不要重定义
	odu = new ODU;
	odu = &odu331;//记得先分配值,不然odu为空
	//第四卷Windows线程，第六卷Linux线程
	//多线程-同时多个功能
	//创建线程,对ODU进行心跳检测
	// 创建一个线程，用于对ODU进行监测
	std::thread oduMonitor(oduMonitorHandler);

	// 主线程等待线程oduMonitor的结束
	oduMonitor.join();


	return 0;
}
//
//#include <iostream>
//#include <Windows.h>
//#include <thread>
//#include "ODU.h"
//#include "ODU335.h"
//class ODU;
//using namespace std;
//
//ODU* odu = NULL;
//
//void oduMonitorHandler() {
//	while (1) {
//		if (odu->heartBeat() == false) {
//			// 切换ODU
//			ODU_TYPE type = odu->type;
//			switch (type) {
//			case ODU_TYPE::ODU_TYPE_331:
//				delete odu;
//				odu = new ODU335;
//				break;
//			case ODU_TYPE::ODU_TYPE_335:
//				delete odu;
//				odu = new ODU;
//				break;
//			default:
//				odu = NULL;
//				return;
//			}
//		}
//
//		Sleep(3000);
//	}
//}
//
//int main(void) {
//	odu = new ODU();
//
//	// 创建一个线程，用于对ODU进行监测
//	std::thread oduMonitor(oduMonitorHandler);
//
//	// 主线程等待线程oduMonitor的结束
//	oduMonitor.join();
//
//	return 0;
//}