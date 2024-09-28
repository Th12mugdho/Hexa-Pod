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

void MoveBackward() {
    // Leg Forward
    moveLeg(pwm1, 1, 375, 345, 370);    // Expand motion
    moveLeg(pwm1, 0, 375, 340, 327);
    moveLeg(pwm1, 2, 350, 355, 350);
    delay(100);

    for (int i = 0; i <= 100; i += 5) {
        moveLegT(pwm2, 1, 375, mapValue(100 - i, 0, 100, 407, 450), mapValue(100 - i, 0, 100, 450, 420));
        moveLegT(pwm2, 0, 375, mapValue(i, 0, 100, 402, 440), mapValue(i, 0, 100, 377, 407));
        moveLegT(pwm2, 2, 350, mapValue(i, 0, 100, 402, 442), mapValue(i, 0, 100, 397, 427));
        delay(5);
    }

    moveLegT(pwm2, 1, 375, 450, 450);
    moveLegT(pwm2, 0, 375, 440, 407);
    moveLegT(pwm2, 2, 350, 442, 427);
    delay(100);

    // Condense motion
    for (int i = 0; i <= 100; i += 5) {
        moveLeg(pwm1, 1, 375, mapValue(100 - i, 0, 100, 340, 345), mapValue(100 - i, 0, 100, 327, 370));
        moveLeg(pwm1, 0, 375, mapValue(i, 0, 100, 340, 345), mapValue(i, 0, 100, 327, 370));
        moveLeg(pwm1, 2, mapValue(i, 0, 100, 350, 400), 355, 350);

        moveLegT(pwm2, 1, 375, mapValue(100 - i, 0, 100, 440, 450), mapValue(100 - i, 0, 100, 407, 450));
        moveLegT(pwm2, 0, 375, mapValue(i, 0, 100, 440, 450), mapValue(i, 0, 100, 407, 450));
        moveLegT(pwm2, 2, mapValue(i, 0, 100, 350, 400), 442, 427);
        delay(10);
    }
    delay(100);

    // LegT Forward
    for (int i = 0; i <= 100; i += 5) {
        moveLegT(pwm2, 1, 375, mapValue(100 - i, 0, 100, 402, 440), mapValue(100 - i, 0, 100, 377, 407));
        moveLegT(pwm2, 0, 375, mapValue(100 - i, 0, 100, 407, 450), mapValue(100 - i, 0, 100, 420, 450));
        moveLegT(pwm2, 2, 400, mapValue(100 - i, 0, 100, 402, 442), mapValue(100 - i, 0, 100, 397, 427));
        delay(5);
    }
    delay(100);

    moveLegT(pwm2, 1, 375, 402, 377);
    moveLegT(pwm2, 0, 375, 407, 420);
    moveLegT(pwm2, 2, 400, 402, 397);
    delay(100);

    for (int i = 0; i <= 100; i += 5) {
        moveLeg(pwm1, 1, 375, mapValue(100 - i, 0, 100, 297, 340), mapValue(100 - i, 0, 100, 297, 327));
        moveLeg(pwm1, 0, 375, mapValue(100 - i, 0, 100, 307, 345), mapValue(100 - i, 0, 100, 340, 370));
        moveLeg(pwm1, 2, 400, mapValue(100 - i, 0, 100, 305, 355), mapValue(100 - i, 0, 100, 320, 350));
        delay(5);
    }
    moveLeg(pwm1, 1, 375, 297, 297);
    moveLeg(pwm1, 0, 375, 307, 340);
    moveLeg(pwm1, 2, 400, 305, 320);
    delay(100);

    // Condense motion
    for (int i = 0; i <= 100; i += 5) {
        moveLegT(pwm2, 1, 375, mapValue(i, 0, 100, 402, 407), mapValue(i, 0, 100, 377, 420));
        moveLegT(pwm2, 0, 375, mapValue(100 - i, 0, 100, 402, 407), mapValue(100 - i, 0, 100, 377, 420));
        moveLegT(pwm2, 2, mapValue(100 - i, 0, 100, 350, 400), 402, 397);

        moveLeg(pwm1, 1, 375, mapValue(i, 0, 100, 297, 307), mapValue(i, 0, 100, 297, 340));
        moveLeg(pwm1, 0, 375, mapValue(100 - i, 0, 100, 297, 307), mapValue(100 - i, 0, 100, 297, 340));
        moveLeg(pwm1, 2, mapValue(100 - i, 0, 100, 350, 400), 305, 320);
        delay(10);
    }
    delay(100);

    for (int i = 0; i <= 100; i += 5) {
        moveLeg(pwm1, 1, 375, mapValue(i, 0, 100, 307, 345), mapValue(i, 0, 100, 340, 370));
        moveLeg(pwm1, 0, 375, mapValue(i, 0, 100, 297, 340), mapValue(i, 0, 100, 297, 327));
        moveLeg(pwm1, 2, 350, mapValue(i, 0, 100, 305, 355), mapValue(i, 0, 100, 320, 350));
        delay(5);
    }
    delay(100);
}

int main() {
    MoveBackward();
    return 0;
}
