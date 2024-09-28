#include <iostream>
#include <thread>
#include <chrono>

// Map a value from one range to another
template <typename T>
T mapValue(T x, T in_min, T in_max, T out_min, T out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// Delay function in milliseconds
void delay(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

// Placeholder functions for moving legs
void moveLeg(int pwm, int legNumber, int param1, int param2, int param3) {
    // Implement hardware-specific leg movement logic here
    std::cout << "moveLeg called with pwm: " << pwm << ", legNumber: " << legNumber
              << ", params: " << param1 << ", " << param2 << ", " << param3 << std::endl;
}

void moveLegT(int pwm, int legNumber, int param1, int param2, int param3) {
    // Implement hardware-specific leg movement logic here
    std::cout << "moveLegT called with pwm: " << pwm << ", legNumber: " << legNumber
              << ", params: " << param1 << ", " << param2 << ", " << param3 << std::endl;
}

// PWM variables (assign appropriate values based on your hardware setup)
int pwm1 = 1;
int pwm2 = 2;

void MoveForward() {
    // Leg Forward
    moveLeg(pwm1, 0, 375, 345, 370);    // Expand motion
    moveLeg(pwm1, 1, 375, 340, 327);
    moveLeg(pwm1, 2, 350, 345, 350);

    for (int i = 0; i <= 100; i += 5) {
        moveLegT(pwm2, 0, 375, mapValue(i, 0, 100, 407, 480), mapValue(i, 0, 100, 420, 467));
        moveLegT(pwm2, 1, 375, mapValue(i, 0, 100, 402, 462), mapValue(i, 0, 100, 377, 420));
        moveLegT(pwm2, 2, 350, mapValue(i, 0, 100, 402, 470), mapValue(i, 0, 100, 397, 442));
        delay(10);
    }

    moveLegT(pwm2, 0, 375, 480, 467);
    moveLegT(pwm2, 1, 375, 462, 420);
    moveLegT(pwm2, 2, 350, 470, 442);
    delay(100);

    // Condense motion
    for (int i = 0; i <= 100; i += 5) {
        moveLeg(pwm1, 0, 375, mapValue(100 - i, 0, 100, 340, 345), mapValue(100 - i, 0, 100, 327, 370));
        moveLeg(pwm1, 1, 375, mapValue(i, 0, 100, 340, 345), mapValue(i, 0, 100, 327, 370));
        moveLeg(pwm1, 2, mapValue(i, 0, 100, 350, 400), 345, 350);

        moveLegT(pwm2, 0, 375, mapValue(100 - i, 0, 100, 462, 480), mapValue(100 - i, 0, 100, 420, 467));
        moveLegT(pwm2, 1, 375, mapValue(i, 0, 100, 462, 480), mapValue(i, 0, 100, 420, 467));
        moveLegT(pwm2, 2, mapValue(i, 0, 100, 350, 400), 470, 442);
        delay(15);
    }
    delay(100);

    // LegT Forward
    for (int i = 0; i <= 100; i += 5) {
        moveLegT(pwm2, 0, 375, mapValue(100 - i, 0, 100, 402, 462), mapValue(100 - i, 0, 100, 377, 420));
        moveLegT(pwm2, 1, 375, mapValue(100 - i, 0, 100, 407, 480), mapValue(100 - i, 0, 100, 420, 467));
        moveLegT(pwm2, 2, 400, mapValue(100 - i, 0, 100, 402, 470), mapValue(100 - i, 0, 100, 397, 422));
        delay(10);
    }

    moveLegT(pwm2, 0, 375, 402, 377);
    moveLegT(pwm2, 1, 375, 407, 420);
    moveLegT(pwm2, 2, 400, 402, 397);

    for (int i = 0; i <= 100; i += 5) {
        moveLeg(pwm1, 0, 375, mapValue(100 - i, 0, 100, 267, 340), mapValue(100 - i, 0, 100, 280, 327));
        moveLeg(pwm1, 1, 375, mapValue(100 - i, 0, 100, 285, 345), mapValue(100 - i, 0, 100, 327, 370));
        moveLeg(pwm1, 2, 400, mapValue(100 - i, 0, 100, 277, 345), mapValue(100 - i, 0, 100, 305, 350));
        delay(10);
    }
    moveLeg(pwm1, 0, 375, 267, 280);
    moveLeg(pwm1, 1, 375, 285, 327);
    moveLeg(pwm1, 2, 400, 277, 305);
    delay(100);

    // Condense motion
    for (int i = 0; i <= 100; i += 5) {
        moveLegT(pwm2, 0, 375, mapValue(i, 0, 100, 402, 407), mapValue(i, 0, 100, 377, 420));
        moveLegT(pwm2, 1, 375, mapValue(100 - i, 0, 100, 402, 407), mapValue(100 - i, 0, 100, 377, 420));
        moveLegT(pwm2, 2, mapValue(100 - i, 0, 100, 350, 400), 402, 397);

        moveLeg(pwm1, 0, 375, mapValue(i, 0, 100, 267, 285), mapValue(i, 0, 100, 280, 327));
        moveLeg(pwm1, 1, 375, mapValue(100 - i, 0, 100, 267, 285), mapValue(100 - i, 0, 100, 280, 327));
        moveLeg(pwm1, 2, mapValue(100 - i, 0, 100, 350, 400), 277, 305);
        delay(15);
    }

    moveLeg(pwm1, 0, 375, 285, 327);
    moveLeg(pwm1, 1, 375, 267, 280);
    moveLeg(pwm1, 2, 350, 277, 305);

    for (int i = 0; i <= 100; i += 5) {
        moveLeg(pwm1, 0, 375, mapValue(i, 0, 100, 285, 345), mapValue(i, 0, 100, 327, 370));
        moveLeg(pwm1, 1, 375, mapValue(i, 0, 100, 267, 340), mapValue(i, 0, 100, 280, 327));
        moveLeg(pwm1, 2, 350, mapValue(i, 0, 100, 277, 345), mapValue(i, 0, 100, 305, 350));
        delay(10);
    }
    delay(100);
}

int main() {
    MoveForward();
    return 0;
}
