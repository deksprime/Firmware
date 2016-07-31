/****************************************************************************
 *
 *   Copyright (c) 2013-2015 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/*
 * @file system_params.c
 *
 * System wide parameters
 */

/**
 * Auto-start script index.
 *
 * CHANGING THIS VALUE REQUIRES A RESTART. Defines the auto-start script used to bootstrap the system.
 *
 * @reboot_required true
 * @min 0
 * @max 99999
 * @group System
 */
PARAM_DEFINE_INT32(SYS_AUTOSTART, 0);

/**
 * Automatically configure default values.
 *
 * Set to 1 to reset parameters on next system startup (setting defaults).
 * Platform-specific values are used if available.
 * RC* parameters are preserved.
 *
 * @min 0
 * @max 1
 * @value 0 Keep parameters
 * @value 1 Reset parameters
 * @group System
 */
PARAM_DEFINE_INT32(SYS_AUTOCONFIG, 0);

/**
 * Set usage of IO board
 *
 * Can be used to use a standard startup script but with a FMU only set-up. Set to 0 to force the FMU only set-up.
 *
 * @boolean
 * @min 0
 * @max 1
 * @group System
 */
PARAM_DEFINE_INT32(SYS_USE_IO, 1);

/**
 * Set restart type
 *
 * Set by px4io to indicate type of restart
 *
 * @min 0
 * @max 2
 * @value 0 Data survives resets
 * @value 1 Data survives in-flight resets only
 * @value 2 Data does not survive reset
 * @group System
 */
PARAM_DEFINE_INT32(SYS_RESTART_TYPE, 2);

/**
 * Set multicopter estimator group
 *
 * Set the group of estimators used for multicopters and vtols
 *
 * @value 0 position_estimator_inav, attitude_estimator_q
 * @value 1 local_position_estimator, attitude_estimator_q
 * @value 2 ekf2
 *
 * @min 0
 * @max 2
 * @reboot_required true
 * @group System
 */
PARAM_DEFINE_INT32(SYS_MC_EST_GROUP, 0);

/**
 * TELEM2 as companion computer link
 *
 * CHANGING THIS VALUE REQUIRES A RESTART. Configures the baud rate of the TELEM2 connector as
 * companion computer interface.
 *
 * @value 0 Disabled
 * @value 10 FrSky Telemetry
 * @value 921600 Companion Link (921600 baud, 8N1)
 * @value 57600 Companion Link (57600 baud, 8N1)
 * @value 157600 OSD (57600 baud, 8N1)
 * @value 257600 Command Receiver (57600 baud, 8N1)
 * @value 357600 Normal Telemetry (57600 baud, 8N1)
 * @value 1921600 ESP8266 (921600 baud, 8N1)
 *
 * @min 0
 * @max 1921600
 * @reboot_required true
 * @group System
 */
PARAM_DEFINE_INT32(SYS_COMPANION, 157600);

/**
 * Companion computer port (TTY)
 *
 * @min -1
 * @max 3
 * @value -1 default
 * @value 0 /dev/ttyS0
 * @value 1 /dev/ttyS1
 * @value 2 /dev/ttyS2
 * @value 3 /dev/ttyS3
 * @reboot_required true
 * @group System
 */
PARAM_DEFINE_INT32(SYS_COMP_TTY, -1);

/**
* Parameter version
*
* This monotonically increasing number encodes the parameter compatibility set.
* whenever it increases parameters might not be backwards compatible and
* ground control stations should suggest a fresh configuration.
*
* @min 0
* @group System
*/
PARAM_DEFINE_INT32(SYS_PARAM_VER, 1);

/**
 * SD logger
 *
 * @value 0 sdlog2 (default)
 * @value 1 new logger
 * @min 0
 * @max 1
 * @reboot_required true
 * @group System
 */
PARAM_DEFINE_INT32(SYS_LOGGER, 0);
