/*= Rohde&Schwarz UP300/UP350 Audio Analyzer & Generator Include File =======*/

/*===========================================================================*/
/*  Please do not use global variables or arrays in the include file of      */
/*  instrument drivers that will be submitted for inclusion into the         */
/*  LabWindows Instrument Driver Library.                                    */
/*===========================================================================*/

#ifndef __RSSIUP_HEADER
#define __RSSIUP_HEADER

#include "rssitype.h"

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/*****************************************************************************/
/*= Instrument Driver Specific Error/Warning Codes ==========================*/
/*****************************************************************************/

#define VI_ERROR_INSTR_FILE_OPEN                (_VI_ERROR+0x3FFC0800L)
#define VI_ERROR_INSTR_FILE_WRITE               (_VI_ERROR+0x3FFC0801L)
#define VI_ERROR_INSTR_INTERPRETING_RESPONSE    (_VI_ERROR+0x3FFC0803L)
#define VI_ERROR_INSTR_PARAMETER9               (_VI_ERROR+0x3FFC0809L)
#define VI_ERROR_INSTR_PARAMETER10              (_VI_ERROR+0x3FFC080AL)
#define VI_ERROR_INSTR_PARAMETER11              (_VI_ERROR+0x3FFC080BL)
#define VI_ERROR_INSTR_PARAMETER12              (_VI_ERROR+0x3FFC080CL)
#define VI_ERROR_INSTR_PARAMETER13              (_VI_ERROR+0x3FFC080DL)
#define VI_ERROR_INSTR_PARAMETER14              (_VI_ERROR+0x3FFC080EL)
#define VI_ERROR_INSTR_PARAMETER15              (_VI_ERROR+0x3FFC080FL)

/*****************************************************************************/
/*= Define Instrument Specific Error/Warning Codes Here =====================*/
/*****************************************************************************/

#define VI_WARNING_INSTR_OFFSET                 (0x3FFC0900L)
#define VI_ERROR_INSTR_OFFSET                   (_VI_ERROR+0x3FFC0900L)

#define RSSIUP_ERROR_INSTRUMENT_ERROR           (VI_ERROR_INSTR_OFFSET + 0xF0L)
#define RSSIUP_ERROR_INVALID_CONFIGURATION      (VI_ERROR_INSTR_OFFSET + 0xF1L)
#define RSSIUP_ERROR_INSTRUMENT_OPTION          (VI_ERROR_INSTR_OFFSET + 0xF2L)
#define RSSIUP_ERROR_DATA_NOT_AVAILABLE         (VI_ERROR_INSTR_OFFSET + 0xF3L)
#define RSSIUP_ERROR_SETTINGS_CONFLICT          (VI_ERROR_INSTR_OFFSET + 0xF4L)
#define RSSIUP_ERROR_INSTRUMENT_NSUP_FUNC       (VI_ERROR_INSTR_OFFSET + 0xF5L)
#define RSSIUP_ERROR_INSTRUMENT_NSUP_MODEL      (VI_ERROR_INSTR_OFFSET + 0xF6L)
#define RSSIUP_ERROR_NULL_POINTER_VALUE         (VI_ERROR_INSTR_OFFSET + 0xF8L)

#define RSSIUP_ERROR_MEASUREMENT_ABORTED        (VI_ERROR_INSTR_OFFSET + 0xF9L)
#define RSSIUP_ERROR_INVALID_VALUE              (VI_ERROR_INSTR_OFFSET + 0xFAL)
#define RSSIUP_ERROR_RNG_TAB_NOT_AVAIL          (VI_ERROR_INSTR_OFFSET + 0xFBL)
#define RSSIUP_ERROR_QUEUE_OVERFLOW             (VI_ERROR_INSTR_OFFSET + 0xFCL)
#define RSSIUP_ERROR_DATA_CORRUPTED             (VI_ERROR_INSTR_OFFSET + 0xFDL)
#define RSSIUP_ERROR_RESERVED                   (VI_ERROR_INSTR_OFFSET + 0xFEL)
#define RSSIUP_ERROR_OVER_LIMIT                 (VI_ERROR_INSTR_OFFSET + 0xFFL)

#define RSSIUP_WARNING_INSTRUMENT_WARNING       (VI_WARNING_INSTR_OFFSET + 0xF0L)
#define RSSIUP_WARNING_CACHED_DATA              (VI_WARNING_INSTR_OFFSET + 0xF1L)

/*****************************************************************************/
/*= INSTRUMENT CONSTANTS ====================================================*/
/*****************************************************************************/

/*- Channels ----------------------------------------------------------------*/

#define RSSIUP_CHAB                             0
#define RSSIUP_CHA                              1
#define RSSIUP_CHB                              2

/*- Units -------------------------------------------------------------------*/

#define RSSIUP_UNIT_PCT                         0
#define RSSIUP_UNIT_PCTFRM                      1
#define RSSIUP_UNIT_PCTFS                       2
#define RSSIUP_UNIT_PCTON                       3
#define RSSIUP_UNIT_PCTPPR                      4
#define RSSIUP_UNIT_PCTUI                       5
#define RSSIUP_UNIT_PCTVVR                      6
#define RSSIUP_UNIT_BITS                        7
#define RSSIUP_UNIT_CYC                         8
#define RSSIUP_UNIT_DPCT                        9
#define RSSIUP_UNIT_DPCTHZ                      10
#define RSSIUP_UNIT_DPCTV                       11
#define RSSIUP_UNIT_DPCTW                       12
#define RSSIUP_UNIT_DB                          13
#define RSSIUP_UNIT_DBFS                        14
#define RSSIUP_UNIT_DBM                         15
#define RSSIUP_UNIT_DBON                        16
#define RSSIUP_UNIT_DBR                         17
#define RSSIUP_UNIT_DBU                         18
#define RSSIUP_UNIT_DBUI                        19
#define RSSIUP_UNIT_DBV                         20
#define RSSIUP_UNIT_DDEG                        21
#define RSSIUP_UNIT_DEC                         22
#define RSSIUP_UNIT_DEG                         23
#define RSSIUP_UNIT_DEGFRM                      24
#define RSSIUP_UNIT_DHZ                         25
#define RSSIUP_UNIT_DRAD                        26
#define RSSIUP_UNIT_DS                          27
#define RSSIUP_UNIT_DV                          28
#define RSSIUP_UNIT_DW                          29
#define RSSIUP_UNIT_FFR                         30
#define RSSIUP_UNIT_FS                          31
#define RSSIUP_UNIT_HEX                         32
#define RSSIUP_UNIT_HZ                          33
#define RSSIUP_UNIT_LSBS                        34
#define RSSIUP_UNIT_MLT                         35
#define RSSIUP_UNIT_NS                          36
#define RSSIUP_UNIT_OCT                         37
#define RSSIUP_UNIT_OHM                         38
#define RSSIUP_UNIT_PPR                         39
#define RSSIUP_UNIT_PPMUI                       40
#define RSSIUP_UNIT_RAD                         41
#define RSSIUP_UNIT_S                           42
#define RSSIUP_UNIT_TOCT                        43
#define RSSIUP_UNIT_UI                          44
#define RSSIUP_UNIT_UIR                         45
#define RSSIUP_UNIT_UIS                         46
#define RSSIUP_UNIT_V                           47
#define RSSIUP_UNIT_VVON                        48
#define RSSIUP_UNIT_VVR                         49
#define RSSIUP_UNIT_VPP                         50
#define RSSIUP_UNIT_W                           51
#define RSSIUP_UNIT_DBUV                        52

/*- Generator Device --------------------------------------------------------*/

#define RSSIUP_GEN_A49                          0
#define RSSIUP_GEN_A98                          1
#define RSSIUP_GEN_A195                         2
#define RSSIUP_GEN_D32                          3
#define RSSIUP_GEN_D44                          4
#define RSSIUP_GEN_D48                          5
#define RSSIUP_GEN_D96                          6
#define RSSIUP_GEN_D192                         7

/*- Analyzer Device ----------------------------------------------------------*/

#define RSSIUP_ANL_A49                          0
#define RSSIUP_ANL_A98                          1
#define RSSIUP_ANL_A195                         2
#define RSSIUP_ANL_D32                          3
#define RSSIUP_ANL_D44                          4
#define RSSIUP_ANL_D48                          5
#define RSSIUP_ANL_D96                          6
#define RSSIUP_ANL_D192                         7

/*- Range Dependency --------------------------------------------------------*/

#define RSSIUP_RANGE_INDEPENDENT                0
#define RSSIUP_RANGE_DEPENDENT                  1

/*- Range Mode --------------------------------------------------------------*/

#define RSSIUP_RANGE_MODE_AUTO                  0
#define RSSIUP_RANGE_MODE_FIXED                 1
#define RSSIUP_RANGE_MODE_MINIMAL               2

/*- Generator Function ID ---------------------------------------------------*/

#define RSSIUP_GEN_FUNC_ALL                    -1
#define RSSIUP_GEN_FUNC_SINE                    0
#define RSSIUP_GEN_FUNC_ARB                     1
#define RSSIUP_GEN_FUNC_NOISE                   2
#define RSSIUP_GEN_FUNC_MULTISINE               3
#define RSSIUP_GEN_FUNC_BURST                   4
#define RSSIUP_GEN_FUNC_POLARITY                5

