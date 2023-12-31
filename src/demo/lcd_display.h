/**
 * @file lcd_display.h
 * @brief Expanded commands and specific routines for the LCD display.
 * @author Maximilian Kautzsch
 * @date Created on 23rd December 2023
 * @date Last modified on 25th December 2023 by Maximilian Kautzsch,
 * Finnian Belger & Logan Weigoldt
*/

#include <sys/_stdint.h>
#include <LiquidCrystal_I2C.h>

// LCD display dimensions
const uint8_t columns = 16;
const uint8_t rows = 2;

// Create LCD object
LiquidCrystal_I2C lcd(0x27, columns, rows);

/**
 * @brief Function to format numbers into strings with leading spaces.
 * @param num The number to format.
 * @param max_digits The maximum number of digits in the formatted string.
 * @param show_sign Checks if the sign of the number should be displayed.
 * @return The formatted string.
 */
String formatNumber(int16_t num, uint8_t max_digits, bool show_sign) {
  // Get the absolute value of the maximum and minimum number that
  // can be displayed according to max_digits
  uint16_t limit = pow(10, max_digits) - 1;

  // Convert number into string and get the sign from the number
  String str = String(abs(constrain(num, -limit, limit)));
  String sign = (num > 0)   ? "+"
                : (num < 0) ? "-"
                            : " ";

  // Add leading spaces until the string length reaches max_digits
  if (show_sign) {
    str = sign + str;
  }
  while (str.length() < max_digits + (show_sign ? 1 : 0)) {
    str = " " + str;
  }

  return str;
}

/**
 * @brief Function to update the LCD display with the current sensor readings.
 * @tparam T The type of the sensor reading.
 * @param values An array of PrintValues structs holding the sensor readings.
 * @param size The number of elements in the array.
 */
void lcdUpdate(int16_t last_num, int16_t current_num, uint8_t cursor_x, uint8_t cursor_y, uint8_t max_digits, bool show_sign) {
  if (last_num != current_num) {
    lcd.setCursor(cursor_x, cursor_y);
    lcd.print(formatNumber(current_num, max_digits, show_sign));
    last_num = current_num;
  }
}

/**
 * @brief Clear the content of the LCD display without using large delays.
 */
void lcdClear() {
  for (uint8_t i = 0; i < rows; i++) {
    for (uint8_t j = 0; j < columns; j++) {
      lcd.setCursor(j, i);
      lcd.print(" ");
    }
  }
}

/**
 * @brief Bootup routine for the LCD display.
 */
void lcdBootup() {
  lcd.setCursor(2, 0);
  lcd.print("INITIALIZING");

  // Progress bar animation
  lcd.setCursor(2, 1);
  lcd.print("[----------]");
  delay(100);
  for (uint8_t i = 3; i < 13; i++) {
    lcd.setCursor(i, 1);
    lcd.print("=");
    delay(100);
  }
}

/**
 * @brief Setup routine for printing the values on the LCD display.
*/

void lcdPrintValueSetup() {
  lcd.setCursor(0, 0);
  lcd.print("L");
  lcd.setCursor(4, 0);
  lcd.print("M");
  lcd.setCursor(8, 0);
  lcd.print("R");
  lcd.setCursor(0, 1);
  lcd.print("X");
  lcd.setCursor(5, 1);
  lcd.print("Y");
  lcd.setCursor(10, 1);
  lcd.print("C");
  lcd.setCursor(13, 1);
  lcd.print("V");
}

/**
 * @brief Shutdown routine for the LCD display.
 */
void lcdShutdown() {
  lcdClear();
  lcd.setCursor(6, 0);
  lcd.print("RACE");
  lcd.setCursor(4, 1);
  lcd.print("FINISHED");
  delay(1000);
  lcdClear();

  // Countdown for power saving mode
  lcd.setCursor(3, 0);
  lcd.print("POWER SAVING");
  lcd.setCursor(3, 1);
  lcd.print("MODE IN 3.");
  for (uint8_t i = 2; i > 0; i--) {
    delay(500);
    lcd.setCursor(11, 1);
    lcd.print(i);
  }
  delay(500);
}