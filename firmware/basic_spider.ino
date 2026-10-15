# ESP32 实体蜘蛛基础控制程序

```cpp
#include <Arduino.h>
#include <Servo.h>

Servo legs[8];
const uint8_t pinMap[8] = {13, 14, 27, 26, 25, 33, 32, 35};

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 8; i++) {
    legs[i].attach(pinMap[i]);
    legs[i].write(90);
  }
  delay(500);
  Serial.println("Spider ready.");
}

void setAngle(int idx, int angle) {
  if (idx < 0 || idx >= 8) return;
  legs[idx].write(constrain(angle, 0, 180));
}

void testSequence() {
  for (int a = 30; a <= 150; a += 20) {
    for (int i = 0; i < 8; i++) {
      setAngle(i, a);
    }
    delay(200);
  }

  for (int i = 0; i < 8; i++) {
    setAngle(i, 90);
  }
}

void loop() {
  testSequence();
  delay(1000);
}
```

## 说明
- 这是基础版本，用于验证每个舵机是否正常工作
- 后续可以加入 8 足步态算法
- 推荐先用单腿测试，再整体调试