/*- Analyzer Function ID ----------------------------------------------------*/

#define RSSIUP_ANL_FUNC_ALL                    -1
#define RSSIUP_ANL_FUNC_PEAK                    0
#define RSSIUP_ANL_FUNC_RMSDC                   1
#define RSSIUP_ANL_FUNC_QPEAK                   2
#define RSSIUP_ANL_FUNC_RMS_SEL                 3
#define RSSIUP_ANL_FUNC_THDN                    4
#define RSSIUP_ANL_FUNC_PHASE                   5
#define RSSIUP_ANL_FUNC_DFD                     6
#define RSSIUP_ANL_FUNC_MOD_DIST                7
#define RSSIUP_ANL_FUNC_FFT                     8
#define RSSIUP_ANL_FUNC_DAI_SAMPLE_RATE         9
#define RSSIUP_ANL_FUNC_DAI_PROTOCOL            10
#define RSSIUP_ANL_FUNC_POLARITY				11
#define RSSIUP_ANL_FUNC_SIN_RMS_SWEEP			12
#define RSSIUP_ANL_FUNC_SIN_THD_SWEEP			13
#define RSSIUP_ANL_FUNC_SIN_RSM_SWEEP			14
#define RSSIUP_ANL_FUNC_RMS_SEL_MuTsk           15	

/*- Audio Monitor Source ----------------------------------------------------*/

#define RSSIUP_MONITOR_SOURCE_NONE              0
#define RSSIUP_MONITOR_SOURCE_ANALYZER_1        1
#define RSSIUP_MONITOR_SOURCE_ANALYZER_2        2
#define RSSIUP_MONITOR_SOURCE_GENERATOR         3

/*- PDF ---------------------------------------------------------------------*/

#define RSSIUP_PDF_GAUSSIAN                     0
#define RSSIUP_PDF_RECTANGULAR                  1
#define RSSIUP_PDF_TRIANGULAR                   2

/*- Burst Signal Type -------------------------------------------------------*/

#define RSSIUP_BURST_SIGNAL_SINGLE              0
#define RSSIUP_BURST_SIGNAL_QUADRANT            1

/*- Analyzer Input ----------------------------------------------------------*/

#define RSSIUP_ANL_INPUT_OFF                    0
#define RSSIUP_ANL_INPUT_ON                     1
#define RSSIUP_ANL_INPUT_LOOPBACK               2

/*- Analyzer Input Coupling -------------------------------------------------*/

#define RSSIUP_ANL_COUPLING_AC                  0
#define RSSIUP_ANL_COUPLING_DC                  1

/*- Averaging Mode ----------------------------------------------------------*/

#define RSSIUP_AVERAGING_MODE_OFF               0
#define RSSIUP_AVERAGING_MODE_NORMAL            1
#define RSSIUP_AVERAGING_MODE_EXPONENCIAL       2
#define RSSIUP_AVERAGING_MODE_FLAT              3

/*- Measurement Mode --------------------------------------------------------*/

#define RSSIUP_MEAS_MODE_SINGLE                 0
#define RSSIUP_MEAS_MODE_CONTINUOUS             1
#define RSSIUP_MEAS_MODE_IDLE                   2

/*- Synchronization Mode ----------------------------------------------------*/

#define RSSIUP_SYNC_MODE_SYNC                   0
#define RSSIUP_SYNC_MODE_ASYNC                  1

/*- Synchronization Source --------------------------------------------------*/

#define RSSIUP_SYNC_SOURCE_SIN_GEN_A_RISE       0
#define RSSIUP_SYNC_SOURCE_SIN_GEN_A_FALL       1
#define RSSIUP_SYNC_SOURCE_SIN_GEN_B_RISE       2
#define RSSIUP_SYNC_SOURCE_SIN_GEN_B_FALL       3
#define RSSIUP_SYNC_SOURCE_SIGNAL_A_RISE        4
#define RSSIUP_SYNC_SOURCE_SIGNAL_A_FALL        5
#define RSSIUP_SYNC_SOURCE_SIGNAL_B_RISE        6
#define RSSIUP_SYNC_SOURCE_SIGNAL_B_FALL        7
#define RSSIUP_SYNC_SOURCE_ARB_GEN_A            8
#define RSSIUP_SYNC_SOURCE_ARB_GEN_B            9
#define RSSIUP_SYNC_SOURCE_BURST_SINE_GEN       10
#define RSSIUP_SYNC_SOURCE_MULTISINE_GEN        11
#define RSSIUP_SYNC_SOURCE_NO_SYNC              12
#define RSSIUP_SYNC_SOURCE_EXT_SYNC             13

/*- Synchronization Level Mode ----------------------------------------------*/

#define RSSIUP_SYNC_LEVEL_MODE_AUTO             0
#define RSSIUP_SYNC_LEVEL_MODE_FIXED            1

/*- Reference Oscillator Source ---------------------------------------------*/

#define RSSIUP_REF_OSCILLATOR_SOURCE_INT        0
#define RSSIUP_REF_OSCILLATOR_SOURCE_EXT        1

/*- Ext Reference Frequency -------------------------------------------------*/

#define RSSIUP_REF_OSCILLATOR_FREQ_2MHZ         0
#define RSSIUP_REF_OSCILLATOR_FREQ_5MHZ         1
#define RSSIUP_REF_OSCILLATOR_FREQ_10MHZ        2

/*- Frequency Mode ----------------------------------------------------------*/

#define RSSIUP_FREQ_MODE_AUTO                   0
#define RSSIUP_FREQ_MODE_FIXED                  1

/*- Frequency Mode RMS Selective --------------------------------------------*/

#define RSSIUP_FREQ_MODE_RMS_FIXED_VALUE        0
#define RSSIUP_FREQ_MODE_RMS_SIGNAL_CHA         1
#define RSSIUP_FREQ_MODE_RMS_SIGNAL_CHB         2
#define RSSIUP_FREQ_MODE_RMS_GEN_TRACK_CHA      3
#define RSSIUP_FREQ_MODE_RMS_GEN_TRACK_CHB      4

/*- Measurement Bandwidth ---------------------------------------------------*/

#define RSSIUP_RMS_BANDWIDTH_3HZ                0
#define RSSIUP_RMS_BANDWIDTH_10HZ               1
#define RSSIUP_RMS_BANDWIDTH_30HZ               2
#define RSSIUP_RMS_BANDWIDTH_100HZ              3
#define RSSIUP_RMS_BANDWIDTH_300HZ              4

/*- Filter Bandwidth -------------------------------------------------------*/

#define RSSIUP_FILTER_BWIDTH_NARROW             0
#define RSSIUP_FILTER_BWIDTH_WIDE               1

/*- Measurement Time Mode ---------------------------------------------------*/

#define RSSIUP_MEAS_TIME_FAST                   0
#define RSSIUP_MEAS_TIME_NORMAL                 1

/*- FFT Window Type ---------------------------------------------------------*/

#define RSSIUP_FFT_WINDOW_RECTANGULAR           0
#define RSSIUP_FFT_WINDOW_HAMMING               1
#define RSSIUP_FFT_WINDOW_HANNING               2
#define RSSIUP_FFT_WINDOW_BLACKMANN_HARRIS      3
#define RSSIUP_FFT_WINDOW_RIFE_VINCENT_1        4
#define RSSIUP_FFT_WINDOW_RIFE_VINCENT_2        5
#define RSSIUP_FFT_WINDOW_RIFE_VINCENT_3        6
#define RSSIUP_FFT_WINDOW_FLAT_TOP              7
#define RSSIUP_FFT_WINDOW_KAISER                8
#define RSSIUP_FFT_WINDOW_KAISER_17             9

/*- FFT Window Size ---------------------------------------------------------*/

#define RSSIUP_FFT_SIZE_1024                    0
#define RSSIUP_FFT_SIZE_2048                    1
#define RSSIUP_FFT_SIZE_4096                    2
#define RSSIUP_FFT_SIZE_8192                    3
#define RSSIUP_FFT_SIZE_16384                   4

/*- Master Mode -------------------------------------------------------------*/

#define RSSIUP_FREQ_MASTER_AUTO                 0
#define RSSIUP_FREQ_MASTER_CHA                  1
#define RSSIUP_FREQ_MASTER_CHB                  2

/*- FFT Zoom Factor ---------------------------------------------------------*/

#define RSSIUP_FFT_ZOOM_FACTOR_0                0
#define RSSIUP_FFT_ZOOM_FACTOR_2                1
#define RSSIUP_FFT_ZOOM_FACTOR_4                2
#define RSSIUP_FFT_ZOOM_FACTOR_8                3
#define RSSIUP_FFT_ZOOM_FACTOR_16               4
#define RSSIUP_FFT_ZOOM_FACTOR_32               5
#define RSSIUP_FFT_ZOOM_FACTOR_64               6
#define RSSIUP_FFT_ZOOM_FACTOR_128              7

/*- Filter Section ----------------------------------------------------------*/

#define RSSIUP_DIGI_FILTER_SECTION_1            0
#define RSSIUP_DIGI_FILTER_SECTION_2            1
#define RSSIUP_DIGI_FILTER_SECTION_3            2

/*- Filter Type -------------------------------------------------------------*/

