

#pragma config(Motor,  port2,           BL,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           BR,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           FR,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           FL,            tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

float mecSpeed(int side, float speed, float angle, float turn) {
	writeDebugStreamLine("%d",speed*sin(angle+(PI/4))+turn);
	if(side == 0) {
			return speed*sin(angle+(PI/4))+turn;
		}
		else {
			return speed*cos(angle+(PI/4))+turn;
		}
}

float stickAngle(float x, float y) {
	return atan2(x,y);
}

float pointDistance(float x1,float y1,float x2,float y2) {
		return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}



task main()
{




while(true) {
	float angle = stickAngle(VexRT[Ch1],vexRT[Ch2]);
	float distance = pointDistance(VexRT[Ch1],vexRT[Ch2],0,0);
	int baseSpeed = 100;

	float nSpeed = distance/127;


	motor[FL] = mecSpeed(0,nSpeed*baseSpeed,angle,27*vexRT[Ch4]/127);
	motor[BR] = mecSpeed(0,nSpeed*baseSpeed,angle,-27*vexRT[Ch4]/127);
	motor[FR] = mecSpeed(1,nSpeed*baseSpeed,angle,-27*vexRT[Ch4]/127);
	motor[BL] = mecSpeed(1,nSpeed*baseSpeed,angle,27*vexRT[Ch4]/127);
}


}



