/**
 * @file dc_motor.cpp
 * @brief Implementation of the Motor class.
 */

#include <api/Common.h>
#include <sys/_intsup.h>
#include <sys/_stdint.h>
#include "dc_motor.h"

/**
 * @brief Constructor that initializes the pins for the motor.
 * @param forward_pin The pin number for the forward direction of the motor.
 * @param backward_pin The pin number for the backward direction of the motor.
<<<<<<< HEAD
 */
=======
*/
>>>>>>> 7156fcf (Large Update)
Motor::Motor(uint8_t forward_pin, uint8_t backward_pin)
    : forwardPwm(forward_pin), backwardPwm(backward_pin) {}

/**
 * @brief Destructor that ends the pwm modules.
<<<<<<< HEAD
 */
Motor::~Motor()
{
=======
*/
Motor::~Motor() {
>>>>>>> 7156fcf (Large Update)
  forwardPwm.end();
  backwardPwm.end();
  enabled_ = false;
}

/**
 * @brief Initializes the PWM outputs for the motor.
 * @return True if the initialization was successful, false otherwise.
<<<<<<< HEAD
 */
bool Motor::init()
{
=======
*/
bool Motor::init() {
>>>>>>> 7156fcf (Large Update)
  acceleration_ = MAX_ACCELERATION;
  frequency_ = 33000;
  forwardPwm.begin(frequency_, 0);
  backwardPwm.begin(frequency_, 0);
  enabled_ = true;
  return enabled_;
}

/**
 * @brief Updates the motor speed and direction according to the setpoint and acceleration.
<<<<<<< HEAD
 */
void Motor::update()
{
  static unsigned long last_ms;

  update_delay_ = map(acceleration_, MIN_ACCELERATION, MAX_ACCELERATION,
                      MIN_UPDATE_DELAY, MAX_UPDATE_DELAY);

  // adjust the current speed to the setpoint speed in time interval
  if (millis() - last_ms > update_delay_)
  {
    last_ms = millis();
    if (setpoint_speed_ != current_speed_)
    {
=======
*/
void Motor::update() {
  static unsigned long last_ms;

  update_delay_ = map(acceleration_, MIN_ACCELERATION, MAX_ACCELERATION,
                      MIN_UPDATE_DELAY, MAX_UPDATE_DELAY);

  // adjust the current speed to the setpoint speed in time interval
  if (millis() - last_ms > update_delay_) {
    last_ms = millis();
    if (setpoint_speed_ != current_speed_) {
>>>>>>> 7156fcf (Large Update)
      status_ = true;
      if (setpoint_speed_ > current_speed_)
      {
        current_speed_++;
      }
      else if (setpoint_speed_ < current_speed_)
      {
        current_speed_--;
      }
    }
    else
    {
      status_ = false;
    }

    // change the duty cycle of the pins, depending on the direction
    if (current_speed_ < 0)
    {
      forwardPwm.pulse_perc(0);
      backwardPwm.pulse_perc(abs(current_speed_));
    }
    else
    {
      forwardPwm.pulse_perc(current_speed_);
      backwardPwm.pulse_perc(0);
    }
  }
}

/**
 * @brief Sets the desired speed for the motor.
 * @param speed The speed in percentage, from -100 (backward) to 100 (forward).
<<<<<<< HEAD
 */
void Motor::setSpeed(int8_t speed)
{
=======
*/
void Motor::setSpeed(int8_t speed) {
>>>>>>> 7156fcf (Large Update)
  setpoint_speed_ = constrain(speed, MIN_SPEED, MAX_SPEED);
}

/**
 * @brief Sets the acceleration for the motor.
 * @param acceleration The acceleration in percentage, from 0 (no acceleration) to 100 (maximum acceleration).
<<<<<<< HEAD
 */
void Motor::setAcceleration(uint8_t acceleration)
{
=======
*/
void Motor::setAcceleration(uint8_t acceleration) {
>>>>>>> 7156fcf (Large Update)
  acceleration_ = constrain(acceleration, MIN_ACCELERATION, MAX_ACCELERATION);
}

/**
 * @brief Stops the motor immediately.
 * @return True if the motor was stopped, false otherwise.
<<<<<<< HEAD
 */
bool Motor::stop()
{
=======
*/
bool Motor::stop() {
>>>>>>> 7156fcf (Large Update)
  // immediately set both current speed and setpoint speed to 0
  acceleration_ = MAX_ACCELERATION;
  current_speed_ = 0;
  setpoint_speed_ = 0;
  enabled_ = false;
  return enabled_;
}

/**
 * @brief Checks if the motor is updating its speed and direction.
 * @return True if the motor is updating, false otherwise.
<<<<<<< HEAD
 */
bool Motor::isUpdating()
{
=======
*/
bool Motor::isUpdating() {
>>>>>>> 7156fcf (Large Update)
  return status_;
}

/**
 * @brief Returns the current speed of the motor.
 * @return The speed in percentage, from -100 (backward) to 100 (forward).
<<<<<<< HEAD
 */
int8_t Motor::getSpeed()
{
=======
*/
int8_t Motor::getSpeed() {
>>>>>>> 7156fcf (Large Update)
  return current_speed_;
}