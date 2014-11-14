#ifndef __DAP_CONFIG_H__
#define __DAP_CONFIG_H__

//**************************************************************************************************
/**
\defgroup DAP_Config_Debug_gr CMSIS-DAP Debug Unit Information
\ingroup DAP_ConfigIO_gr
@{
Provides definitions about:
 - Definition of Cortex-M processor parameters used in CMSIS-DAP Debug Unit.
 - Debug Unit communication packet size.
 - Debug Access Port communication mode (JTAG or SWD).
 - Optional information about a connected Target Device (for Evaluation Boards).
*/

#include "max32550.h"	// Debug Unit Cortex-M Processor Header File
#include "gpio_regs.h"

/// Processor Clock of the Cortex-M MCU used in the Debug Unit.
/// This value is used to calculate the SWD/JTAG clock speed.
#define CPU_CLOCK               SystemCoreClock        ///< Specifies the CPU Clock in Hz

/// Number of processor cycles for I/O Port write operations.
/// This value is used to calculate the SWD/JTAG clock speed that is generated with I/O
/// Port write operations in the Debug Unit by a Cortex-M MCU. Most Cortex-M processors
/// requrie 2 processor cycles for a I/O Port Write operation.  If the Debug Unit uses
/// a Cortex-M0+ processor with high-speed peripheral I/O only 1 processor cycle might be
/// required.
#define IO_PORT_WRITE_CYCLES    2               ///< I/O Cycles

/// Indicate that Serial Wire Debug (SWD) communication mode is available at the Debug Access Port.
/// This information is returned by the command \ref DAP_Info as part of <b>Capabilities</b>.
#define DAP_SWD                 0               ///< SWD Mode:  1 = available, 0 = not available

/// Indicate that JTAG communication mode is available at the Debug Port.
/// This information is returned by the command \ref DAP_Info as part of <b>Capabilities</b>.
#define DAP_JTAG                1               ///< JTAG Mode: 1 = available

/// Configure maximum number of JTAG devices on the scan chain connected to the Debug Access Port.
/// This setting impacts the RAM requirements of the Debug Unit. Valid range is 1 .. 255.
#define DAP_JTAG_DEV_CNT        8               ///< Maximum number of JTAG devices on scan chain

/// Default communication mode on the Debug Access Port.
/// Used for the command \ref DAP_Connect when Port Default mode is selected.
#define DAP_DEFAULT_PORT        2               ///< Default JTAG/SWJ Port Mode: 1 = SWD, 2 = JTAG.

/// Default communication speed on the Debug Access Port for SWD and JTAG mode.
/// Used to initialize the default SWD/JTAG clock frequency.
/// The command \ref DAP_SWJ_Clock can be used to overwrite this default setting.
#define DAP_DEFAULT_SWJ_CLOCK   3000000         ///< Default SWD/JTAG clock frequency in Hz.

/// Maximum Package Size for Command and Response data.
/// This configuration settings is used to optimized the communication performance with the
/// debugger and depends on the USB peripheral. Change setting to 1024 for High-Speed USB.
#define DAP_PACKET_SIZE         64              ///< USB: 64 = Full-Speed, 1024 = High-Speed.

/// Maximum Package Buffers for Command and Response data.
/// This configuration settings is used to optimized the communication performance with the
/// debugger and depends on the USB peripheral. For devices with limited RAM or USB buffer the
/// setting can be reduced (valid range is 1 .. 255). Change setting to 4 for High-Speed USB.
#define DAP_PACKET_COUNT        1              ///< Buffers: 64 = Full-Speed, 4 = High-Speed.

/// Debug Unit is connected to fixed Target Device.
/// The Debug Unit may be part of an evaluation board and always connected to a fixed
/// known device.  In this case a Device Vendor and Device Name string is stored which
/// may be used by the debugger or IDE to configure device parameters.
#define TARGET_DEVICE_FIXED     0               ///< Target Device: 1 = known, 0 = unknown;

#if TARGET_DEVICE_FIXED
#define TARGET_DEVICE_VENDOR    ""              ///< String indicating the Silicon Vendor
#define TARGET_DEVICE_NAME      ""              ///< String indicating the Target Device
#endif

///@}

