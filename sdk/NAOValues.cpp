#include "NAOValues.h"
#include <assert.h>

using namespace std;
using namespace AL;

NAOValues::NAOKin(string nao_ip) : almotion(nao_ip), alposture(nao_ip) 
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