#define RSSIUP_DIGI_FILTER_TYPE_NONE            0
#define RSSIUP_DIGI_FILTER_TYPE_A_WEIGHT        1
#define RSSIUP_DIGI_FILTER_TYPE_C_MESSAGE       2
#define RSSIUP_DIGI_FILTER_TYPE_CCITT           3
#define RSSIUP_DIGI_FILTER_TYPE_CCIR_WEIGHT     4
#define RSSIUP_DIGI_FILTER_TYPE_CCIR_UNWEGHT    5
#define RSSIUP_DIGI_FILTER_TYPE_CCIR_ARM        6
#define RSSIUP_DIGI_FILTER_TYPE_DEEMPH_50P15    7
#define RSSIUP_DIGI_FILTER_TYPE_DEEMPH_50       8
#define RSSIUP_DIGI_FILTER_TYPE_DEEMPH_75       9
#define RSSIUP_DIGI_FILTER_TYPE_DEEMPH_J17      10
#define RSSIUP_DIGI_FILTER_TYPE_R_WEIGHTING     11
#define RSSIUP_DIGI_FILTER_TYPE_R_UNWEIGHT      12
#define RSSIUP_DIGI_FILTER_TYPE_DC_NOISE_HPF    13
#define RSSIUP_DIGI_FILTER_TYPE_IEC_IEE         14
#define RSSIUP_DIGI_FILTER_TYPE_JITTER_WEIGHT   15
#define RSSIUP_DIGI_FILTER_TYPE_1P3_OCTAVE      16
#define RSSIUP_DIGI_FILTER_TYPE_1P1_OCTAVE      17
#define RSSIUP_DIGI_FILTER_TYPE_USER_1          18
#define RSSIUP_DIGI_FILTER_TYPE_USER_2          19
#define RSSIUP_DIGI_FILTER_TYPE_USER_3          20
#define RSSIUP_DIGI_FILTER_TYPE_BSELLIP         21

/*- User Filter Number ------------------------------------------------------*/

#define RSSIUP_USER_FILTER_1                    0
#define RSSIUP_USER_FILTER_2                    1
#define RSSIUP_USER_FILTER_3                    2

/*- Digital Analyzer Input --------------------------------------------------*/

#define RSSIUP_DAI_INPUT_BNC                    0
#define RSSIUP_DAI_INPUT_OPTO                   1
#define RSSIUP_DAI_INPUT_I2S                    2

/*- DAI Protocol ------------------------------------------------------------*/

#define RSSIUP_DAI_PROTOCOL_CH_STATUS           0
#define RSSIUP_DAI_PROTOCOL_USER_DATA           1

/*- DAI Bits ----------------------------------------------------------------*/

#define RSSIUP_DAI_BITS_16                      0
#define RSSIUP_DAI_BITS_17                      1
#define RSSIUP_DAI_BITS_18                      2
#define RSSIUP_DAI_BITS_19                      3
#define RSSIUP_DAI_BITS_20                      4
#define RSSIUP_DAI_BITS_21                      5
#define RSSIUP_DAI_BITS_22                      6
#define RSSIUP_DAI_BITS_23                      7
#define RSSIUP_DAI_BITS_24                      8

/*- DAI Validity Bit --------------------------------------------------------*/

#define RSSIUP_INVALID                          0
#define RSSIUP_VALID                            1
	
/*- Trigger Source ----------------------------------------------------------*/

#define RSSIUP_TRIGGER_SOURCE_IMMEDIATE         0
#define RSSIUP_TRIGGER_SOURCE_BUS               1
	
/*- Trigger Measurement Mode ------------------------------------------------*/

#define RSSIUP_TRG_MEAS_MODE_CONTINUOUS         0
#define RSSIUP_TRG_MEAS_MODE_TRIGGERED          1
	
/*- Trigger Measurement State -----------------------------------------------*/

#define RSSIUP_TRIGGER_STATE_IDLE               0
#define RSSIUP_TRIGGER_STATE_WFT                1
#define RSSIUP_TRIGGER_STATE_MEAS               2
	
/*- Frequency Sweep Spacing -------------------------------------------------*/

#define RSSIUP_SPACING_NO                       0
#define RSSIUP_SPACING_LIN                      1
#define RSSIUP_SPACING_LOG                      2
#define RSSIUP_SPACING_INS_LIN                  3
#define RSSIUP_SPACING_INS_LOG                  5
	
/*- Control Step ------------------------------------------------------------*/

#define RSSIUP_CTRL_STEP_RESTART_SWEEPS         0
#define RSSIUP_CTRL_STEP_RESTART_SWEEP			1
#define RSSIUP_CTRL_STEP_CONTINUE				2
#define RSSIUP_CTRL_STEP_STOP					3
#define RSSIUP_CTRL_STEP_NEXT_1_STEP			4
#define RSSIUP_CTRL_STEP_TO_END_OF_INS_LOOP		5
	
/*- Average Mode ------------------------------------------------------------*/

#define RSSIUP_AVER_MODE_OFF                    0
#define RSSIUP_AVER_MODE_NORM                   1
#define RSSIUP_AVER_MODE_EXP                    2
#define RSSIUP_AVER_MODE_FLAT                   3
	
/*- Synchro Mode ------------------------------------------------------------*/

#define RSSIUP_SYNC_MODE_SYNCHRO                0
#define RSSIUP_SYNC_MODE_ASYNCHRO               1
	
/*- Synchro Source ----------------------------------------------------------*/

#define RSSIUP_SYNC_SRC_SINE_GEN_A_RISING       0
#define RSSIUP_SYNC_SRC_SINE_GEN_A_FALLING      1
#define RSSIUP_SYNC_SRC_SINE_GEN_B_RISING       2
#define RSSIUP_SYNC_SRC_SINE_GEN_B_FALLING      3
#define RSSIUP_SYNC_SRC_SIGNAL_A_RISING         4
#define RSSIUP_SYNC_SRC_SIGNAL_A_FALLING        5
#define RSSIUP_SYNC_SRC_SIGNAL_B_RISING         6
#define RSSIUP_SYNC_SRC_SIGNAL_B_FALLING        7
#define RSSIUP_SYNC_SRC_SIGNAL_ARBITRARY_A      8
#define RSSIUP_SYNC_SRC_SIGNAL_ARBITRARY_B      9
#define RSSIUP_SYNC_SRC_SIGNAL_BURST_SINE       10
#define RSSIUP_SYNC_SRC_SIGNAL_MULTI_SINE       11
		
/*- Synchro Level Mode ------------------------------------------------------*/

#define RSSIUP_SYNC_LEVEL_MODE_AUTO             0
#define RSSIUP_SYNC_LEVEL_MODE_FIXED            1
	
/*- Frequency Mode ----------------------------------------------------------*/

#define RSSIUP_FREQ_MODE_AUTO                   0
#define RSSIUP_FREQ_MODE_FIXED					1
	
/*- Filter Bandwidth Type ---------------------------------------------------*/

#define RSSIUP_FILTER_BWID_TYPE_CONST           0
#define RSSIUP_FILTER_BWID_TYPE_RELAT			1
	
/*- DAI Validity Bit --------------------------------------------------------*/

#define RSSIUP_DAI_DATA_VALID                   0
#define RSSIUP_DAI_DATA_INVALID					1

/*****************************************************************************/
/*= GLOBAL USER-CALLABLE FUNCTION DECLARATIONS (Exportable Functions) =======*/
/*****************************************************************************/

ViStatus _VI_FUNC rssiup_init (ViRsrc resourceName, ViBoolean IDQuery,
                               ViBoolean resetDevice, ViSession *instrumentHandle);
ViStatus _VI_FUNC rssiup_SetAnalyzerDeviceSelector (ViSession instrumentHandle,
                                                    ViInt32 device);
ViStatus _VI_FUNC rssiup_GetAnalyzerDeviceSelector (ViSession instrumentHandle,
                                                    ViInt32 *device);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionState (ViSession instrumentHandle,
                                                   ViInt32 channel,
                                                   ViInt32 functionID,
                                                   ViBoolean functionState,
                                                   ViBoolean digitalFilterState);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionState (ViSession instrumentHandle,
                                                   ViInt32 channel,
                                                   ViInt32 functionID,
                                                   ViBoolean *functionState);
ViStatus _VI_FUNC rssiup_SetMeasurementMode (ViSession instrumentHandle,
                                             ViInt32 measurementMode);
ViStatus _VI_FUNC rssiup_GetMeasurementMode (ViSession instrumentHandle,
                                             ViInt32 *measurementMode);
ViStatus _VI_FUNC rssiup_GetTriggerState (ViSession instrumentHandle,
                                          ViInt32 channel, ViInt32 *triggerState);
ViStatus _VI_FUNC rssiup_SetTriggerSource (ViSession instrumentHandle,
                                           ViInt32 channel, ViInt32 functionID,
                                           ViInt32 triggerSource);
ViStatus _VI_FUNC rssiup_GetTriggerSource (ViSession instrumentHandle,
                                           ViInt32 *triggerSource);
ViStatus _VI_FUNC rssiup_SetSweepControl (ViSession instrumentHandle,
                                          ViInt32 functionID, ViInt32 controlStep);
