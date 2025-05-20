#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

// 采样参数
const int SAMPLE_INTERVAL_MS = 10;         // 100Hz = 10ms
const unsigned long CAPTURE_DURATION = 1000; // 1秒
unsigned long last_sample_time = 0;
unsigned long capture_start_time = 0;

bool capturing = false;
int sample_count = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin(4, 5); // 指定 SDA / SCL

  while (!mpu.begin()) {
    Serial.println("MPU6050 not found");
    delay(500);
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  Serial.println("Setup done. Send 'o' to start capture.");
}

void loop() {
  // 检查串口输入
  if (Serial.available()) {
    char cmd = Serial.read();
    if (cmd == 'o') {
      capturing = true;
      capture_start_time = millis();
      last_sample_time = millis();
      sample_count = 0;
      Serial.println("-,-,-"); // 通知 Python 开始采集
      Serial.println("Starting capture...");
    } else if (cmd == 'p') {
      capturing = false;
      Serial.println("Capture stopped manually");
    }
  }

  // 如果正在采集
  if (capturing) {
    unsigned long now = millis();

    if (now - last_sample_time >= SAMPLE_INTERVAL_MS) {
      last_sample_time = now;

      sensors_event_t a, g, temp;
      mpu.getEvent(&a, &g, &temp);

      Serial.print(a.acceleration.x); Serial.print(",");
      Serial.print(a.acceleration.y); Serial.print(",");
      Serial.println(a.acceleration.z);

      sample_count++;
    }

    // 超时自动结束采集
    if (millis() - capture_start_time >= CAPTURE_DURATION) {
      capturing = false;
      Serial.println("Capture complete (1 second)");
      Serial.print("Samples captured: ");
      Serial.println(sample_count);
      Serial.println();  // 保留原脚本中的间隔识别
      Serial.println();
    }
  }
}