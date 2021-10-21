/* Copyright 2021 andresteare
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

#include "quantum.h"

#define LAYOUT( \
	K00,       K01, K111, K02, K112, K03, K113, K04, K114, K05, K115, K06, K116,        K07, K117, K08,       K118, K09, K119, K010, \
	K10, K100, K11, K101, K12, K102, K13, K103, K14, K104, K15, K105, K16, K106, K96,   K17, K107, K18,       K108, K19, K109, K110, \
	K20, K90,  K21, K91,  K22, K92,  K23, K93,  K24, K94,  K25, K95,  K26, K36,         K27, K97,  K28,       K98,  K29, K99,  K210, \
 	K30, K80,  K31, K81,  K32, K82,  K33, K83,  K34, K84,  K35, K85,     K86,                                 K88,  K39, K89,  K310, \
	K40, K70,  K41, K71,  K42, K72,  K43, K73,  K44, K74,  K45, K75,  K46,  K76,             K77,             K78,  K49, K79,  K410, \
	K50, K60,  K51, K61,  K52,       K53,       K54,       K55, K65,  K56,  K66,        K57, K67,  K58,       K68,  K59, K69,  K510  \
){ \
	{K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K010},  \
	{K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K110},  \
	{K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29       },  \
	{K30,  K31,  K32,  K33,  K34,  K35,  K36,              K39,  K310},  \
	{K40,  K41,  K42,  K43,  K44,  K45,  K46,              K49       },  \
	{K50,  K51,  K52,  K53,  K54,  K55,  K56,  K57,  K58,  K59,  K510},  \
	{K60,  K61,                    K65,  K66,  K67,  K68,  K69       },  \
	{K70,  K71,  K72,  K73,  K74,  K75,  K76,  K77,  K78,  K79       },  \
	{K80,  K81,  K82,  K83,  K84,  K08,  K86,        K88,  K89       },  \
	{K90,  K91,  K92,  K93,  K94,  K95,  K96,  K97,  K98,  K99       },  \
	{K100, K101, K102, K103, K104, K105, K106, K107, K108, K109      },  \
	{      K111, K112, K113, K114, K115, K116, K117, K118, K119      },  \
}
