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
#else
#define ROOT_PATH "."
#endif


/* CONSTANTS. */
const std::string EXAMPLES_PATH         = ROOT_PATH"/examples";
const std::string RESOURCE_PATH         = ROOT_PATH"/resources";
const std::string CONFIG_FILE           = "config.json";
const std::string DEFAULT_FONT          = "calibri";

/* Default font size. */
constexpr uint8_t DEFAULT_FONT_SIZE     = 15;

#endif // CONSTANTS_H