ViStatus _VI_FUNC rssiup_StartMeasurement (ViSession instrumentHandle);
ViStatus _VI_FUNC rssiup_AbortMeasurement (ViSession instrumentHandle);
ViStatus _VI_FUNC rssiup_StartMeasurementWaitOPC (ViSession instrumentHandle,
                                                  ViInt32 timeout);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionPeakSettings (ViSession instrumentHandle,
                                                          ViReal64 measurementTime);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionPeakSettings (ViSession instrumentHandle,
                                                          ViReal64 *measurementTime);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionRMSDCSettings
             (ViSession instrumentHandle, ViInt32 channel, ViReal64 measurementTime,
              ViReal64 timeout, ViInt32 syncMode, ViInt32 syncSource);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionRMSDCSettings
             (ViSession instrumentHandle, ViInt32 channel,
              ViReal64 *measurementTime, ViReal64 *timeout, ViInt32 *syncMode,
              ViInt32 *syncSource);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionRMSDCAveraging
             (ViSession instrumentHandle, ViInt32 channel, ViInt32 averagingModeDC,
              ViInt32 averagingFactorDC, ViInt32 averagingModeRMS,
              ViInt32 averagingFactorRMS, ViInt32 averagingModeFrequency,
              ViInt32 averagingFactorFrequency);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionRMSDCAveraging
             (ViSession instrumentHandle, ViInt32 channel, ViInt32 *averagingModeDC,
              ViInt32 *averagingFactorDC, ViInt32 *averagingModeRMS,
              ViInt32 *averagingFactorRMS, ViInt32 *averagingModeFrequency,
              ViInt32 *averagingFactorFrequency);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionQpeakSettings
             (ViSession instrumentHandle, ViReal64 intervalTime);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionQpeakSettings
             (ViSession instrumentHandle, ViReal64 *intervalTime);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionRMSSelectiveSettings
             (ViSession instrumentHandle, ViReal64 measurementTime,
              ViReal64 centerFrequency, ViInt32 bandwidth);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionRMSSelectiveSettings
             (ViSession instrumentHandle, ViReal64 *measurementTime,
              ViReal64 *centerFrequency, ViInt32 *frequencyMode,
              ViInt32 *bandwidth);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionRMSSelectiveAveraging
             (ViSession instrumentHandle, ViInt32 averagingMode,
              ViInt32 averagingFactor);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionRMSSelectiveAveraging
             (ViSession instrumentHandle, ViInt32 *averagingMode,
              ViInt32 *averagingFactor);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionRMSSelectiveVariableBWSettings (ViSession instrumentHandle,
                                                                       ViInt32 filterBandwidthType,
                                                                       ViReal64 filterBandwidth,
                                                                       ViReal64 multipleOfCenterFrequency,
                                                                       ViInt32 tuningMode);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionRMSSelectiveVariableBWSettings (ViSession instrumentHandle,
                                                                       ViInt32 *filterBandwidthType,
                                                                       ViReal64 *filterBandwidth,
                                                                       ViReal64 *multipleOfCenterFrequency,
                                                                       ViInt32 *tuningMode);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionRMSSelVariableBWFFTSettings (ViSession instrumentHandle,
                                                                    ViBoolean postFFT,
                                                                    ViInt32 postFFTSize,
                                                                    ViInt32 postFFTWindow);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionRMSSelVariableBWFFTSettings (ViSession instrumentHandle,
                                                                    ViBoolean *postFFT,
                                                                    ViInt32 *postFFTSize,
                                                                    ViInt32 *postFFTWindow);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionRMSSelectiveVariableBWFrequencySettings (ViSession instrumentHandle,
                                                                              ViInt32 channel,
                                                                              ViReal64 frequency);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionRMSSelectiveVariableBWFrequencySettings (ViSession instrumentHandle,
                                                                              ViInt32 channel,
                                                                              ViReal64 *frequency);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionAllParamsRMSSelectiveVariableBWSettings (ViSession instrumentHandle,
                                                                                ViReal64 frequency[],
                                                                                ViInt32 filterBandwidthType,
                                                                                ViReal64 filterBandwidth,
                                                                                ViReal64 multipleOfCenterFrequency,
                                                                                ViInt32 tuningMode);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionAllParamsRMSSelectiveVariableBWSettings (ViSession instrumentHandle,
                                                                                ViReal64 frequency[],
                                                                                ViInt32 *filterBandwidthType,
                                                                                ViReal64 *filterBandwidth,
                                                                                ViReal64 *multipleOfCenterFrequency,
                                                                                ViInt32 *tuningMode);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionAllParamsRMSSelVariableBWFFTSettings (ViSession instrumentHandle,
                                                                             ViBoolean postFFT,
                                                                             ViInt32 postFFTSize,
                                                                             ViInt32 postFFTWindow);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionAllParamsRMSSelVariableBWFFTSettings (ViSession instrumentHandle,
                                                                             ViBoolean *postFFT,
                                                                             ViInt32 *postFFTSize,
                                                                             ViInt32 *postFFTWindow);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionTHDNSettings (ViSession instrumentHandle,
                                                          ViInt32 measurementTime,
                                                          ViInt32 frequencyMode,
                                                          ViReal64 fixedFrequencyChA,
                                                          ViReal64 fixedFrequencyChB,
                                                          ViReal64 frequencyLimitLo,
                                                          ViReal64 frequencyLimitHi);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionTHDNSettings (ViSession instrumentHandle,
                                                          ViInt32 *measurementTime,
                                                          ViInt32 *frequencyMode,
                                                          ViReal64 *fixedFrequencyChA,
                                                          ViReal64 *fixedFrequencyChB,
                                                          ViReal64 *frequencyLimitLo,
                                                          ViReal64 *frequencyLimitHi);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionTHDNFFTSettings
             (ViSession instrumentHandle, ViBoolean postFFT, ViInt32 postFFTSize,
              ViInt32 postFFTWindow);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionTHDNFFTSettings
             (ViSession instrumentHandle, ViBoolean *postFFT, ViInt32 *postFFTSize,
              ViInt32 *postFFTWindow);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionPhaseSettings
             (ViSession instrumentHandle, ViInt32 frequencyMode,
              ViReal64 fixedFrequency, ViInt32 frequencyMaster);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionPhaseSettings
             (ViSession instrumentHandle, ViInt32 *frequencyMode,
              ViReal64 *fixedFrequency, ViInt32 *frequencyMaster);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionDFDSettings (ViSession instrumentHandle,
                                                         ViInt32 frequencyMode,
                                                         ViReal64 fixedFrequency1ChA,
                                                         ViReal64 fixedFrequency2ChA,
                                                         ViReal64 fixedFrequency1ChB,
                                                         ViReal64 fixedFrequency2ChB);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionDFDSettings (ViSession instrumentHandle,
                                                         ViInt32 *frequencyMode,
                                                         ViReal64 *fixedFrequency1ChA,
                                                         ViReal64 *fixedFrequency2ChA,
                                                         ViReal64 *fixedFrequency1ChB,
                                                         ViReal64 *fixedFrequency2ChB);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionDFDFFTSettings
             (ViSession instrumentHandle, ViBoolean postFFT, ViInt32 postFFTSize,
              ViInt32 postFFTWindow);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionDFDFFTSettings
             (ViSession instrumentHandle, ViBoolean *postFFT, ViInt32 *postFFTSize,
              ViInt32 *postFFTWindow);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionModDistSettings
             (ViSession instrumentHandle, ViInt32 frequencyMode,
              ViReal64 fixedFrequency1ChA, ViReal64 fixedFrequency2ChA,
              ViReal64 fixedFrequency1ChB, ViReal64 fixedFrequency2ChB);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionModDistSettings
             (ViSession instrumentHandle, ViInt32 *frequencyMode,
              ViReal64 *fixedFrequency1ChA, ViReal64 *fixedFrequency2ChA,
              ViReal64 *fixedFrequency1ChB, ViReal64 *fixedFrequency2ChB);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionModDistFFTSettings
             (ViSession instrumentHandle, ViBoolean postFFT, ViInt32 postFFTSize,
              ViInt32 postFFTWindow);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionDistFFTSettings
             (ViSession instrumentHandle, ViBoolean *postFFT, ViInt32 *postFFTSize,
              ViInt32 *postFFTWindow);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionFFTSettings (ViSession instrumentHandle,
                                                         ViInt32 channel,
                                                         ViInt32 FFTSize,
                                                         ViInt32 FFTWindow,
                                                         ViReal64 kaiserWindowBeta);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionFFTSettings (ViSession instrumentHandle,
                                                         ViInt32 channel,
                                                         ViInt32 *FFTSize,
                                                         ViInt32 *FFTWindow,
                                                         ViReal64 *kaiserWindowBeta);
ViStatus _VI_FUNC rssiup_SetAnalyzerFunctionFFTAveraging (ViSession instrumentHandle,
                                                          ViInt32 channel,
                                                          ViInt32 averagingMode,
                                                          ViInt32 averagingFactor);
ViStatus _VI_FUNC rssiup_GetAnalyzerFunctionFFTAveraging (ViSession instrumentHandle,
                                                          ViInt32 channel,
                                                          ViInt32 *averagingMode,
                                                          ViInt32 *averagingFactor);
