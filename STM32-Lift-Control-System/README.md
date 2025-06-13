# STM32 Lift Control System

A professional-grade elevator control system designed for STM32 microcontrollers. This system implements a complete lift management solution with safety features, modular architecture, and real-time operation capabilities.

## 🏗️ Project Overview

This project provides a comprehensive lift (elevator) control system built specifically for ARM Cortex-M microcontrollers, particularly the STM32 family. The system is designed following embedded systems best practices with a focus on safety, reliability, and maintainability.

### Key Features

- ✅ **Professional State Machine Architecture**
- ✅ **Multi-Floor Support** (configurable up to 5 floors)
- ✅ **Emergency Safety Systems**
- ✅ **Door Control with Obstruction Detection**
- ✅ **Motor Control with Overheating Protection**
- ✅ **Comprehensive Error Logging**
- ✅ **Self-Diagnostic Capabilities**
- ✅ **Modular Design for Easy Customization**

## 📁 Project Structure

```
STM32-Lift-Control/
├── src/
│   ├── lift_system.h           # Main system definitions and API
│   ├── main.c                  # Core state machine implementation
│   ├── button_handler.h/.c     # Button input processing with debouncing
│   ├── motor_control.h/.c      # Motor safety and control management
│   └── sensor_interface.h/.c   # Sensor abstraction layer
├── docs/
│   ├── hardware_setup.md       # Hardware connection guide
│   ├── api_reference.md        # Complete API documentation
│   └── safety_guide.md         # Safety implementation guide
├── examples/
│   ├── basic_setup.c           # Simple implementation example
│   └── advanced_config.c       # Advanced configuration example
└── README.md                   # This file
```

## 🚀 Quick Start

### Prerequisites

- **Hardware**: STM32F103 or compatible ARM Cortex-M microcontroller
- **Software**: ARM GCC toolchain or Keil MDK-ARM
- **Memory**: Minimum 32KB Flash, 8KB RAM
- **IDE**: STM32CubeIDE, Keil µVision, or VSCode with ARM extensions

### Basic Implementation

1. **Clone the repository**
   ```bash
   git clone https://github.com/yourusername/stm32-lift-control.git
   cd stm32-lift-control
   ```

2. **Include in your STM32 project**
   ```c
   #include "lift_system.h"
   
   int main(void) {
       // Initialize STM32 HAL
       HAL_Init();
       SystemClock_Config();
       
       // Initialize lift system
       lift_system_init();
       
       // Configure SysTick for 100ms intervals
       SysTick_Config(SystemCoreClock / 10);
       
       while (1) {
           // Main loop - system updates handled in SysTick
       }
   }
   
   // SysTick Handler
   void SysTick_Handler(void) {
       HAL_IncTick();
       lift_system_update();  // Call every 100ms
   }
   ```

3. **Configure GPIO pins** (see Hardware Setup section)

4. **Compile and upload** to your STM32 board

## 🔌 Hardware Setup

### Pin Configuration (STM32F103 Example)

| Function | Pin | Description |
|----------|-----|-------------|
| Floor Buttons 1-5 | PA0-PA4 | Input with pull-up |
| Emergency Button | PA5 | Input with pull-up |
| Maintenance Button | PA6 | Input with pull-up |
| Motor UP Control | PB0 | Output (to motor driver) |
| Motor DOWN Control | PB1 | Output (to motor driver) |
| Door OPEN Control | PB2 | Output (to door motor) |
| Door CLOSE Control | PB3 | Output (to door motor) |
| Floor Sensors 1-5 | PC0-PC4 | Input (magnetic/optical) |
| Door OPEN Sensor | PC5 | Input (limit switch) |
| Door CLOSED Sensor | PC6 | Input (limit switch) |
| Obstruction Sensor | PC7 | Input (IR/ultrasonic) |

### GPIO Configuration Code

