#include <Wire.h>
//#include "ADXL345_l.h"  // ADXL345 Accelerometer Library
//#include "HMC5883L.h" // HMC5883L Magnetometer Library
//#include "ITG3200.h"
#include <math.h>
#include "Amalthea_AHRS.h"



//Amalthea_AHRS* ahrs = new Amalthea_AHRS(QAEF);
//Amalthea_AHRS ahrs;
float m_x, m_y, m_z, g_x, g_y, g_z;
int a_x, a_y, a_z;
int ax, ay,az;
 Amalthea_AHRS* ahrs;
 
void setup(){
    
  //setup board
  Serial.begin(9600);
  Serial.print("1");
  pinMode(13, OUTPUT);
  delay(6000);
  digitalWrite(13,HIGH); // power ON BLE

  ahrs = new Amalthea_AHRS(QAEF);
 }

void loop(){
  Serial.print("2");
ahrs->update_acc();
//m_x = ahrs->mx;
//m_y = ahrs->my;
//m_z = ahrs->mz;
a_x = ahrs->ax;
a_y = ahrs->ay;
a_z = ahrs->az;
//g_x = ahrs->gx; 
//g_y = ahrs->gy;
//g_z = ahrs->gz;
  

Output_2(a_x, a_y, a_z);
delay(100);
}


void Output_2 (int X, int Y, int Z)
{
//accel data
   Serial.print("Accel");
   Serial.print(X);
   Serial.print(" ");   
   Serial.print(Y);
   Serial.print(" ");   
   Serial.print(Z);
   Serial.println(" ");

}