ViStatus _VI_FUNC rssiup_SetAnalyzerDigitalFilter (ViSession instrumentHandle,
                                                   ViInt32 channel,
                                                   ViInt32 filterSection,
                                                   ViInt32 filterType,
                                                   ViReal64 centerFrequency);
ViStatus _VI_FUNC rssiup_GetAnalyzerDigitalFilter (ViSession instrumentHandle,
                                                   ViInt32 filterSection,
                                                   ViInt32 _VI_FAR filterType[],
                                                   ViReal64 _VI_FAR centerFrequency[],
                                                   ViReal64 _VI_FAR filterDelay[],
                                                   ViInt32 _VI_FAR filterBiQuads[],
                                                   ViInt32 *biQuadsCount);
ViStatus _VI_FUNC rssiup_SetAnalogAnalyzerInput (ViSession instrumentHandle,
                                                 ViInt32 channel,
                                                 ViInt32 analyzerInput);
ViStatus _VI_FUNC rssiup_GetAnalogAnalyzerInput (ViSession instrumentHandle,
                                                 ViInt32 channel,
                                                 ViInt32 *analyzerInput);
ViStatus _VI_FUNC rssiup_SetAnalogAnalyzerCoupling (ViSession instrumentHandle,
                                                    ViInt32 coupling);
ViStatus _VI_FUNC rssiup_GetAnalogAnalyzerCoupling (ViSession instrumentHandle,
                                                    ViInt32 *coupling);
ViStatus _VI_FUNC rssiup_SetAnalogAnalyzerFloatGround (ViSession instrumentHandle,
                                                       ViInt32 channel,
                                                       ViBoolean floatGround);
ViStatus _VI_FUNC rssiup_GetAnalogAnalyzerFloatGround (ViSession instrumentHandle,
                                                       ViInt32 channel,
                                                       ViBoolean *floatGround);
ViStatus _VI_FUNC rssiup_SetAnalogAnalyzerRangeDependency
             (ViSession instrumentHandle, ViInt32 rangeDependency);
ViStatus _VI_FUNC rssiup_GetAnalogAnalyzerRangeDependency
             (ViSession instrumentHandle, ViInt32 *rangeDependency);
ViStatus _VI_FUNC rssiup_SetAnalogAnalyzerRangeValue (ViSession instrumentHandle,
                                                      ViInt32 channel,
                                                      ViInt32 rangeMode,
                                                      ViReal64 rangeValue);
ViStatus _VI_FUNC rssiup_GetAnalogAnalyzerRange (ViSession instrumentHandle,
                                                 ViInt32 channel,
                                                 ViInt32 *rangeMode,
                                                 ViReal64 *lowerLimit,
                                                 ViReal64 *upperLimit);
ViStatus _VI_FUNC rssiup_AnalyzerPeakResponseData (ViSession instrumentHandle,
                                                   ViReal64 _VI_FAR peakMin[],
                                                   ViInt32 *peakMinUnit,
                                                   ViReal64 _VI_FAR peakMax[],
                                                   ViInt32 *peakMaxUnit);
ViStatus _VI_FUNC rssiup_AnalyzerRMSDCMeasurement (ViSession instrumentHandle,
                                                   ViReal64 _VI_FAR DC[],
                                                   ViInt32 *DCUnit,
                                                   ViReal64 _VI_FAR RMS[],
                                                   ViInt32 *RMSUnit,
                                                   ViReal64 _VI_FAR frequency[],
                                                   ViInt32 *frequencyUnit,
                                                   ViInt32 _VI_FAR dataStatus[],
                                                   ViInt32 _VI_FAR asynchronousStatus[]);
ViStatus _VI_FUNC rssiup_AnalyzerQpeakMeasurement (ViSession instrumentHandle,
                                                   ViReal64 _VI_FAR QPeakMin[],
                                                   ViInt32 *QPeakMinUnit,
                                                   ViReal64 _VI_FAR QPeakMax[],
                                                   ViInt32 *QPeakMaxUnit,
                                                   ViReal64 _VI_FAR QPeakCurrent[],
                                                   ViInt32 *QPeakCurrentUnit);
ViStatus _VI_FUNC rssiup_AnalyzerRMSSelectiveMeasurement (ViSession instrumentHandle,
                                                          ViReal64 _VI_FAR RMSValue[],
                                                          ViInt32 *unit,
                                                          ViInt32 *dataStatus);
ViStatus _VI_FUNC rssiup_AnalyzerRMSSelectiveVariableBWMainMeasurement (ViSession instrumentHandle,
                                                                   ViInt32 autoTuneLocked[],
                                                                   ViReal64 frequency[],
                                                                   ViReal64 RMS[],
                                                                   ViInt32 *levelValuesUnit);
ViStatus _VI_FUNC rssiup_AnalyzerRMSSelectiveVariableBWPostFFTMeasurement (ViSession instrumentHandle,
                                                                      ViInt32 FFTResponseHeader[],
                                                                      ViReal64 spectralLines[]);
ViStatus _VI_FUNC rssiup_AnalyzerTHDNMainMeasurement (ViSession instrumentHandle,
                                                      ViInt32 _VI_FAR autoTuneLocked[],
                                                      ViReal64 _VI_FAR frequency[],
                                                      ViReal64 _VI_FAR totalRMS[],
                                                      ViReal64 _VI_FAR noiseRMS[],
                                                      ViReal64 _VI_FAR totalRMSNonfund[],
                                                      ViReal64 _VI_FAR totalRMSTHD[],
                                                      ViReal64 _VI_FAR harmonicLines[],
                                                      ViInt32 *levelValuesUnit);
ViStatus _VI_FUNC rssiup_AnalyzerTHDNMeasurementResults (ViSession instrumentHandle,
                                                         ViInt32 units,
                                                         ViReal64 frequency[],
                                                         ViReal64 THDAllHarmonics[],
                                                         ViReal64 THDEvenHarmonics[],
                                                         ViReal64 THDOddHarmonics[],
                                                         ViReal64 SINAD[],
                                                         ViReal64 noiseSignal[]);
ViStatus _VI_FUNC rssiup_AnalyzerTHDNPostFFTMeasurement (ViSession instrumentHandle,
                                                         ViInt32 _VI_FAR FFTResponseHeader[],
                                                         ViReal64 _VI_FAR spectralLines[]);
ViStatus _VI_FUNC rssiup_AnalyzerTHDNMeasurementResultsExt (ViSession instrumentHandle,
                                                            ViInt32 units,
                                                            ViReal64 THDN[]);
ViStatus _VI_FUNC rssiup_AnalyzerPhaseMainMeasurement (ViSession instrumentHandle,
                                                       ViInt32 *autoTuneLocked,
                                                       ViReal64 *frequency,
                                                       ViReal64 *phaseDifference,
                                                       ViInt32 *frequencyMaster);
ViStatus _VI_FUNC rssiup_AnalyzerDFDMainMeasurement (ViSession instrumentHandle,
                                                     ViInt32 _VI_FAR autoTuneLocked[],
                                                     ViReal64 _VI_FAR frequencies[],
                                                     ViReal64 _VI_FAR RMSValues[],
                                                     ViInt32 *levelValuesUnit);
ViStatus _VI_FUNC rssiup_AnalyzerDFDMeasurementResults (ViSession instrumentHandle,
                                                        ViInt32 units,
                                                        ViReal64 d2IEC268[],
                                                        ViReal64 d3IEC268[],
                                                        ViReal64 d2IEC118[],
                                                        ViReal64 d3IEC118[]);
ViStatus _VI_FUNC rssiup_AnalyzerDFDPostFFTMeasurement (ViSession instrumentHandle,
                                                        ViInt32 _VI_FAR FFTResponseHeader[],
                                                        ViReal64 _VI_FAR spectralLines[]);
ViStatus _VI_FUNC rssiup_AnalyzerModDistMainMeasurement (ViSession instrumentHandle,
                                                         ViInt32 _VI_FAR autoTuneLocked[],
                                                         ViReal64 _VI_FAR frequencies[],
                                                         ViReal64 _VI_FAR RMSValues[],
                                                         ViInt32 *levelValuesUnit);
ViStatus _VI_FUNC rssiup_AnalyzerModDistMeasurementResults (ViSession instrumentHandle,
                                                            ViInt32 units,
                                                            ViReal64 modDist[]);
ViStatus _VI_FUNC rssiup_AnalyzerModDistPostFFTMeasurement
             (ViSession instrumentHandle, ViInt32 _VI_FAR FFTResponseHeader[],
              ViReal64 _VI_FAR spectralLines[]);
ViStatus _VI_FUNC rssiup_AnalyzerFFTSpectrumMainMeasurement
             (ViSession instrumentHandle, ViInt32 _VI_FAR FFTResponseHeader[],
              ViReal64 _VI_FAR spectralLines[]);
ViStatus _VI_FUNC rssiup_AnalyzerRMSSweepMeasurement (ViSession instrumentHandle,
                                                      ViUInt16 *sweepCount,
                                                      ViUInt16 *sampleCount,
                                                      ViReal64 actualAmplitude[],
													  ViReal64 sweepParams[],
													  ViReal64 RMSValues[]);
