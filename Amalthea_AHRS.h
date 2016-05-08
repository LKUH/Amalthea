#ifndef __Amalthea_AHRS_H__
#define __Amalthea_AHRS_H__

#include <Wire.h>
#include "ADXL345_l.h"  // ADXL345 Accelerometer Library
#include "HMC5883L.h" // HMC5883L Magnetometer Library
#include "ITG3200.h" //ITG3200 Gyroscope Library

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
#endif

// Accelerometer


// QAEF Constants
#define GyroMeasError PI * (40.0f / 180.0f)
#define beta sqrt(3.0f / 4.0f) * GyroMeasError

// Mahony Constants
#define Kp 2.0f * 5.0f
#define Ki 0.0f

enum UpdateMethod
{
	MAHONY = 0,
	QAEF = 1
};

class Amalthea_AHRS
{
	public:
		Amalthea_AHRS(UpdateMethod updateMethod);
		void Amalthea_AHRS_2(UpdateMethod updateMethod);
		void update();
		void update_acc(int x, int y, int z);
		
		float pitch, yaw, roll;
		float gx, gy, gz, mx, my, mz;
		float q[4];
		float dt;
		float  raw_gX, raw_gY, raw_gZ;
		int raw_aX, raw_aY, raw_aZ, ax, ay, az;
	
	private:
		void acc_powerOn();
		void initializeMarg();
		ADXL345* initializeMarg_2();
		void readMarg();
		void readAcc();
		void updateQuaternions();
		void updateEulerAngles();
		void tick();
		void QAEFQuaternionUpdate(float ax, float ay, float az, float gx, float gy, float gz, float mx, float my, float mz);
		void mahonyQuaternionUpdate(float ax, float ay, float az, float gx, float gy, float gz, float mx, float my, float mz);
		ADXL345* acc; //variable adxl is an instance of the ADXL345 library
		HMC5883L* compass;
		ITG3200* gyro;
		// IMU* marg;
		UpdateMethod updateMethod;
		float mahonyErrors[3];
		uint16_t lastUpdate;
};

#endif // __Amalthea_AHRS_H__