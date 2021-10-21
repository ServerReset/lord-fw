/** Copyright 2021 andresteare
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x8888  
#define PRODUCT_ID      0x6969
#define DEVICE_VER      0x0001
#define MANUFACTURER   nKeys
#define PRODUCT         Dino104

/* key matrix size */
#define MATRIX_ROWS 12
#define MATRIX_COLS 11

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */

#define DIODE_DIRECTION COL2ROW

#define MATRIX_ROW_PINS { A15, B4, B6, A7, A5, A3, A2, A4, A6, B7, B5, B3 } 
#define MATRIX_COL_PINS { B12, B13, B14, B15, A8, A9, A10, A13, B10, B1, B0 } 
