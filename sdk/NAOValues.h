#ifndef _NAOVALUES_H_
#define _NAOVALUES_H_

#include <iostream>
#include <string>
#include <qi/os.hpp>
#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>


#include<vector> 

using namespace std;



class NAOValues
{
private:
  AL::ALMotionProxy almotion;
  AL::ALRobotPostureProxy alposture;

public:
  NAOValues(string nao_ip);
  void WakeUp();
  void Rest();
  void GoToPosture(string);
};

#endif