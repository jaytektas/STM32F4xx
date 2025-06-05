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

#define BOARD_NAME "JAYTEK CNC REV2 2025"
#define STEP_OUTMODE                GPIO_BITBAND

#define DIRECTION_OUTMODE           GPIO_BITBAND
#define LIMIT_INMODE                GPIO_BITBAND

#define X_DIRECTION_PORT            GPIOE
#define X_DIRECTION_PIN             6
#define X_STEP_PORT                 GPIOE
#define X_STEP_PIN                  5
#define X_LIMIT_PORT                GPIOE
#define X_LIMIT_PIN                 8

#define Y_DIRECTION_PORT            GPIOE
#define Y_DIRECTION_PIN             4
#define Y_STEP_PORT                 GPIOE
#define Y_STEP_PIN                  3
#define Y_LIMIT_PORT                GPIOE
#define Y_LIMIT_PIN                 9

#define Z_DIRECTION_PORT            GPIOE
#define Z_DIRECTION_PIN             2
#define Z_STEP_PORT                 GPIOE
#define Z_STEP_PIN                  1
#define Z_LIMIT_PORT                GPIOE
#define Z_LIMIT_PIN                 10

// Define stepper driver enable/disable output pin.
#define STEPPERS_ENABLE_PORT        GPIOE
#define STEPPERS_ENABLE_PIN         0
#define STEPPERS_ENABLE_MASK        STEPPERS_ENABLE_BIT

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE

#define M3_DIRECTION_PORT           GPIOB
#define M3_DIRECTION_PIN            9
#define M3_STEP_PORT                GPIOB
#define M3_STEP_PIN                 8
#define M3_LIMIT_PORT               GPIOE
#define M3_LIMIT_PIN                11
#endif

#if N_ABC_MOTORS > 1
#define M4_AVAILABLE
#define M4_DIRECTION_PORT           GPIOB
#define M4_DIRECTION_PIN            7
#define M4_STEP_PORT                GPIOB
#define M4_STEP_PIN                 6
#define M4_LIMIT_PORT               GPIOE
#define M4_LIMIT_PIN                12
#endif

#if N_ABC_MOTORS > 2
#define M5_AVAILABLE
#define M5_DIRECTION_PORT           GPIOD
#define M5_DIRECTION_PIN            7
#define M5_STEP_PORT                GPIOD
#define M5_STEP_PIN                 4
#define M5_LIMIT_PORT               GPIOE
#define M5_LIMIT_PIN                13
#endif

// Define driver spindle pins
#if DRIVER_SPINDLE_ENABLE
#define SPINDLE_ENABLE_PORT         GPIOD
#define SPINDLE_ENABLE_PIN          12
#if DRIVER_SPINDLE_ENABLE & SPINDLE_PWM
#define SPINDLE_PWM_PORT            GPIOD
#define SPINDLE_PWM_PIN             14
#endif
#if DRIVER_SPINDLE_ENABLE & SPINDLE_DIR
#define SPINDLE_DIRECTION_PORT      GPIOD
#define SPINDLE_DIRECTION_PIN       13
#endif
#endif //DRIVER_SPINDLE_ENABLE

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT          GPIOD
#define COOLANT_FLOOD_PIN           3
#define COOLANT_MIST_PORT           GPIOD
#define COOLANT_MIST_PIN            2

// Define user-control controls (cycle start, reset, feed hold) input pins.
#define CONTROL_INMODE              GPIO_BITBAND

#define CYCLE_START_PORT            GPIOC
#define CYCLE_START_PIN             4

#define FEED_HOLD_PORT              GPIOC
#define FEED_HOLD_PIN               5

#define ESTOP_PORT                  GPIOB
#define ESTOP_PIN                   0

#define RESET_PORT                  GPIOB
#define RESET_PIN                   1

#define PROBE_PORT                  GPIOB
#define PROBE_PIN                   2

#define SAFETY_DOOR_PORT            GPIOE
#define SAFETY_DOOR_PIN             7


// aux input
#define AUXINPUT0_PORT              GPIOE
#define AUXINPUT0_PIN               14
#define AUXINPUT1_PORT              GPIOE
#define AUXINPUT1_PIN               15
#define AUXINPUT2_PORT              GPIOB
#define AUXINPUT2_PIN               12
#define AUXINPUT3_PORT              GPIOC
#define AUXINPUT3_PIN               13
#define AUXINPUT4_PORT              GPIOD
#define AUXINPUT4_PIN               8
#define AUXINPUT5_PORT              GPIOD
#define AUXINPUT5_PIN               9
#define AUXINPUT6_PORT              GPIOD
#define AUXINPUT6_PIN               10
#define AUXINPUT7_PORT              GPIOD
#define AUXINPUT7_PIN               11

// aux analog inputs
#define AUXINPUT0_ANALOG_PORT      GPIOA
#define AUXINPUT0_ANALOG_PIN       0
#define AUXINPUT1_ANALOG_PORT      GPIOA
#define AUXINPUT1_ANALOG_PIN       1
#define AUXINPUT2_ANALOG_PORT      GPIOA
#define AUXINPUT2_ANALOG_PIN       2
#define AUXINPUT3_ANALOG_PORT      GPIOA
#define AUXINPUT3_ANALOG_PIN       3
#define AUXINPUT4_ANALOG_PORT      GPIOA
#define AUXINPUT4_ANALOG_PIN       4
#define AUXINPUT5_ANALOG_PORT      GPIOA
#define AUXINPUT5_ANALOG_PIN       5
#define AUXINPUT6_ANALOG_PORT      GPIOA
#define AUXINPUT6_ANALOG_PIN       6
#define AUXINPUT7_ANALOG_PORT      GPIOA
#define AUXINPUT7_ANALOG_PIN       7

// aux outputs
#define AUXOUTPUT0_PORT             GPIOD
#define AUXOUTPUT0_PIN              1
#define AUXOUTPUT1_PORT             GPIOD
#define AUXOUTPUT1_PIN              0
#define AUXOUTPUT2_PORT             GPIOA
#define AUXOUTPUT2_PIN              8
#define AUXOUTPUT3_PORT             GPIOC
#define AUXOUTPUT3_PIN              9
#define AUXOUTPUT4_PORT             GPIOC
#define AUXOUTPUT4_PIN              8
#define AUXOUTPUT5_PORT             GPIOC
#define AUXOUTPUT5_PIN              7
#define AUXOUTPUT6_PORT             GPIOC
#define AUXOUTPUT6_PIN              6
#define AUXOUTPUT7_PORT             GPIOD
#define AUXOUTPUT7_PIN              15