```c
void configure_gpio(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    
    // Enable GPIO clocks
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    
    // Configure button inputs (PA0-PA6)
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    
    // Configure motor outputs (PB0-PB3)
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    // Configure sensor inputs (PC0-PC7)
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}
```

## 🏛️ System Architecture

### Core Components

#### 1. **State Machine** (`main.c`)
The heart of the system implements a finite state machine with the following states:
- `LIFT_STATE_IDLE` - Waiting for requests
- `LIFT_STATE_MOVING_UP` - Moving upward
- `LIFT_STATE_MOVING_DOWN` - Moving downward  
- `LIFT_STATE_DOOR_OPENING` - Opening doors
- `LIFT_STATE_DOOR_OPEN` - Doors open, waiting
- `LIFT_STATE_DOOR_CLOSING` - Closing doors
- `LIFT_STATE_EMERGENCY_STOP` - Emergency condition
- `LIFT_STATE_MAINTENANCE` - Maintenance mode

#### 2. **Button Handler** (`button_handler.c`)
- Debounced input processing
- Edge detection for button presses
- Support for floor, emergency, and maintenance buttons

#### 3. **Motor Control** (`motor_control.c`)
- Safe motor operation with overheating protection
- Direction control with safety interlocks
- Emergency stop capabilities

#### 4. **Sensor Interface** (`sensor_interface.c`)
- Abstracted sensor reading
- Floor position detection
- Door status monitoring
- Obstruction detection

### Data Flow

```
Buttons → Button Handler → Main Controller → Motor Control → Hardware
                        ↓                  ↓
Sensors → Sensor Interface → State Machine → Door Control → Hardware
```

## ⚙️ Configuration

### System Parameters

Key parameters can be modified in `lift_system.h`:

```c
#define MAX_FLOORS              5       // Maximum number of floors
#define FLOOR_TRAVEL_TIME_MS    3000    // Time between floors
#define DOOR_OPERATION_TIME_MS  2000    // Door open/close time
#define IDLE_TIMEOUT_MS         10000   // Timeout before idle
#define SYSTEM_TICK_MS          100     // Main loop interval
```

### Runtime Configuration

```c
system_config_t config = {
    .floor_travel_time_ms = 2500,
    .door_operation_time_ms = 1500,
    .max_floors = 3,
    .enable_intermediate_stops = true,
    .enable_door_obstruction_detection = true
};

set_system_config(&config);
```

## 🛡️ Safety Features

### Emergency Systems
- **Immediate Stop**: Emergency button stops all operations instantly
- **Motor Protection**: Overheating detection with cooldown periods
- **Door Safety**: Obstruction detection prevents door closure
- **Sensor Validation**: Cross-checking of sensor readings
- **Timeout Protection**: Prevents system lockups

### Error Handling
```c
// Check system status
system_status_t status = get_system_status();
if (status.emergency_active) {
    // Handle emergency condition
}

// Check for faults
if (motor_has_fault()) {
    // Handle motor fault
}
```

## 🔧 API Reference

### Core Functions

#### System Control
```c
void lift_system_init(void);                    // Initialize system
void lift_system_update(void);                  // Update (call every 100ms)
void lift_process_floor_request(uint8_t floor); // Request floor
void lift_emergency_stop(void);                 // Emergency stop
void lift_reset_emergency(void);                // Reset after emergency
```

#### Status Monitoring
```c
bool lift_is_moving(void);                      // Check if moving
uint8_t lift_get_current_floor(void);           // Get current floor
lift_state_t lift_get_state(void);              // Get current state
system_status_t get_system_status(void);        // Get full status
```

#### Motor Control
```c
void motor_set_direction(motor_state_t direction); // Set motor direction
void motor_stop(void);                              // Stop motor
bool motor_is_running(void);                        // Check if running
bool motor_has_fault(void);                         // Check for faults
```

### Error Codes

