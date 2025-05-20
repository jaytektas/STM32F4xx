/*
  jaytek_cnc_map.h - driver code for STM32F407 ARM processors

  Part of grblHAL

  Copyright (c) 2023 fitch22

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#if N_ABC_MOTORS > 6
#error "JAYTEK supports 6 motors max."
#endif

#if !(defined(STM32F407xx) || defined(STM32F429xx)) || HSE_VALUE != 8000000
#error "This board has a STM32F407 processor with a 8MHz crystal, select a corresponding build!"
#endif

#define BOARD_NAME "JAYTEK CNC 2023"

#define STEP_OUTMODE                GPIO_BITBAND

#define DIRECTION_OUTMODE           GPIO_BITBAND
#define LIMIT_INMODE                GPIO_BITBAND

#define X_DIRECTION_PORT            GPIOC
#define X_DIRECTION_PIN             1
#define X_STEP_PORT                 GPIOC
#define X_STEP_PIN                  2
#define X_LIMIT_PORT                GPIOE
#define X_LIMIT_PIN                 0

#define Y_DIRECTION_PORT            GPIOC
#define Y_DIRECTION_PIN             3
#define Y_STEP_PORT                 GPIOC
#define Y_STEP_PIN                  4
#define Y_LIMIT_PORT                GPIOE
#define Y_LIMIT_PIN                 1

#define Z_DIRECTION_PORT            GPIOC
#define Z_DIRECTION_PIN             5
#define Z_STEP_PORT                 GPIOC
#define Z_STEP_PIN                  6
#define Z_LIMIT_PORT                GPIOE
#define Z_LIMIT_PIN                 2

// Define stepper driver enable/disable output pin.
#define STEPPERS_ENABLE_PORT        GPIOC
#define STEPPERS_ENABLE_PIN         13
#define STEPPERS_ENABLE_MASK        STEPPERS_ENABLE_BIT

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE

#define M3_STEP_PORT                GPIOC
#define M3_STEP_PIN                 8
#define M3_DIRECTION_PORT           GPIOC
#define M3_DIRECTION_PIN            7
#define M3_LIMIT_PORT               GPIOE
#define M3_LIMIT_PIN                3
#endif

#if N_ABC_MOTORS > 1
#define M4_AVAILABLE
#define M4_STEP_PORT                GPIOC
#define M4_STEP_PIN                 10
#define M4_DIRECTION_PORT           GPIOC
#define M4_DIRECTION_PIN            9
#define M4_LIMIT_PORT               GPIOE
#define M4_LIMIT_PIN                4
#endif

#if N_ABC_MOTORS > 2
#define M5_AVAILABLE
#define M5_STEP_PORT                GPIOC
#define M5_STEP_PIN                 12
#define M5_DIRECTION_PORT           GPIOC
#define M5_DIRECTION_PIN            11
#define M5_LIMIT_PORT               GPIOE
#define M5_LIMIT_PIN                5
#endif

// Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_PORT         GPIOB
#define SPINDLE_ENABLE_PIN          7

// Define spindle direction port.
#define SPINDLE_DIRECTION_PORT      GPIOB
#define SPINDLE_DIRECTION_PIN       8

// Define spindle PWM output pin.
#define SPINDLE_PWM_PORT_BASE       GPIOB_BASE
#define SPINDLE_PWM_PIN             9

// Define spindle DAC output pin.
#define SPINDLE_DAC_PORT_BASE       GPIOA_BASE
#define SPINDLE_DAC_PIN             4

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT          GPIOB
#define COOLANT_FLOOD_PIN           11
#define COOLANT_MIST_PORT           GPIOB
#define COOLANT_MIST_PIN            12

// Define user-control controls (cycle start, reset, feed hold) input pins.
#define CONTROL_PORT                GPIOE
#define SAFETY_DOOR_PIN             7
#define CYCLE_START_PIN             8
#define FEED_HOLD_PIN               9
#define RESET_PIN                   10
#define CONTROL_INMODE              GPIO_MAP

// Define probe switch input pin.
#define PROBE_PORT                  GPIOE
#define PROBE_PIN                   6

#ifdef HAS_IOPORTS

// aux input
#define AUXINPUT0_PORT              GPIOE
#define AUXINPUT0_PIN               11

// aux outputs
#define AUXOUTPUT0_PORT             GPIOB
#define AUXOUTPUT0_PIN              10    // vacuum
#define AUXOUTPUT1_PORT             GPIOB
#define AUXOUTPUT1_PIN              13    // aux0
#define AUXOUTPUT2_PORT             GPIOB
#define AUXOUTPUT2_PIN              14    // aux1
#define AUXOUTPUT3_PORT             GPIOB
#define AUXOUTPUT3_PIN              15    // aux2
#endif
