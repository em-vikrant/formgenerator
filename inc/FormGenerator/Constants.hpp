/* File: Constants.hpp
 * Header file to include all the constants.
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

/* STD includes. */
#include <string>

/* # defines. */
#ifdef _ROOT_PATH
#define ROOT_PATH _ROOT_PATH
#endif

/* CONSTANTS. */
const std::string DEFAULT_FONT  = std::string(ROOT_PATH) + std::string("/resources/fonts/CalibriRegular.ttf");
const std::string CALIBRI_FONT  = std::string(ROOT_PATH) + std::string("/resources/fonts/CalibriRegular.ttf");
const std::string TUFFY_FONT    = std::string(ROOT_PATH) + std::string("/resources/fonts/tuffy.ttf");

/* Default button configs. */
constexpr float defaultButtonWidth      = 80;
constexpr float defaultButtonHeight     = 30;

/* Default textbox configs. */
constexpr float defaultTextBoxWidth     = 250;
constexpr float defaultTextBoxHeight    = 100;

/* Default character size. */
constexpr uint8_t defaultFontSize       = 15;

#endif // CONSTANTS_H
