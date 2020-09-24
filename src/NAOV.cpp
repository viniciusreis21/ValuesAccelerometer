#include <iostream>
#include <string>
#include <qi/os.hpp>
#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <alproxies/almemoryproxy.h>
#include <pthread.h>

#include<vector> 
#include "Timer.h"
using namespace std;
using namespace AL;

class NAOV{
public:
    AL::ALMotionProxy almotion;
    AL::ALRobotPostureProxy alposture;
    AL::ALMemoryProxy memory;
    Timer t;
    NAOV(string nao_ip) : almotion(nao_ip), alposture(nao_ip), memory(nao_ip)
    {
    }
    void WakeUp()
    {
        almotion.wakeUp();
    }

    void Rest()
    {
        almotion.rest();
    }

    void GoToPosture(string posture)
    {
        alposture.goToPosture(posture, 1.0f);
    }
    void footSteps()
    {
        /*bool leftArmEnabled  = true;
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
        */
        float x  = 0.2f;
        float y  = 0.0f;
        float theta  = 0.0f;
        almotion.moveTo(x, y, theta);
    }
    void getAccelerometer()
    {	
        bool aux1 = 1;
        while (aux1 == 1){
            AL::ALValue sensors= AL::ALValue::array(0);
            sensors[0] = memory.getData("Device/SubDeviceList/InertialSensor/AccelerometerZ/Sensor/Value");
            cout << sensors[0] << endl;
            t.Wait(200);
            aux1 = almotion.moveIsActive();
        }
    }
    void *hello(void)
    {
        getAccelerometer();
        std::cout << "Hello, world!" << std::endl;
        return 0;
    }

    static void *hello_helper(void *context)
    {
        return ((NAOV *)context)->hello();
    }

};