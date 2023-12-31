/**
 * @file ultrasonic_sensor.cpp
 * @brief Implementation of the Ultrasonic sensor class.
 */

#include <api/Common.h>
#include <sys/_stdint.h>
#include "ultrasonic_sensor.h"

/**
 * @brief Constructor that initializes the pins and the mode for the ultrasonic sensor.
 * @param trigger_pin The pin number for the trigger signal of the ultrasonic sensor.
 * @param echo_pin The pin number for the echo signal of the ultrasonic sensor.
 * @param mode The mode of the ultrasonic sensor, either MANUAL or AUTOMATIC.
<<<<<<< HEAD
 */

UltrasonicSensor::UltrasonicSensor(uint8_t trigger_pin, uint8_t echo_pin, SonarMode mode)
    : trigger_pin_(trigger_pin), echo_pin_(echo_pin), mode_(mode)
{
=======
*/

UltrasonicSensor::UltrasonicSensor(uint8_t trigger_pin, uint8_t echo_pin, SonarMode mode)
  : trigger_pin_(trigger_pin), echo_pin_(echo_pin), mode_(mode) {
>>>>>>> 7156fcf (Large Update)
  pinMode(trigger_pin_, OUTPUT);
  pinMode(echo_pin_, INPUT);
}

/**
 * @brief Constructor that initializes the pins for the ultrasonic sensor and sets the mode to AUTOMATIC.
 * @param trigger_pin The pin number for the trigger signal of the ultrasonic sensor.
 * @param echo_pin The pin number for the echo signal of the ultrasonic sensor.
<<<<<<< HEAD
 */
UltrasonicSensor::UltrasonicSensor(uint8_t trigger_pin, uint8_t echo_pin)
    : UltrasonicSensor(trigger_pin, echo_pin, SonarMode::MANUAL) {}

/**
 * @brief Destructor that sets the trigger pin to INPUT mode and the echo pin to OUTPUT.
 */
UltrasonicSensor::~UltrasonicSensor()
{
=======
*/
UltrasonicSensor::UltrasonicSensor(uint8_t trigger_pin, uint8_t echo_pin)
  : UltrasonicSensor(trigger_pin, echo_pin, SonarMode::MANUAL) {}

/**
 * @brief Destructor that sets the trigger pin to INPUT mode and the echo pin to OUTPUT.
*/
UltrasonicSensor::~UltrasonicSensor() {
>>>>>>> 7156fcf (Large Update)
  pinMode(trigger_pin_, INPUT);
  pinMode(echo_pin_, OUTPUT);
}

/**
 * @brief Calculates the distance from measured pulse time.
<<<<<<< HEAD
 */
void UltrasonicSensor::computeDistance()
{
  static unsigned long last_us;

  digitalWrite(trigger_pin_, LOW);
  if (micros() - last_us > 2)
  {
    last_us = micros();
    digitalWrite(trigger_pin_, HIGH);
  }
  if (micros() - last_us > 10)
  {
=======
*/
void UltrasonicSensor::computeDistance() {
  static unsigned long last_us;

  digitalWrite(trigger_pin_, LOW);
  if (micros() - last_us > 2) {
    last_us = micros();
    digitalWrite(trigger_pin_, HIGH);
  }
  if (micros() - last_us > 10) {
>>>>>>> 7156fcf (Large Update)
    last_us = micros();
    digitalWrite(trigger_pin_, LOW);
  }
  unsigned long pulse_time = pulseInLong(echo_pin_, HIGH);
  distance_ = pulse_time * kSpeedOfSound * pow(10, -4) / 2;
}

/**
 * @brief Updates the ultrasonic sensor's distance and status.
<<<<<<< HEAD
 */
void UltrasonicSensor::update()
{
  if (mode_ == SonarMode::AUTOMATIC)
  {
=======
*/
void UltrasonicSensor::update() {
  if (mode_ == SonarMode::AUTOMATIC) {
>>>>>>> 7156fcf (Large Update)
    this->computeDistance();
  }
  else
  {
    if (status_)
    {
      this->computeDistance();
      status_ = false;
    }
  }
}

/**
 * @brief Sets the mode for the measurements.
 * @param mode The mode of the ultrasonic sensor, either MANUAL or AUTOMATIC.
<<<<<<< HEAD
 */
void UltrasonicSensor::setMode(SonarMode mode)
{
=======
*/
void UltrasonicSensor::setMode(SonarMode mode) {
>>>>>>> 7156fcf (Large Update)
  mode_ = mode;
}

/**
 * @brief Starts the measurement manually if mode is MANUAL.
<<<<<<< HEAD
 */
void UltrasonicSensor::startMeasurement()
{
  if (mode_ == SonarMode::MANUAL)
  {
=======
*/
void UltrasonicSensor::startMeasurement() {
  if (mode_ == SonarMode::MANUAL) {
>>>>>>> 7156fcf (Large Update)
    status_ = true;
  }
}

/**
 * @brief Checks if the ultrasonic sensor is updating the values.
 * @return True if the ultrasonic sensor is updating, false otherwise.
<<<<<<< HEAD
 */
bool UltrasonicSensor::isUpdating()
{
=======
*/
bool UltrasonicSensor::isUpdating() {
>>>>>>> 7156fcf (Large Update)
  return status_;
}

/**
 * @brief Returns the distance measured by the ultrasonic sensor.
 * @return The distance in centimeters.
<<<<<<< HEAD
 */
uint16_t UltrasonicSensor::getDistance()
{
=======
*/
uint16_t UltrasonicSensor::getDistance() {
>>>>>>> 7156fcf (Large Update)
  distance_ = constrain(distance_, 0, 400);
  return distance_;
}