#ifndef _NAOVALUES_H_
#define _NAOVALUES_H_

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



class NAOValues
{
private:
  AL::ALMotionProxy almotion;
  AL::ALRobotPostureProxy alposture;
  AL::ALMemoryProxy memory;

public:
  Timer t;
  NAOValues(string nao_ip);
  void WakeUp();
  void Rest();
  void GoToPosture(string);
  void footSteps();
  void getAccelerometer();
  //void *PrintHello(void *threadid);
};

#endif