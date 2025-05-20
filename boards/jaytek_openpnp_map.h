/*
  jaytek_cnc_map.h - driver code for STM32F407 ARM processors

  Part of grblHAL

  Copyright (c) 2024 JAYTEK

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

#undef I2C_ENABLE
#define  I2C_ENABLE 1
#define I2C_PORT 2
#define I2C_KHZ 400

#if N_ABC_MOTORS > 6
#error "JAYTEK supports 6 motors max."
#endif

#if !(defined(STM32F407xx) || defined(STM32F429xx)) || HSE_VALUE != 8000000
#error "This board has a STM32F407 processor with a 8MHz crystal, select a corresponding build!"
#endif

#define BOARD_NAME "JAYTEK OPENPNP 2024"
#define HAS_BOARD_INIT

// onboard stepper driver module options (set flags in platformio.ini)
//#define TRINAMIC_ENABLE   2130 // Trinamic TMC2130 stepper driver support. NOTE: work in progress.
//#define TRINAMIC_ENABLE   5160 // Trinamic TMC5160 stepper driver support. NOTE: work in progress.
//#define TRINAMIC_ENABLE   2209 // Trinamic TMC2209 stepper driver support. NOTE: work in progress.
//#define TRINAMIC_I2C         1 // Trinamic I2C - SPI bridge interface.
//#define TRINAMIC_DEV         1 // Development mode, adds a few M-codes to aid debugging. Do not enable in production code.

#define STEP_OUTMODE                GPIO_BITBAND
#define DIRECTION_OUTMODE           GPIO_BITBAND
#define LIMIT_INMODE                GPIO_BITBAND

#define X_DIRECTION_PORT            GPIOC
#define X_DIRECTION_PIN             2
#define X_STEP_PORT                 GPIOC
#define X_STEP_PIN                  3
#define X_ENABLE_PORT               GPIOC
#define X_ENABLE_PIN                1
#define X_LIMIT_PORT                GPIOE
#define X_LIMIT_PIN                 8

#define Y_DIRECTION_PORT            GPIOC
#define Y_DIRECTION_PIN             13
#define Y_STEP_PORT                 GPIOC
#define Y_STEP_PIN                  14
#define Y_ENABLE_PORT               GPIOE
#define Y_ENABLE_PIN                6
#define Y_LIMIT_PORT                GPIOE
#define Y_LIMIT_PIN                 9

#define Z_DIRECTION_PORT            GPIOE
#define Z_DIRECTION_PIN             3
#define Z_STEP_PORT                 GPIOE
#define Z_STEP_PIN                  4
#define Z_ENABLE_PORT               GPIOE
#define Z_ENABLE_PIN                2
#define Z_LIMIT_PORT                GPIOE
#define Z_LIMIT_PIN                 10


// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE

#define M3_DIRECTION_PORT           GPIOB
#define M3_DIRECTION_PIN            8
#define M3_STEP_PORT                GPIOB
#define M3_STEP_PIN                 9
#define M3_ENABLE_PORT              GPIOB
#define M3_ENABLE_PIN               7
#define M3_LIMIT_PORT               GPIOE
#define M3_LIMIT_PIN                11
#endif

#if N_ABC_MOTORS > 1
#define M4_AVAILABLE

#define M4_DIRECTION_PORT           GPIOB
#define M4_DIRECTION_PIN            4
#define M4_STEP_PORT                GPIOB
#define M4_STEP_PIN                 5
#define M4_ENABLE_PORT              GPIOD
#define M4_ENABLE_PIN               7
#define M4_LIMIT_PORT               GPIOE
#define M4_LIMIT_PIN                12
#endif

#if N_ABC_MOTORS > 2
#define M5_AVAILABLE

#define M5_DIRECTION_PORT           GPIOD
#define M5_DIRECTION_PIN            4
#define M5_STEP_PORT                GPIOD
#define M5_STEP_PIN                 5
#define M5_ENABLE_PORT              GPIOD
#define M5_ENABLE_PIN               3
#define M5_LIMIT_PORT               GPIOE
#define M5_LIMIT_PIN                13
#endif

#if DRIVER_SPINDLE_ENABLE
// Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_PORT         GPIOD
#define SPINDLE_ENABLE_PIN          11

// Define spindle direction port.
#define SPINDLE_DIRECTION_PORT      GPIOD
#define SPINDLE_DIRECTION_PIN       10

// Define spindle PWM output pin.
#define SPINDLE_PWM_PORT            GPIOA
#define SPINDLE_PWM_PIN             8
#endif // DRIVER_SPINDLE_ENABLE

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT          GPIOD
#define COOLANT_FLOOD_PIN           12
#define COOLANT_MIST_PORT           GPIOD
#define COOLANT_MIST_PIN            13

// Define user-control controls (cycle start, reset, feed hold) input pins.
#define CONTROL_INMODE              GPIO_BITBAND
#define CYCLE_START_PORT            GPIOC
#define CYCLE_START_PIN             4

#define FEED_HOLD_PORT              GPIOC
#define FEED_HOLD_PIN               5

//#define SAFETY_DOOR_PORT            GPIOB
//#define SAFETY_DOOR_PIN             0

#define ESTOP_PORT                  GPIOB
#define ESTOP_PIN                   1

#define RESET_PORT                  GPIOB
#define RESET_PIN                   2

// Define probe switch input pin.
#define PROBE_PORT                  GPIOE
#define PROBE_PIN                   7

// aux input
#define AUXINPUT0_PORT              GPIOE
#define AUXINPUT0_PIN               14
#define AUXINPUT1_PORT              GPIOE
#define AUXINPUT1_PIN               15
#define AUXINPUT2_PORT              GPIOB
#define AUXINPUT2_PIN               12
#define AUXINPUT3_PORT              GPIOB
#define AUXINPUT3_PIN               13
#define AUXINPUT4_PORT              GPIOB
#define AUXINPUT4_PIN               14
#define AUXINPUT5_PORT              GPIOB
#define AUXINPUT5_PIN               15
#define AUXINPUT6_PORT              GPIOD
#define AUXINPUT6_PIN               8
#define AUXINPUT7_PORT              GPIOD
#define AUXINPUT7_PIN               9

// aux analog inputs
#define AUXINPUT0_ANALOG_PORT      GPIOA
#define AUXINPUT0_ANALOG_PIN       1
#define AUXINPUT1_ANALOG_PORT      GPIOA
#define AUXINPUT1_ANALOG_PIN       0
#define AUXINPUT2_ANALOG_PORT      GPIOA
#define AUXINPUT2_ANALOG_PIN       3
#define AUXINPUT3_ANALOG_PORT      GPIOA
#define AUXINPUT3_ANALOG_PIN       2
#define AUXINPUT4_ANALOG_PORT      GPIOA
#define AUXINPUT4_ANALOG_PIN       5
#define AUXINPUT5_ANALOG_PORT      GPIOA
#define AUXINPUT5_ANALOG_PIN       4
#define AUXINPUT6_ANALOG_PORT      GPIOA
#define AUXINPUT6_ANALOG_PIN       7
#define AUXINPUT7_ANALOG_PORT      GPIOA
#define AUXINPUT7_ANALOG_PIN       6

// aux outputs
#define AUXOUTPUT0_PORT             GPIOD
#define AUXOUTPUT0_PIN              14
#define AUXOUTPUT1_PORT             GPIOD
#define AUXOUTPUT1_PIN              15
#define AUXOUTPUT2_PORT             GPIOC
#define AUXOUTPUT2_PIN              6
#define AUXOUTPUT3_PORT             GPIOC
#define AUXOUTPUT3_PIN              7
#define AUXOUTPUT4_PORT             GPIOC
#define AUXOUTPUT4_PIN              8
#define AUXOUTPUT5_PORT             GPIOC
#define AUXOUTPUT5_PIN              9
#define AUXOUTPUT6_PORT             GPIOD
#define AUXOUTPUT6_PIN              0
#define AUXOUTPUT7_PORT             GPIOD
#define AUXOUTPUT7_PIN              1

#if TRINAMIC_UART_ENABLE

#undef TRINAMIC_UART_ENABLE
#define TRINAMIC_UART_ENABLE        2

// X UART
#define MOTOR_UARTX_PORT            GPIOC
#define MOTOR_UARTX_PIN             0

// Y UART
#define MOTOR_UARTY_PORT            GPIOE
#define MOTOR_UARTY_PIN             5

// Z UART
#define MOTOR_UARTZ_PORT            GPIOE
#define MOTOR_UARTZ_PIN             1

// A UART
#ifdef  M3_AVAILABLE
#define MOTOR_UARTM3_PORT           GPIOB
#define MOTOR_UARTM3_PIN            6
#endif

// B UART
#ifdef  M4_AVAILABLE
#define MOTOR_UARTM4_PORT           GPIOD
#define MOTOR_UARTM4_PIN            6
#endif

// C UART
#ifdef  M5_AVAILABLE
#define MOTOR_UARTM5_PORT           GPIOD
#define MOTOR_UARTM5_PIN            2
#endif

#elif TRINAMIC_SPI_ENABLE

// SPI PORT
#define TRINAMIC_MOSI_PORT          GPIOC
#define TRINAMIC_MOSI_PIN           12
#define TRINAMIC_SCK_PORT           GPIOC
#define TRINAMIC_SCK_PIN            10
#define TRINAMIC_MISO_PORT          GPIOC
#define TRINAMIC_MISO_PIN           11

// CS X
#define MOTOR_CSX_PORT              GPIOC
#define MOTOR_CSX_PIN               0

// CS Y
#define MOTOR_CSY_PORT              GPIOE
#define MOTOR_CSY_PIN               5

// CS Z
#define MOTOR_CSZ_PORT              GPIOE
#define MOTOR_CSZ_PIN               1

// CS A
#ifdef  M3_AVAILABLE
#define MOTOR_CSM3_PORT             GPIOB
#define MOTOR_CSM3_PIN              6
#endif

// CS B
#ifdef  M4_AVAILABLE
#define MOTOR_CSM4_PORT             GPIOD
#define MOTOR_CSM4_PIN              6
#endif

// CS C
#ifdef  M5_AVAILABLE
#define MOTOR_CSM5_PORT             GPIOD
#define MOTOR_CSM5_PIN              2
#endif

#endif