//**************************************************************************************************
/**
\defgroup DAP_Config_PortIO_gr CMSIS-DAP Hardware I/O Pin Access
\ingroup DAP_ConfigIO_gr
@{

Standard I/O Pins of the CMSIS-DAP Hardware Debug Port support standard JTAG mode
and Serial Wire Debug (SWD) mode. In SWD mode only 2 pins are required to implement the debug
interface of a device. The following I/O Pins are provided:

JTAG I/O Pin                 | SWD I/O Pin          | CMSIS-DAP Hardware pin mode
---------------------------- | -------------------- | ---------------------------------------------
TCK: Test Clock              | SWCLK: Clock         | Output Push/Pull
TMS: Test Mode Select        | SWDIO: Data I/O      | Output Push/Pull; Input (for receiving data)
TDI: Test Data Input         |                      | Output Push/Pull
TDO: Test Data Output        |                      | Input
nTRST: Test Reset (optional) |                      | Output Open Drain with pull-up resistor
nRESET: Device Reset         | nRESET: Device Reset | Output Open Drain with pull-up resistor


DAP Hardware I/O Pin Access Functions
-------------------------------------
The various I/O Pins are accessed by functions that implement the Read, Write, Set, or Clear to
these I/O Pins.

For the SWDIO I/O Pin there are additional functions that are called in SWD I/O mode only.
This functions are provided to achieve faster I/O that is possible with some advanced GPIO
peripherals that can independently write/read a single I/O pin without affecting any other pins
of the same I/O port. The following SWDIO I/O Pin functions are provided:
 - \ref PIN_SWDIO_OUT_ENABLE to enable the output mode from the DAP hardware.
 - \ref PIN_SWDIO_OUT_DISABLE to enable the input mode to the DAP hardware.
 - \ref PIN_SWDIO_IN to read from the SWDIO I/O pin with utmost possible speed.
 - \ref PIN_SWDIO_OUT to write to the SWDIO I/O pin with utmost possible speed.
*/

#ifdef TARGET_MAX32550_EVKIT
#define TCK_PORT    MXC_GPIO0
#define TCK_PIN     (2)
#define TCK_MASK    (1 << TCK_PIN)
#define TMS_PORT    MXC_GPIO0
#define TMS_PIN     (3)
#define TMS_MASK    (1 << TMS_PIN)
#define TDI_PORT    MXC_GPIO0
#define TDI_PIN     (16)
#define TDI_MASK    (1 << TDI_PIN)
#define TDO_PORT    MXC_GPIO0
#define TDO_PIN     (17)
#define TDO_MASK    (1 << TDO_PIN)
#define TRST_PORT   MXC_GPIO0
#define TRST_PIN    (0)
#define TRST_MASK   (1 << TRST_PIN)
#define SRST_PORT   MXC_GPIO0
#define SRST_PIN    (1)
#define SRST_MASK   (1 << SRST_PIN)
#define TSEL_PORT   MXC_GPIO0
#define TSEL_PIN    (4)
#define TSEL_MASK   (1 << TSEL_PIN)
#else
#define TCK_PORT    MXC_GPIO0
#define TCK_PIN     (17)
#define TCK_MASK    (1 << TCK_PIN)
#define TMS_PORT    MXC_GPIO0
#define TMS_PIN     (16)
#define TMS_MASK    (1 << TMS_PIN)
#define TDI_PORT    MXC_GPIO0
#define TDI_PIN     (23)
#define TDI_MASK    (1 << TDI_PIN)
#define TDO_PORT    MXC_GPIO0
#define TDO_PIN     (19)
#define TDO_MASK    (1 << TDO_PIN)
#define TRST_PORT   MXC_GPIO0
#define TRST_PIN    (18)
#define TRST_MASK   (1 << TRST_PIN)
#define SRST_PORT   MXC_GPIO0
#define SRST_PIN    (24)
#define SRST_MASK   (1 << SRST_PIN)
#define TSEL_PORT   MXC_GPIO0
#define TSEL_PIN    (20)
#define TSEL_MASK   (1 << TSEL_PIN)
#endif

#define SWCLK_PORT  TCK_PORT
#define SWCLK_PIN   TCK_PIN
#define SWCLK_MASK  TCK_MASK
#define SWDIO_PORT  TMS_PORT
#define SWDIO_PIN   TMS_PIN
#define SWDIO_MASK  TMS_MASK

// Configure DAP I/O pins ------------------------------