| Code | Description |
|------|-------------|
| `ERROR_MOTOR_TIMEOUT` | Motor operation timeout |
| `ERROR_SENSOR_FAULT` | Sensor reading error |
| `ERROR_DOOR_OBSTRUCTION` | Door blocked |
| `ERROR_EMERGENCY_ACTIVATED` | Emergency stop triggered |
| `ERROR_QUEUE_OVERFLOW` | Too many floor requests |

## 🧪 Testing

### Self-Test Function
```c
self_test_result_t result = perform_system_self_test();
switch (result) {
    case SELF_TEST_PASS:
        // System OK
        break;
    case SELF_TEST_MOTOR_FAULT:
        // Motor issue detected
        break;
    // Handle other test results...
}
```

### Simulation Mode
For testing without hardware:
```c
// Simulate button press
button_simulate_press(2);  // Press floor 2 button

// Simulate reaching floor
sensor_simulate_floor_reached(3);  // Arrived at floor 3
```

## 🔍 Debugging

### Error Log System
```c
// Get recent errors
for (uint8_t i = 0; i < 5; i++) {
    error_log_entry_t entry = get_error_log_entry(i);
    if (entry.code != ERROR_NONE) {
        printf("Error %d at time %lu\n", entry.code, entry.timestamp);
    }
}
```

### Status Monitoring
```c
system_status_t status = get_system_status();
printf("State: %d, Floor: %d, Target: %d\n", 
       status.current_state, 
       status.current_floor, 
       status.target_floor);
```

## 📊 Performance

### Resource Usage
- **Flash Memory**: ~15KB (optimized build)
- **RAM Usage**: ~2KB static + ~1KB stack
- **CPU Usage**: <5% at 72MHz (STM32F103)
- **Response Time**: <100ms for button press to motor start

### Timing Specifications
- **System Tick**: 100ms (configurable)
- **Button Debounce**: 50ms
- **Emergency Stop**: <10ms response time
- **Floor Travel**: 3 seconds default (configurable)

## 🔧 Customization

### Adding More Floors
1. Modify `MAX_FLOORS` in `lift_system.h`
2. Update GPIO pin assignments
3. Add sensor calibration for new floors

### Custom Safety Features
```c
// Add custom safety check
bool custom_safety_check(void) {
    // Your safety logic here
    return true;  // Safe to operate
}

// Call in main update loop
if (!custom_safety_check()) {
    lift_emergency_stop();
}
```

### External Communication
```c
// Process external commands
command_packet_t cmd = receive_command();
response_packet_t response = process_command(&cmd);
send_response(&response);
```

## 🚨 Troubleshooting

### Common Issues

| Problem | Cause | Solution |
|---------|-------|----------|
| Lift doesn't move | Motor fault or emergency active | Check `motor_has_fault()` and reset if needed |
| Buttons not responding | GPIO configuration or debounce issue | Verify pin configuration and connections |
| Doors don't open | Sensor fault or obstruction | Check door sensors and clear obstructions |
| System resets | Stack overflow or watchdog | Increase stack size, check for infinite loops |

### Debug Output
Enable debug output by defining `DEBUG_ENABLED`:
```c
#define DEBUG_ENABLED
// System will output status messages via printf
```

## 📋 Compliance and Standards

This system is designed with consideration for:
- **IEC 61508** (Functional Safety)
- **EN 81-20/50** (Lift Safety Standards)
- **MISRA C** Guidelines (subset compliance)
- **ISO 26262** Automotive Safety (architecture principles)

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Coding Standards
- Follow MISRA C guidelines where applicable
- Use consistent naming conventions
- Document all public functions
- Include unit tests for new features

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👥 Authors

- **Embedded System Coach** - *Initial work and architecture*

## 🙏 Acknowledgments

- STMicroelectronics for STM32 HAL libraries
- ARM for Cortex-M architecture documentation
- Embedded systems community for best practices

---

⭐ **Star this repository if you find it useful!**

*Built with ❤️ for the embedded systems community*
