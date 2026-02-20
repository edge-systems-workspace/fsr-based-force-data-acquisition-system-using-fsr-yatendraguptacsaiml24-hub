// main.cpp
#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Embedded Force Measurement System using FSR
 * @author yatendraguptacsaiml24-hub (Yatendra Kumar Gupta)
 * @date 20-02-2026
 *
 * @details
 * Reads analog force data from an FSR (Force Sensitive Resistor) sensor
 * connected to `FSR_PIN` and prints structured output to the Serial Monitor.
 * Simple thresholding is used to indicate presence of pressure.
 */

#define FSR_PIN A0

int fsrValue = 0;

/**
 * @brief Initialize Serial communication and any required peripherals.
 *
 * This function configures the Serial port at 9600 baud and prints
 * an initialization banner to the Serial Monitor.
 *
 * @return void
 */
void setup() {
    Serial.begin(9600);
    Serial.println("=== FSR Force Measurement System Initialized ===");
}

/**
 * @brief Main loop: read FSR value and print status to Serial.
 *
 * Reads the analog value from the FSR sensor on `FSR_PIN`, prints the raw ADC
 * value and a simple thresholded status message. Loop delays 500 ms between reads.
 *
 * @return void
 */
void loop() {

    fsrValue = analogRead(FSR_PIN);

    Serial.print("Raw ADC Value: ");
    Serial.println(fsrValue);

    if (fsrValue > 100) {
        Serial.println("Pressure Detected!");
    } else {
        Serial.println("No Significant Pressure.");
    }
    delay(500);
}
