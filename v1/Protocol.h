// typedef enum {
    // WL_NO_SHIELD        = 255,   // for compatibility with WiFi Shield library
    // WL_IDLE_STATUS      = 0,	
    // WL_NO_SSID_AVAIL    = 1,		// WRONG SSID
    // WL_SCAN_COMPLETED   = 2,	
    // WL_CONNECTED        = 3,		
    // WL_CONNECT_FAILED   = 4,		// WRONG PW
    // WL_CONNECTION_LOST  = 5,
    // WL_DISCONNECTED     = 6
// } wl_status_t;

const char Code[]={'I', 'B', 'S', 'W', 'T', 'S'};
  
typedef enum _function{
	// UDP <=> UART
	FUNC_READ_STATUS_OF_CHANNEL 			= 0x01,
	FUNC_READ_STATUS_OF_CHANNEL_RESPOND		= 0x02,
	FUNC_SINGLE_CHANNEL_CONTROL				= 0x03,
	FUNC_SINGLE_CHANNEL_CONTROL_RESPOND		= 0x04,
  FUNC_SET_LED_BRIGHTNESS               = 0x05,
  FUNC_SET_LED_BRIGHTNESS_RESPOND       = 0x06,
	FUNC_SET_REAL_TIME						= 0x10,
	FUNC_SET_REAL_TIME_RESPOND				= 0x11,
	FUNC_SET_TIMER_CONTROL					= 0x12,
	FUNC_SET_TIMER_CONTROL_RESPOND			= 0x13,
	FUNC_GET_TIMER_CONTROL					= 0x14,
	FUNC_GET_TIMER_CONTROL_RESPOND			= 0x15,
	
	// UPD, WiFi module Only
  
	FUNC_GET_WIFI_INFOR						= 0x20,
	FUNC_GET_WIFI_INFOR_RESPOND				= 0x21,
	FUNC_SCAN_DEVICE 						= 0x22,
	FUNC_SCAN_DEVICE_RESPOND				= 0x23,
	FUNC_CONFIG_NEW_NETWORK					= 0x0C,
  FUNC_GET_DEVICE_TYPE          = 0x24,
  FUNC_GET_DEVICE_TYPE_RESPOND          = 0x25,
  FUNC_CLEAR_WIFI_INFOR					= 0xFF	//Clear ssid and pw stored in eeprom
	
                       } function;
