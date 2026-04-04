#include <SPI.h>
#include <RF24.h>
#include <Wire.h>
#include <MPU6050.h>

RF24 radio(4,5);
const byte addr[6] = "00001";

MPU6050 mpu;

int motorL = 25;
int motorR = 26;

int chL = 0;
int chR = 1;

float joyL = 0;
float joyR = 0;
float roll = 0;
float rollFiltered = 0;

bool autoStabilize = false;
bool emergency = false;

// ===== IMPORTANT: MUST MATCH TX =====
struct __attribute__((packed)) ControlData {
  float L;
  float R;
  uint8_t toggle;
};

ControlData ctrl;

// ===== SIGNAL TIMEOUT =====
unsigned long lastReceive = 0;
const unsigned long timeoutMs = 500;

// ===== SETUP =====
void setup() {
  Serial.begin(115200);

  ledcSetup(chL, 5000, 8);
  ledcSetup(chR, 5000, 8);
  ledcAttachPin(motorL, chL);
  ledcAttachPin(motorR, chR);

  Wire.begin();
  mpu.initialize();

  if(!mpu.testConnection()){
    Serial.println("MPU6050 FAILED");
    while(true);
  }

  radio.begin();
  radio.setChannel(108);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);
  radio.setAutoAck(true);

  radio.openReadingPipe(1, addr);
  radio.startListening();

  lastReceive = millis();
}

// ===== LOOP =====
void loop() {

  // ===== RF RECEIVE =====
  if(radio.available()){
    radio.read(&ctrl, sizeof(ctrl));

    joyL = ctrl.L;  
    joyR = ctrl.R;  
    autoStabilize = ctrl.toggle;

    lastReceive = millis();
  }

  // ===== FAILSAFE =====
  if (millis() - lastReceive > timeoutMs) {
    joyL = 0;
    joyR = 0;
    autoStabilize = false;
  }

  readGyro();
  controlMotors();
}

// ===== GYRO =====
void readGyro(){
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  roll = atan2(ax, az) * 57.3;

  // smoothing
  rollFiltered = (rollFiltered * 0.8) + (roll * 0.2);
  roll = rollFiltered;
}

// ===== MOTOR CONTROL =====
void controlMotors(){

  float baseL = joyL;
  float baseR = joyR;

  float absRoll = abs(roll);

  // emergency hysteresis
  if(absRoll > 45) emergency = true;
  else if(absRoll < 30) emergency = false;

  float correction = 0;

  if(autoStabilize){
    correction += roll * 0.5;
  }

  if(emergency){
    correction += roll * 2.0;
  }

  float L = baseL - correction;
  float R = baseR + correction;

  L = constrain(L, 0, 255);
  R = constrain(R, 0, 255);

  ledcWrite(chL, (int)L);
  ledcWrite(chR, (int)R);
}