/** Setup JTAG I/O pins: TCK, TMS, TDI, TDO, nTRST, and nRESET.
Configures the DAP Hardware I/O pins for JTAG mode:
 - TCK, TMS, TDI, nTRST, nRESET to output mode and set to high level.
 - TDO to input mode.
*/
static __inline void PORT_JTAG_SETUP (void) {

  // TCK: Test Clock              | Output Push/Pull
  TCK_PORT->out_clr     = TCK_MASK;
  TCK_PORT->en_set      = TCK_MASK;
  TCK_PORT->en1_clr     = TCK_MASK;
  TCK_PORT->out_en_set  = TCK_MASK;

  // TMS: Test Mode Select        | Output Push/Pull
  TMS_PORT->out_clr     = TMS_MASK;
  TMS_PORT->en_set      = TMS_MASK;
  TMS_PORT->en1_clr     = TMS_MASK;
  TMS_PORT->out_en_set  = TMS_MASK;

  // TDI: Test Data Input         | Output Push/Pull
  TDI_PORT->out_clr     = TDI_MASK;
  TDI_PORT->en_set      = TDI_MASK;
  TDI_PORT->en1_clr     = TDI_MASK;
  TDI_PORT->out_en_set  = TDI_MASK;

  // TDO: Test Data Output        | Input
  TDO_PORT->out_en_clr  = TDO_MASK;
  TDO_PORT->en_set      = TDO_MASK;
  TDO_PORT->en1_clr     = TDO_MASK;

  // nTRST: Test Reset (optional) | Output Open Drain with pull-up resistor
  TRST_PORT->out_clr     = TRST_MASK;
  TRST_PORT->en_set      = TRST_MASK;
  TRST_PORT->en1_clr     = TRST_MASK;
  TRST_PORT->out_en_clr  = TRST_MASK;  // disable output with pull-up --> high level

  // nRESET: Device Reset         | Output Open Drain with pull-up resistor
  SRST_PORT->out_clr     = SRST_MASK;
  SRST_PORT->en_set      = SRST_MASK;
  SRST_PORT->en1_clr     = SRST_MASK;
  SRST_PORT->out_en_clr  = SRST_MASK;  // disable output with pull-up --> high level

  // TSEL: TAP select             | Output Open Drain with pull-up resistor
  TSEL_PORT->out_clr     = TSEL_MASK;
  TSEL_PORT->en_set      = TSEL_MASK;
  TSEL_PORT->en1_clr     = TSEL_MASK;
  TSEL_PORT->out_en_clr  = TSEL_MASK;  // disable output with pull-up --> high level
}
 
/** Setup SWD I/O pins: SWCLK, SWDIO, and nRESET.
Configures the DAP Hardware I/O pins for Serial Wire Debug (SWD) mode:
 - SWCLK, SWDIO, nRESET to output mode and set to default high level.
 - TDI, TMS, nTRST to HighZ mode (pins are unused in SWD mode).
*/
static __inline void PORT_SWD_SETUP (void) {

  // SWCLK: Clock         | Output Push/Pull
  SWCLK_PORT->out_set     = SWCLK_MASK;
  SWCLK_PORT->en_set      = SWCLK_MASK;
  SWCLK_PORT->en1_clr     = SWCLK_MASK;
  SWCLK_PORT->out_en_set  = SWCLK_MASK;

  // SWDIO: Data I/O      | Output Push/Pull; Input (for receiving data)
  SWDIO_PORT->out_set     = SWDIO_MASK;
  SWDIO_PORT->en_set      = SWDIO_MASK;
  SWDIO_PORT->en1_clr     = SWDIO_MASK;
  SWDIO_PORT->out_en_set  = SWDIO_MASK;

  // nRESET: Device Reset         | Output Open Drain with pull-up resistor
  SRST_PORT->out_clr     = SRST_MASK;
  SRST_PORT->en_set      = SRST_MASK;
  SRST_PORT->en1_clr     = SRST_MASK;
  SRST_PORT->out_en_clr  = SRST_MASK;  // disable output with pull-up --> high level
}

/** Disable JTAG/SWD I/O Pins.
Disables the DAP Hardware I/O pins which configures:
 - TCK/SWCLK, TMS/SWDIO, TDI, TDO, nTRST, nRESET to High-Z mode.
*/
static __inline void PORT_OFF (void) {

  TCK_PORT->out_en_clr = TCK_MASK;
  TMS_PORT->out_en_clr = TMS_MASK;
  TDI_PORT->out_en_clr = TDI_MASK;
  TDO_PORT->out_en_clr = TDO_MASK;
  TRST_PORT->out_en_clr = TRST_MASK;
  SRST_PORT->out_en_clr = SRST_MASK;
  TSEL_PORT->out_en_clr = TSEL_MASK;
}


// SWCLK/TCK I/O pin -------------------------------------