ViStatus _VI_FUNC rssiup_AnalyzerRMSSelectiveSweepMeasurement (ViSession instrumentHandle,
                                                               ViUInt16 *sweepCount,
                                                               ViUInt16 *sampleCount,
                                                               ViReal64 sweepParams[],
                                                               ViReal64 actualAmplitude[],
                                                               ViInt32 autoTuneLocked[],
                                                               ViReal64 frequency[],
                                                               ViReal64 RMS[]);
ViStatus _VI_FUNC rssiup_AnalyzerTHDSweepMeasurement (ViSession instrumentHandle,
                                                      ViUInt16 *sweepCount,
                                                      ViUInt16 *sampleCount,
                                                      ViReal64 sweepParams[],
                                                      ViReal64 actualAmplitude[],
                                                      ViInt32 autoTuneLocked[],
                                                      ViReal64 frequency[],
                                                      ViReal64 totalRMS[],
                                                      ViReal64 noiseRMS[],
                                                      ViReal64 totalRMSNonfund[],
                                                      ViReal64 totalRMSTHD[],
                                                      ViReal64 harmonicLines[]);
ViStatus _VI_FUNC rssiup_AnalyzerTHDSweepMeasurementResults (ViSession instrumentHandle,
                                                             ViInt32 units,
                                                             ViInt32 *valuesReturned,
                                                             ViReal64 sweepParams[],
                                                             ViReal64 THDAllHarmonics[],
                                                             ViReal64 THDEvenHarmonics[],
                                                             ViReal64 THDOddHarmonics[],
                                                             ViReal64 SINAD[],
                                                             ViReal64 noiseSignal[]);
ViStatus _VI_FUNC rssiup_AnalyzerTHDSweepMeasurementResultsExt (ViSession instrumentHandle,
                                                                ViInt32 units,
                                                                ViInt32 *valuesReturned,
                                                                ViReal64 THDN[]);
ViStatus _VI_FUNC rssiup_AnalyzerTHDSweepMeasurementResults2 (ViSession instrumentHandle,
                                                              ViInt32 units,
                                                              ViInt32 *valuesReturned,
                                                              ViReal64 sweepParams[],
                                                              ViReal64 THDN[]);
ViStatus _VI_FUNC rssiup_SetDigitalAnalyzerSampleRateSettings
             (ViSession instrumentHandle, ViReal64 measurementTime);
ViStatus _VI_FUNC rssiup_GetDigitalAnalyzerSampleRateSettings
             (ViSession instrumentHandle, ViReal64 *measurementTime);
ViStatus _VI_FUNC rssiup_SetDigitalAnalyzerSampleRateAveraging
             (ViSession instrumentHandle, ViInt32 averagingMode,
              ViInt32 averagingFactor);
ViStatus _VI_FUNC rssiup_GetDigitalAnalyzerSampleRateAveraging
             (ViSession instrumentHandle, ViInt32 *averagingMode,
              ViInt32 *averagingFactor);
ViStatus _VI_FUNC rssiup_DigitalAnalyzerSampleRateMeasurement
             (ViSession instrumentHandle, ViReal64 *samplingFrequency);
ViStatus _VI_FUNC rssiup_SetDigitalAnalyzerProtocol (ViSession instrumentHandle,
                                                     ViInt32 DAIProtocol,
                                                     ViReal64 measurementTime);
ViStatus _VI_FUNC rssiup_GetDigitalAnalyzerProtocol (ViSession instrumentHandle,
                                                     ViInt32 *DAIProtocol,
                                                     ViReal64 *measurementTime);
ViStatus _VI_FUNC rssiup_DigitalAnalyzerProtocolMeasurement
             (ViSession instrumentHandle, ViChar _VI_FAR chAData[],
              ViChar _VI_FAR chBData[], ViInt32 *receiverError);
ViStatus _VI_FUNC rssiup_SetDigitalAnalyzerInput (ViSession instrumentHandle,
                                                  ViInt32 digitalInput);
ViStatus _VI_FUNC rssiup_GetDigitalAnalyzerInput (ViSession instrumentHandle,
                                                  ViInt32 *digitalInput);
ViStatus _VI_FUNC rssiup_SetDigitalAnalyzerNoofBits (ViSession instrumentHandle,
                                                     ViInt32 channel,
                                                     ViInt32 no_ofBits);
ViStatus _VI_FUNC rssiup_GetDigitalAnalyzerNoofBits (ViSession instrumentHandle,
                                                     ViInt32 channel,
                                                     ViInt32 *no_ofBits);
ViStatus _VI_FUNC rssiup_SetGeneratorDeviceSelector (ViSession instrumentHandle,
                                                     ViInt32 device);
ViStatus _VI_FUNC rssiup_GetGeneratorDeviceSelector (ViSession instrumentHandle,
                                                     ViInt32 *device);
ViStatus _VI_FUNC rssiup_SetGeneratorFunctionSineShape (ViSession instrumentHandle,
                                                        ViReal64 frequency1,
                                                        ViInt32 frequency1Unit,
                                                        ViReal64 initialPhase1,
                                                        ViInt32 initialPhase1Unit,
                                                        ViReal64 frequency2,
                                                        ViInt32 frequency2Unit,
                                                        ViReal64 initialPhase2,
                                                        ViInt32 initialPhase2Unit);
ViStatus _VI_FUNC rssiup_GetGeneratorFunctionSineShape (ViSession instrumentHandle,
                                                        ViReal64 *frequency1,
                                                        ViInt32 *frequency1Unit,
                                                        ViReal64 *initialPhase1,
                                                        ViInt32 *initialPhase1Unit,
                                                        ViReal64 *frequency2,
                                                        ViInt32 *frequency2Unit,
                                                        ViReal64 *initialPhase2,
                                                        ViInt32 *initialPhase2Unit);
ViStatus _VI_FUNC rssiup_SetGeneratorFunctionSineDimension
             (ViSession instrumentHandle, ViInt32 channel, ViReal64 DCOffset,
              ViInt32 DCOffsetUnit, ViReal64 amplitude1, ViInt32 amplitude1Unit,
              ViReal64 amplitude2, ViInt32 amplitude2Unit);
ViStatus _VI_FUNC rssiup_GetGeneratorFunctionSineDimension
             (ViSession instrumentHandle, ViInt32 channel, ViReal64 *DCOffset,
              ViInt32 *DCOffsetUnit, ViReal64 *amplitude1, ViInt32 *amplitude1Unit,
              ViReal64 *amplitude2, ViInt32 *amplitude2Unit);
ViStatus _VI_FUNC rssiup_SetGeneratorFunctionNoiseShape (ViSession instrumentHandle,
                                                         ViInt32 PDF,
                                                         ViInt32 gaussianFactor);
ViStatus _VI_FUNC rssiup_GetGeneratorFunctionNoiseShape (ViSession instrumentHandle,
                                                         ViInt32 *PDF,
                                                         ViInt32 *gaussianFactor);
ViStatus _VI_FUNC rssiup_SetGeneratorFunctionNoiseDimension
             (ViSession instrumentHandle, ViInt32 channel, ViReal64 DCOffset,
              ViInt32 DCOffsetUnit, ViReal64 amplitude1, ViInt32 amplitude1Unit,
              ViReal64 amplitude2, ViInt32 amplitude2Unit);
ViStatus _VI_FUNC rssiup_GetGeneratorFunctionNoiseDimension
             (ViSession instrumentHandle, ViInt32 channel, ViReal64 *DCOffset,
              ViInt32 *DCOffsetUnit, ViReal64 *amplitude1, ViInt32 *amplitude1Unit,
              ViReal64 *amplitude2, ViInt32 *amplitude2Unit);
ViStatus _VI_FUNC rssiup_SetGeneratorFunctionMultisineShape
             (ViSession instrumentHandle, ViInt32 no_ofHarmonic,
              ViReal64 _VI_FAR frequency[], ViReal64 _VI_FAR initialPhase[],
              ViReal64 _VI_FAR relativeAmplitude[], ViReal64 AMFrequency);
ViStatus _VI_FUNC rssiup_GetGeneratorFunctionMultisineShape
             (ViSession instrumentHandle, ViInt32 *no_ofHarmonic,
              ViReal64 _VI_FAR frequency[], ViReal64 _VI_FAR initialPhase[],
              ViReal64 _VI_FAR relativeAmplitude[], ViReal64 *AMFrequency);
ViStatus _VI_FUNC rssiup_SetGeneratorFunctionMultisineDimension
             (ViSession instrumentHandle, ViInt32 channel, ViReal64 DCOffset,
              ViInt32 DCOffsetUnit, ViReal64 amplitude1, ViInt32 amplitude1Unit,
              ViReal64 amplitude2, ViInt32 amplitude2Unit,
              ViReal64 AMModulationDepth);
ViStatus _VI_FUNC rssiup_GetGeneratorFunctionMultisineDimension
             (ViSession instrumentHandle, ViInt32 channel, ViReal64 *DCOffset,
              ViInt32 *DCOffsetUnit, ViReal64 *amplitude1, ViInt32 *amplitude1Unit,
              ViReal64 *amplitude2, ViInt32 *amplitude2Unit,
              ViReal64 *AMModulationDepth);
