/*
* This file is part of the Magzor I2C Library.
*
* The Magzor I2C Library is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser  General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* The Magzor I2C Library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser  General Public License for more details.
*
* You should have received a copy of the GNU Lesser  General Public License
* along with the Magzor I2C Library.  If not, see <http://www.gnu.org/licenses/>.
*/

#if defined(ARDUINO)

#ifndef MLOGGER_ARDUINO_H
#define MLOGGER_ARDUINO_H

#include "Preprocessor_Directives.h"

class MLogger{
public:
	static void debug(const String& message);
	static void error(const String& message);
	static void fatal(const String& message);
	static void info(const String& message);
	static void trace(const String& message);
	static void warn(const String& message);

	static bool is_debug_enabled();
	static bool is_error_enabled();
	static bool is_fatal_enabled();
	static bool is_info_enabled();
	static bool is_trace_enabled();
	static bool is_warn_enabled();
	
	static void set_debug_enabled(bool b);
	static void set_error_enabled(bool b);
	static void set_fatal_enabled(bool b);
	static void set_info_enabled(bool b);
	static void set_trace_enabled(bool b);
	static void set_warn_enabled(bool b);
	
	static void set_all_enabled();
	static void set_all_disabled();
	
private:
	static bool debug_enabled;
	static bool error_enabled;
	static bool fatal_enabled;
	static bool info_enabled;
	static bool trace_enabled;
	static bool warn_enabled;
	
	static bool print(const String& message);
	static bool write(const String& message);
};

#endif

#endif