/** SWCLK/TCK I/O pin: Get Input.
\return Current status of the SWCLK/TCK DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_SWCLK_TCK_IN  (void) {
    return BITBAND_GetBit(&TCK_PORT->in, TCK_PIN);
}

/** SWCLK/TCK I/O pin: Set Output to High.
Set the SWCLK/TCK DAP hardware I/O pin to high level.
*/
static __forceinline void     PIN_SWCLK_TCK_SET (void) {
  TCK_PORT->out_set = TCK_MASK;
}

/** SWCLK/TCK I/O pin: Set Output to Low.
Set the SWCLK/TCK DAP hardware I/O pin to low level.
*/
static __forceinline void     PIN_SWCLK_TCK_CLR (void) {
  TCK_PORT->out_clr = TCK_MASK;
}


// SWDIO/TMS Pin I/O --------------------------------------

/** SWDIO/TMS I/O pin: Get Input.
\return Current status of the SWDIO/TMS DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_SWDIO_TMS_IN  (void) {
    return BITBAND_GetBit(&TMS_PORT->in, TMS_PIN);
}

/** SWDIO/TMS I/O pin: Set Output to High.
Set the SWDIO/TMS DAP hardware I/O pin to high level.
*/
static __forceinline void     PIN_SWDIO_TMS_SET (void) {
  TMS_PORT->out_set = TMS_MASK;
}

/** SWDIO/TMS I/O pin: Set Output to Low.
Set the SWDIO/TMS DAP hardware I/O pin to low level.
*/
static __forceinline void     PIN_SWDIO_TMS_CLR (void) {
  TMS_PORT->out_clr = TMS_MASK;
}

/** SWDIO I/O pin: Get Input (used in SWD mode only).
\return Current status of the SWDIO DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_SWDIO_IN      (void) {
   return BITBAND_GetBit(&SWDIO_PORT->in, SWDIO_PIN);
}

/** SWDIO I/O pin: Set Output (used in SWD mode only).
\param bit Output value for the SWDIO DAP hardware I/O pin.
*/
static __forceinline void     PIN_SWDIO_OUT     (uint32_t bit){
  SWDIO_PORT->out_set = SWDIO_MASK;
}

/** SWDIO I/O pin: Switch to Output mode (used in SWD mode only).
Configure the SWDIO DAP hardware I/O pin to output mode. This function is
called prior \ref PIN_SWDIO_OUT function calls.
*/
static __forceinline void     PIN_SWDIO_OUT_ENABLE  (void) {
  SWDIO_PORT->out_en_set = SWDIO_MASK;
}

/** SWDIO I/O pin: Switch to Input mode (used in SWD mode only).
Configure the SWDIO DAP hardware I/O pin to input mode. This function is
called prior \ref PIN_SWDIO_IN function calls.
*/
static __forceinline void     PIN_SWDIO_OUT_DISABLE (void) {
  SWDIO_PORT->out_en_clr = SWDIO_MASK;
}


// TDI Pin I/O ---------------------------------------------

/** TDI I/O pin: Get Input.
\return Current status of the TDI DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_TDI_IN  (void) {
    return BITBAND_GetBit(&TDI_PORT->in, TDI_PIN);
}

/** TDI I/O pin: Set Output.
\param bit Output value for the TDI DAP hardware I/O pin.
*/
static __forceinline void     PIN_TDI_OUT (uint32_t bit) {
  if (bit & 1) {
    TDI_PORT->out_set = TDI_MASK;
  } else {
    TDI_PORT->out_clr = TDI_MASK;
  }
}


// TDO Pin I/O ---------------------------------------------

/** TDO I/O pin: Get Input.
\return Current status of the TDO DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_TDO_IN  (void) {
    return BITBAND_GetBit(&TDO_PORT->in, TDO_PIN);
}


// nTRST Pin I/O -------------------------------------------

/** nTRST I/O pin: Get Input.
\return Current status of the nTRST DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_nTRST_IN   (void) {
    return BITBAND_GetBit(&TRST_PORT->in, TRST_PIN);
}

/** nTRST I/O pin: Set Output.
\param bit JTAG TRST Test Reset pin status:
           - 0: issue a JTAG TRST Test Reset.
           - 1: release JTAG TRST Test Reset.
*/
static __forceinline void     PIN_nTRST_OUT  (uint32_t bit) {
  if (bit) {
    TRST_PORT->out_en_clr = TRST_MASK;  // disable output with pull-up --> high level
  } else {
    TRST_PORT->out_clr = TRST_MASK;
    TRST_PORT->out_en_set = TRST_MASK;
  }
}

// nRESET Pin I/O------------------------------------------