ViStatus _VI_FUNC rssiup_SetGeneratorFunctionSineBurstShape
             (ViSession instrumentHandle, ViReal64 frequency, ViInt32 frequencyUnit,
              ViReal64 burstOnDelay, ViInt32 burstOnDelayUnit, ViReal64 burstOnTime,
              ViInt32 burstOnTimeUnit, ViReal64 burstOffTime,
              ViInt32 burstOffTimeUnit, ViInt32 signalType);
ViStatus _VI_FUNC rssiup_GetGeneratorFunctionSineBurstShape
             (ViSession instrumentHandle, ViReal64 *frequency,
              ViInt32 *frequencyUnit, ViReal64 *burstOnDelay,
              ViInt32 *burstOnDelayUnit, ViReal64 *burstOnTime,
              ViInt32 *burstOnTimeUnit, ViReal64 *burstOffTime,
              ViInt32 *burstOffTimeUnit, ViInt32 *signalType);
ViStatus _VI_FUNC rssiup_SetGeneratorFunctionSineBurstDimension
             (ViSession instrumentHandle, ViInt32 channel, ViReal64 DCOffset,
              ViInt32 DCOffsetUnit, ViReal64 amplitude1, ViInt32 amplitude1Unit,
              ViReal64 amplitude2, ViInt32 amplitude2Unit,
              ViReal64 lowLevelAmplitude, ViInt32 lowLevelAmplitudeUnit);
ViStatus _VI_FUNC rssiup_GetGeneratorFunctionSineBurstDimension
             (ViSession instrumentHandle, ViInt32 channel, ViReal64 *DCOffset,
              ViInt32 *DCOffsetUnit, ViReal64 *amplitude1, ViInt32 *amplitude1Unit,
              ViReal64 *amplitude2, ViInt32 *amplitude2Unit,
              ViReal64 *lowLevelAmplitude, ViInt32 *lowLevelAmplitudeUnit);
ViStatus _VI_FUNC rssiup_SetGeneratorFunctionPolarityDimension
             (ViSession instrumentHandle, ViInt32 channel, ViReal64 DCOffset,
              ViInt32 DCOffsetUnit, ViReal64 amplitude1, ViInt32 amplitude1Unit,
              ViReal64 amplitude2, ViInt32 amplitude2Unit);
ViStatus _VI_FUNC rssiup_GetGeneratorFunctionPolarityDimension
             (ViSession instrumentHandle, ViInt32 channel, ViReal64 *DCOffset,
              ViInt32 *DCOffsetUnit, ViReal64 *amplitude1, ViInt32 *amplitude1Unit,
              ViReal64 *amplitude2, ViInt32 *amplitude2Unit);
ViStatus _VI_FUNC rssiup_SetGeneratorFunctionState (ViSession instrumentHandle,
                                                    ViInt32 channel,
                                                    ViInt32 functionID,
                                                    ViBoolean functionState);
ViStatus _VI_FUNC rssiup_GetGeneratorFunctionState (ViSession instrumentHandle,
                                                    ViInt32 channel,
                                                    ViInt32 functionID,
                                                    ViBoolean *functionState);
ViStatus _VI_FUNC rssiup_SetAnalogGeneratorOutput (ViSession instrumentHandle,
                                                   ViInt32 channel,
                                                   ViBoolean generatorOutput);
ViStatus _VI_FUNC rssiup_GetAnalogGeneratorOutput (ViSession instrumentHandle,
                                                   ViInt32 channel,
                                                   ViBoolean *generatorOutput);
ViStatus _VI_FUNC rssiup_SetAnalogGeneratorFloatGround (ViSession instrumentHandle,
                                                        ViInt32 channel,
                                                        ViBoolean floatGround);
ViStatus _VI_FUNC rssiup_GetAnalogGeneratorFloatGround (ViSession instrumentHandle,
                                                        ViInt32 channel,
                                                        ViBoolean *floatGround);
ViStatus _VI_FUNC rssiup_SetAnalogGeneratorRangeDependency
             (ViSession instrumentHandle, ViInt32 rangeDependency);
ViStatus _VI_FUNC rssiup_GetAnalogGeneratorRangeDependency
             (ViSession instrumentHandle, ViInt32 *rangeDependency);
ViStatus _VI_FUNC rssiup_SetAnalogGeneratorRangeValue (ViSession instrumentHandle,
                                                       ViInt32 channel,
                                                       ViInt32 rangeMode,
                                                       ViReal64 rangeValue,
                                                       ViInt32 unit);
ViStatus _VI_FUNC rssiup_GetAnalogGeneratorRange (ViSession instrumentHandle,
                                                  ViInt32 channel,
                                                  ViInt32 *rangeMode,
                                                  ViReal64 *lowerLimit,
                                                  ViReal64 *upperLimit);
ViStatus _VI_FUNC rssiup_SetGeneratorGlobalDCOffset (ViSession instrumentHandle,
                                                     ViInt32 channel,
                                                     ViReal64 DCOffset,
                                                     ViInt32 DCOffsetUnit);
ViStatus _VI_FUNC rssiup_GetGeneratorGlobalDCOffset (ViSession instrumentHandle,
                                                     ViInt32 channel,
                                                     ViReal64 *DCOffset,
                                                     ViInt32 *DCOffsetUnit);
ViStatus _VI_FUNC rssiup_SetDigitalGeneratorProtocol (ViSession instrumentHandle,
                                                      ViString channelStatus,
                                                      ViString userData,
                                                      ViInt32 validityBit);
ViStatus _VI_FUNC rssiup_GetDigitalGeneratorProtocol (ViSession instrumentHandle,
                                                      ViInt32 channel,
                                                      ViChar _VI_FAR channelStatus[],
                                                      ViChar _VI_FAR userData[],
                                                      ViInt32 *validityBit);
ViStatus _VI_FUNC rssiup_SetDigitalGeneratorNoofBits (ViSession instrumentHandle,
                                                      ViInt32 no_ofBits);
ViStatus _VI_FUNC rssiup_GetDigitalGeneratorNoofBits (ViSession instrumentHandle,
                                                      ViInt32 *no_ofBits);
ViStatus _VI_FUNC rssiup_SetDigitalGeneratorSamplingFrequencyOffset
             (ViSession instrumentHandle, ViInt32 samplingFrequencyOffset);
ViStatus _VI_FUNC rssiup_GetDigitalGeneratorSamplingFrequencyOffset
             (ViSession instrumentHandle, ViInt32 *samplingFrequencyOffset);
ViStatus _VI_FUNC rssiup_SetGeneratorFunctionRMSSweepFrequency (ViSession instrumentHandle,
                                               ViReal64 startFrequency,
                                               ViReal64 stopFrequency,
                                               ViInt32 frequencySweepSpacing,
                                               ViInt32 frequencySweepSteps,
                                               ViInt32 frequencyStepDelay);
ViStatus _VI_FUNC rssiup_GetGeneratorFunctionRMSSweepFrequency (ViSession instrumentHandle,
                                               ViReal64 *startFrequency,
                                               ViReal64 *stopFrequency,
                                               ViInt32 *frequencySweepSpacing,
                                               ViInt32 *frequencySweepSteps,
                                               ViInt32 *frequencyStepDelay);
ViStatus _VI_FUNC rssiup_SetGeneratorFunctionRMSSweepAmplitude (ViSession instrumentHandle,
                                                      ViInt32 channel,
                                                      ViReal64 startAmplitude,
                                                      ViReal64 stopAmplitude,
                                                      ViInt32 amplitudeSweepSpacing,
                                                      ViReal64 measurementTime,
                                                      ViInt32 amplitudeSweepSteps,
                                                      ViInt32 amplitudeStepDelay);
ViStatus _VI_FUNC rssiup_GetGeneratorFunctionRMSSweepAmplitude (ViSession instrumentHandle,
                                                      ViInt32 channel,
                                                      ViReal64 *startAmplitude,
                                                      ViReal64 *stopAmplitude,
                                                      ViInt32 *amplitudeSweepSpacing,
                                                      ViReal64 *measurementTime,
													  ViInt32 *amplitudeSweepSteps,
													  ViInt32 *amplitudeStepDelay);
ViStatus _VI_FUNC rssiup_SetGeneratorFunctionRMSSelectiveSweepFrequency (ViSession instrumentHandle,
                                                        ViReal64 startFrequency,
                                                        ViReal64 stopFrequency,
                                                        ViInt32 frequencySweepSpacing,
                                                        ViInt32 frequencySweepSteps,
                                                        ViInt32 frequencyStepDelay);
ViStatus _VI_FUNC rssiup_SetGeneratorFunctionRMSSelectiveSweepBandwidth (ViSession instrumentHandle,
                                                                ViInt32 filterBandwidthType,
                                                                ViReal64 filterBandwidth,
                                                                ViReal64 multipleOfCenterFrequency);
ViStatus _VI_FUNC rssiup_GetGeneratorFunctionRMSSelectiveSweepFrequency (ViSession instrumentHandle,
                                                        ViReal64 *startFrequency,
                                                        ViReal64 *stopFrequency,
                                                        ViInt32 *frequencySweepSpacing,
                                                        ViInt32 *frequencySweepSteps,
                                                        ViInt32 *frequencyStepDelay);
