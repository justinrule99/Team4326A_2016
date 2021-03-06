#pragma config(Motor,  port1,           TR,            tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           BL,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           TL,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           BR,            tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void strafeLeft(int speed){
	motor[TL] = speed*-1;
	motor[TR] = speed;
	motor[BR] = speed*-1;
	motor[BL] = speed;
}
void strafeRight(int speed){
	motor[TL] = speed;
	motor[TR] = speed*-1;
	motor[BR] = speed;
	motor[BL] = speed*-1;
}

task main()
{
motor[TL] = vexRT[Ch3];
motor[BL] = vexRT[Ch3];
motor[TR] = vexRT[Ch2];
motor[BR] = vexRT[Ch2];


	if(vexRT[Btn6U] == 1)
		strafeLeft(127);

	if(vexRT[Btn5U] == 1)
		strafeRight(127);

}