/** nRESET I/O pin: Get Input.
\return Current status of the nRESET DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_nRESET_IN  (void) {
    return BITBAND_GetBit(&SRST_PORT->in, SRST_PIN);
}

/** nRESET I/O pin: Set Output.
\param bit target device hardware reset pin status:
           - 0: issue a device hardware reset.
           - 1: release device hardware reset.
*/
static __forceinline void     PIN_nRESET_OUT (uint32_t bit) {
  if (bit) {
    SRST_PORT->out_en_clr = SRST_MASK;  // disable output with pull-up --> high level
  } else {
    SRST_PORT->out_clr = SRST_MASK;
    SRST_PORT->out_en_set = SRST_MASK;
  }
}

// TSEL Pin I/O------------------------------------------

/** TSEL I/O pin: Get Input.
\return Current status of the TSEL DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_TSEL_IN  (void) {
    return BITBAND_GetBit(&TSEL_PORT->in, TSEL_PIN);
}

/** TSEL I/O pin: Set Output.
\param bit target device hardware reset pin status:
           - 0: issue a device hardware reset.
           - 1: release device hardware reset.
*/
static __forceinline void     PIN_TSEL_OUT (uint32_t bit) {
  if (bit) {
    TSEL_PORT->out_en_clr = TSEL_MASK;  // disable output with pull-up --> high level
  } else {
    TSEL_PORT->out_clr = TSEL_MASK;
    TSEL_PORT->out_en_set = TSEL_MASK;
  }
}

///@}


//**************************************************************************************************
/**
\defgroup DAP_Config_LEDs_gr CMSIS-DAP Hardware Status LEDs
\ingroup DAP_ConfigIO_gr
@{

CMSIS-DAP Hardware may provide LEDs that indicate the status of the CMSIS-DAP Debug Unit.

It is recommended to provide the following LEDs for status indication:
 - Connect LED: is active when the DAP hardware is connected to a debugger.
 - Running LED: is active when the debugger has put the target device into running state.
*/

/** Debug Unit: Set status of Connected LED.
\param bit status of the Connect LED.
           - 1: Connect LED ON: debugger is connected to CMSIS-DAP Debug Unit.
           - 0: Connect LED OFF: debugger is not connected to CMSIS-DAP Debug Unit.
*/
static __inline void LED_CONNECTED_OUT (uint32_t bit) {
}

/** Debug Unit: Set status Target Running LED.
\param bit status of the Target Running LED.
           - 1: Target Running LED ON: program execution in target started.
           - 0: Target Running LED OFF: program execution in target stopped.
*/
static __inline void LED_RUNNING_OUT (uint32_t bit) {
  ;             // Not available
}

///@}


//**************************************************************************************************
/**
\defgroup DAP_Config_Initialization_gr CMSIS-DAP Initialization
\ingroup DAP_ConfigIO_gr
@{

CMSIS-DAP Hardware I/O and LED Pins are initialized with the function \ref DAP_SETUP.
*/

/** Setup of the Debug Unit I/O pins and LEDs (called when Debug Unit is initialized).
This function performs the initialization of the CMSIS-DAP Hardware I/O Pins and the
Status LEDs. In detail the operation of Hardware I/O and LED pins are enabled and set:
 - I/O clock system enabled.
 - all I/O pins: input buffer enabled, output pins are set to HighZ mode.
 - for nTRST, nRESET a weak pull-up (if available) is enabled.
 - LED output pins are enabled and LEDs are turned off.
*/
static __inline void DAP_SETUP (void) {
  // Enable pull-ups
  TDI_PORT->pad_cfg1   |=  TDI_MASK;
  TDI_PORT->pad_cfg2   &= ~TDI_MASK;
  TDO_PORT->pad_cfg1   |=  TDO_MASK;
  TDO_PORT->pad_cfg2   &= ~TDO_MASK;
  TRST_PORT->pad_cfg1  |=  TRST_MASK;
  TRST_PORT->pad_cfg2  &= ~TRST_MASK;
  SRST_PORT->pad_cfg1  |=  SRST_MASK;
  SRST_PORT->pad_cfg2  &= ~SRST_MASK;
}

/** Reset Target Device with custom specific I/O pin or command sequence.
This function allows the optional implementation of a device specific reset sequence.
It is called when the command \ref DAP_ResetTarget and is for example required
when a device needs a time-critical unlock sequence that enables the debug port.
\return 0 = no device specific reset sequence is implemented.\n
        1 = a device specific reset sequence is implemented.
*/
static __inline uint32_t RESET_TARGET (void) {
  return (0);              // change to '1' when a device reset sequence is implemented
}

///@}


#endif /* __DAP_CONFIG_H__ */