ViStatus _VI_FUNC rssiup_GetGeneratorFunctionRMSSelectiveSweepBandwidth (ViSession instrumentHandle,
                                                                ViInt32 *filterBandwidthType,
                                                                ViReal64 *filterBandwidth,
                                                                ViReal64 *multipleOfCenterFrequency);
ViStatus _VI_FUNC rssiup_GetGeneratorFunctionRMSSelectiveFrequencyLimits (ViSession instrumentHandle,
                                                                  ViInt32 filterBandwidthType,
                                                                  ViReal64 bandwidth,
                                                                  ViReal64 *lowerLimit,
                                                                  ViReal64 *upperLimit);
ViStatus _VI_FUNC rssiup_SetGeneratorFunctionRMSSelectiveSweepAmplitude (ViSession instrumentHandle,
                                                               ViInt32 channel,
                                                               ViReal64 startAmplitude,
                                                               ViReal64 stopAmplitude,
                                                               ViInt32 amplitudeSweepSpacing,
															   ViInt32 amplitudeSweepSteps,
															   ViInt32 amplitudeStepDelay);
ViStatus _VI_FUNC rssiup_GetGeneratorFunctionRMSSelectiveSweepAmplitude (ViSession instrumentHandle,
                                                               ViInt32 channel,
                                                               ViReal64 *startAmplitude,
                                                               ViReal64 *stopAmplitude,
                                                               ViInt32 *amplitudeSweepSpacing,
															   ViInt32 *amplitudeSweepSteps,
															   ViInt32 *amplitudeStepDelay);
ViStatus _VI_FUNC rssiup_SetGeneratorAllParamChanRMSSelectiveSweep (ViSession instrumentHandle,
                                                                    ViInt32 channel,
                                                                    ViReal64 DCOffset,
                                                                    ViReal64 startAmplitude[],
                                                                    ViReal64 stopAmplitude[],
                                                                    ViInt32 amplitudeSweepSpacing[],
                                                                    ViReal64 analyzerStartFrequency,
                                                                    ViReal64 analyzerStopFrequency,
                                                                    ViInt32 frequencySpacing);
ViStatus _VI_FUNC rssiup_SetGeneratorAllParamRMSSelectiveSweep (ViSession instrumentHandle,
                                                                ViReal64 startFrequency[],
                                                                ViReal64 stopFrequency[],
                                                                ViInt32 frequencySweepSpacing[],
                                                                ViInt32 sweepSteps[],
                                                                ViInt32 stepDelay[],
                                                                ViReal64 generatorInitPhase[]);
ViStatus _VI_FUNC rssiup_SetGeneratorAllParamRMSSelectiveSweepSettings (ViSession instrumentHandle,
                                                                        ViInt32 resultsRefreshTime,
                                                                        ViInt32 numberOfSweepLoops,
                                                                        ViInt32 sweepStepControl,
                                                                        ViInt32 LPFilterOrder,
                                                                        ViInt32 filterBandwidthType,
                                                                        ViReal64 filterBandwidth,
                                                                        ViReal64 multipleOfCenterFrequency,
																		ViInt32 frequencyMode);
ViStatus _VI_FUNC rssiup_GetGeneratorAllParamChanRMSSelectiveSweep (ViSession instrumentHandle,
                                                                    ViInt32 channel,
                                                                    ViReal64 *DCOffset,
                                                                    ViReal64 startAmplitude[],
                                                                    ViReal64 stopAmplitude[],
                                                                    ViInt32 amplitudeSweepSpacing[],
                                                                    ViReal64 *analyzerStartFrequency,
                                                                    ViReal64 *analyzerStopFrequency,
                                                                    ViInt32 *frequencySpacing);
ViStatus _VI_FUNC rssiup_GetGeneratorAllParamRMSSelectiveSweep (ViSession instrumentHandle,
                                                                ViReal64 startFrequency[],
                                                                ViReal64 stopFrequency[],
                                                                ViInt32 frequencySweepSpacing[],
                                                                ViInt32 sweepSteps[],
                                                                ViInt32 stepDelay[],
                                                                ViReal64 generatorInitPhase[]);
ViStatus _VI_FUNC rssiup_GetGeneratorAllParamRMSSelectiveSweepSettings (ViSession instrumentHandle,
                                                                        ViInt32 *resultsRefreshTime,
                                                                        ViInt32 *numberOfSweepLoops,
                                                                        ViInt32 *sweepStepControl,
                                                                        ViInt32 *LPFilterOrder,
                                                                        ViInt32 *filterBandwidthType,
                                                                        ViReal64 *filterBandwidth,
                                                                        ViReal64 *multipleOfCenterFrequency,
                                                                        ViInt32 *frequencyMode);
ViStatus _VI_FUNC rssiup_SetGeneratorFunctionTHDSweepFrequency (ViSession instrumentHandle,
                                               ViReal64 startFrequency,
                                               ViReal64 stopFrequency,
                                               ViInt32 frequencySweepSpacing,
                                               ViInt32 frequencySweepSteps,
                                               ViInt32 frequencyStepDelay);
ViStatus _VI_FUNC rssiup_GetGeneratorFunctionTHDSweepFrequency (ViSession instrumentHandle,
                                               ViReal64 *startFrequency,
                                               ViReal64 *stopFrequency,
                                               ViInt32 *frequencySweepSpacing,
                                               ViInt32 *frequencySweepSteps,
                                               ViInt32 *frequencyStepDelay);
ViStatus _VI_FUNC rssiup_SetGeneratorFunctionTHDSweepAmplitude (ViSession instrumentHandle,
                                                      ViInt32 channel,
                                                      ViReal64 startAmplitude,
                                                      ViReal64 stopAmplitude,
                                                      ViInt32 amplitudeSweepSpacing,
													  ViInt32 amplitudeSweepSteps,
													  ViInt32 amplitudeStepDelay);
ViStatus _VI_FUNC rssiup_GetGeneratorFunctionTHDSweepAmplitude (ViSession instrumentHandle,
                                                      ViInt32 channel,
                                                      ViReal64 *startAmplitude,
                                                      ViReal64 *stopAmplitude,
                                                      ViInt32 *amplitudeSweepSpacing,
													  ViInt32 *amplitudeSweepSteps,
													  ViInt32 *amplitudeStepDelay);
ViStatus _VI_FUNC rssiup_SetAudioMonitorOutput (ViSession instrumentHandle,
                                                ViInt32 channel,
                                                ViBoolean monitorOutput);
ViStatus _VI_FUNC rssiup_GetAudioMonitorOutput (ViSession instrumentHandle,
                                                ViInt32 channel,
                                                ViBoolean *monitorOutput);
ViStatus _VI_FUNC rssiup_SetAudioMonitorSource (ViSession instrumentHandle,
                                                ViInt32 source);
ViStatus _VI_FUNC rssiup_GetAudioMonitorSource (ViSession instrumentHandle,
                                                ViInt32 *source);
ViStatus _VI_FUNC rssiup_SetAudioMonitorAttenuation (ViSession instrumentHandle,
                                                     ViInt32 channel,
                                                     ViReal64 attenuation);
ViStatus _VI_FUNC rssiup_GetAudioMonitorAttenuation (ViSession instrumentHandle,
                                                     ViInt32 channel,
                                                     ViReal64 *attenuation);
ViStatus _VI_FUNC rssiup_configureRefOscillator (ViSession instrumentHandle,
                                                 ViBoolean state, ViInt32 source,
                                                 ViInt32 frequency);
ViStatus _VI_FUNC rssiup_getRefOscillatorParameters (ViSession instrumentHandle,
                                                     ViBoolean *state,
                                                     ViInt32 *source,
                                                     ViInt32 *frequency);
ViStatus _VI_FUNC rssiup_setTimeOut (ViSession instrumentHandle, ViInt32 timeout);
ViStatus _VI_FUNC rssiup_getTimeOut (ViSession instrumentHandle, ViInt32 *timeout);
ViStatus _VI_FUNC rssiup_flushErrorQueue (ViSession instrumentHandle);
ViStatus _VI_FUNC rssiup_warningCheckState (ViSession instrumentHandle,
                                            ViBoolean warningChecking);
ViStatus _VI_FUNC rssiup_errorCheckState (ViSession instrumentHandle,
                                          ViBoolean stateChecking);
ViStatus _VI_FUNC rssiup_reset (ViSession instrumentHandle);
ViStatus _VI_FUNC rssiup_self_test (ViSession instrumentHandle,
                                    ViInt16 *selfTestResult,
                                    ViChar _VI_FAR selfTestMessage[]);
ViStatus _VI_FUNC rssiup_error_query (ViSession instrumentHandle,
                                      ViInt32 *errorCode,
                                      ViChar _VI_FAR errorMessage[]);
ViStatus _VI_FUNC rssiup_error_message (ViSession instrumentHandle,
                                        ViStatus statusCode,
                                        ViChar _VI_FAR message[]);
ViStatus _VI_FUNC rssiup_revision_query (ViSession instrumentHandle,
                                         ViChar _VI_FAR instrumentDriverRevision[],
                                         ViChar _VI_FAR firmwareRevision[]);
ViStatus _VI_FUNC rssiup_close (ViSession instrumentHandle);

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

/*****************************************************************************/
/*=== END INCLUDE FILE ======================================================*/
/*****************************************************************************/

#endif
