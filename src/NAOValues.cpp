#include "NAOValues.h"
#include <assert.h>

using namespace std;
using namespace AL;

NAOValues::NAOValues(string nao_ip) : almotion(nao_ip), alposture(nao_ip), memory(nao_ip)
{

}
void NAOValues::WakeUp()
{
	almotion.wakeUp();
}

void NAOValues::Rest()
{
	almotion.rest();
}

void NAOValues::GoToPosture(string posture)
{
	alposture.goToPosture(posture, 1.0f);
}
void NAOValues::footSteps()
{
	bool leftArmEnabled  = true;
	bool rightArmEnabled = true;
	almotion.setMoveArmsEnabled(leftArmEnabled, rightArmEnabled);
		
	AL::ALValue legName = AL::ALValue::array (("LLeg"),("RLeg"));
		
	AL::ALValue posL1 = AL::ALValue::array(0.06, 0.0, 0.0); 
	AL::ALValue posR1 = AL::ALValue::array(0.06, -0.0, 0.0);

	AL::ALValue footSteps;    		
	footSteps.arrayPush(posL1);   
	footSteps.arrayPush(posR1);

	vector<float>timeList(2,0.0f);
	timeList[0] = 0.5;
	timeList[1] = 1.0;

	bool clearExisting = false;	
	almotion.setFootSteps(legName, footSteps, timeList, clearExisting);
}
void NAOValues::getAccelerometer()
{	
	AL::ALValue sensors= AL::ALValue::array(0);
	sensors[0] = memory.getData("Device/SubDeviceList/InertialSensor/AccelerometerZ/Sensor/Value");
    cout << sensors[0] << endl;
    t.Wait(1000);
}


/*void NAOValues::*PrintHello(void *threadid){//função a ser executada quando uma thread for criada
  long id;
  id = (long)threadid;//conversão de void pra long
  printf("Thread %ld: Olá mundo!\n", id);
  pthread_exit(NULL); //finalização da thread
}
*/