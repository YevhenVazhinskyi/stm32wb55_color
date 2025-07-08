# STM32WB55 BLE LED Control Device

A professional BLE-enabled LED control system built with STM32WB55 microcontroller and Flutter mobile application.

## 🚀 Project Overview

This project implements a complete BLE LED control solution featuring:
- **STM32WB55** microcontroller with integrated BLE stack
- **Real-time LED control** via BLE commands
- **Flutter mobile application** for intuitive user interface
- **Professional embedded architecture** with modular design
- **J-Link debugging** and flashing support
- **FreeRTOS** for real-time task management

## 🏗️ Architecture

### Hardware Platform
- **MCU**: STM32WB55CG (ARM Cortex-M4 + M0+ dual core)
- **Wireless**: Integrated BLE 5.0 stack
- **Memory**: 1MB Flash, 256KB RAM
- **Peripherals**: GPIO, I2C, SPI, UART, Timers

### Software Architecture
```
App/                    # Application layer
├── app__main.c         # Main application logic
├── app__main.h         # Application interface
└── blink__logic.c      # LED control logic

Core/                   # System core files
├── Inc/                # System headers
├── Src/                # System source files
└── Startup/            # Startup and linker files

Services/               # High-level services
├── ble__service.c      # BLE stack integration
├── led__controller.c   # LED management
├── motor__control.c    # Motor control service
├── power__manager.c    # Power management
├── sensor__manager.c   # Sensor interface
└── logger__service.c   # Debug logging

Drivers/                # Hardware drivers
├── MyDriver/           # Custom drivers
└── CubeMxDriver/       # STM32CubeMX generated
```

## 📋 Features

### BLE Capabilities
- **Service UUID**: `12345678-1234-1234-1234-123456789ABC`
- **Characteristics**:
  - LED State (Read/Write/Notify): `87654321-4321-4321-4321-CBA987654321`
  - LED Individual (Read/Write): `11111111-2222-3333-4444-555555555555`
  - System Status (Read/Notify): `AAAAAAAA-BBBB-CCCC-DDDD-EEEEEEEEEEEE`

### Performance
- **Response Time**: <100ms from BLE command to LED change
- **BLE Scanning**: <5 seconds connection time
- **Power Consumption**: <10mA active, <1mA standby

### Development Features
- **J-Link debugging** with RTT support
- **Professional code structure** with clear separation of concerns
- **Comprehensive error handling** and logging
- **Modular design** for easy maintenance and expansion

## 🛠️ Development Setup

### Prerequisites
```bash
# Required tools
- STM32CubeIDE or VS Code
- J-Link Software Tools
- arm-none-eabi-gcc toolchain
- make
- git

# Optional tools
- STM32CubeProgrammer
- Flutter SDK (for mobile app)
```

### Hardware Setup
1. Connect STM32WB55 development board
2. Connect J-Link programmer
3. Ensure proper power supply (3.3V)

### Building the Project
```bash
# Clone the repository
git clone https://github.com/yourusername/stm32wb55_color.git
cd stm32wb55_color

# Build the project
make clean
make

# Flash with J-Link
make flash

# Or use alternative methods
make flash-cube      # STM32CubeProgrammer
make flash-openocd   # OpenOCD
```

## 🔧 J-Link Integration

### Flashing
```bash
# Quick flash
make flash

# Debug session
make debug-server    # Terminal 1
make debug-gdb       # Terminal 2

# Real-time terminal (RTT)
make debug-rtt
```

### J-Link Commands
```bash
# Manual J-Link Commander
JLinkExe -device STM32WB55CG -if SWD -speed 4000

# J-Link Commander commands:
r                                    # Reset and halt
loadfile build/stm32wb55_color.hex  # Load firmware
r                                    # Reset
go                                   # Start execution
```

## 📡 BLE Protocol

### Data Formats
- **LED State**: 1 byte (bit mask for 4 LEDs)
- **LED Individual**: 2 bytes (LED ID + state)
- **System Status**: 4 bytes (status, errors, temperature)

### Example Usage
```c
// LED control via BLE
uint8_t led_state = 0x0F;  // All LEDs on
ble_service_notify_led_state(led_state);

// Individual LED control
uint8_t led_data[2] = {0x01, 0x01};  // LED 1 ON
ble_service_write_led_individual(led_data);
```

## 🧪 Testing

### Unit Tests
```bash
# Run embedded tests
make test

# Test BLE functionality
make test-ble

# Performance tests
make test-performance
```

### Integration Testing
- BLE communication tests
- LED response time verification
- Power consumption validation
- Error handling verification

## 📱 Mobile Application

The Flutter mobile application provides:
- BLE device scanning and connection
- Real-time LED control interface
- System status monitoring
- Configuration management

```bash
# Flutter app setup (if included)
cd mobile_app
flutter pub get
flutter run
```

## 🔧 Configuration

### BLE Configuration
- Located in `Core/Inc/ble_conf.h`
- Configurable parameters: connection intervals, advertising settings
- Memory allocation for BLE stack

### System Configuration
- FreeRTOS configuration in `Core/Inc/FreeRTOSConfig.h`
- HAL configuration in `Core/Inc/stm32wbxx_hal_conf.h`
- Application settings in `Core/Inc/app_conf.h`

## 📊 Performance Metrics

| Metric | Value |
|--------|-------|
| BLE Response Time | <100ms |
| Connection Time | <5s |
| Power Consumption (Active) | <10mA |
| Power Consumption (Standby) | <1mA |
| Flash Usage | ~30KB |
| RAM Usage | ~10KB |

## 🐛 Debugging

### Common Issues
1. **BLE Connection Failed**
   - Check wireless stack firmware
   - Verify UUIDs match in mobile app
   - Ensure proper BLE stack initialization

2. **Compilation Errors**
   - Verify STM32_WPAN_ENABLED flag
   - Check include paths
   - Update STM32CubeWB middleware

3. **Flashing Issues**
   - Check J-Link connection
   - Verify target device selection
   - Try different flashing methods

### Debug Tools
- **J-Link RTT**: Real-time terminal for debugging
- **STM32CubeProgrammer**: Memory inspection
- **Logic Analyzer**: BLE protocol analysis

## 📄 Documentation

- [Project Documentation](docs/Project.md)
- [Task Tracker](docs/Tasktracker.md)
- [Development Diary](docs/Diary.md)
- [Flashing Guide](docs/Flashing_Guide.md)
- [BLE Integration Status](docs/BLE_Integration_Status.md)

## 🤝 Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📋 Code Style

- **C/C++**: snake_case for functions, UPPER_SNAKE_CASE for constants
- **File naming**: `module__function.c` pattern
- **Documentation**: Doxygen-style comments
- **Max function length**: 50 lines
- **Max file length**: 500 lines

## 🔒 Security

- **BLE Security**: Just Works pairing for MVP
- **Input validation**: All BLE commands validated
- **Memory safety**: Buffer boundary checks
- **Error handling**: Comprehensive error logging

## 📈 Roadmap

- [ ] Advanced BLE security implementation
- [ ] OTA firmware update capability
- [ ] Extended LED effects and animations
- [ ] IoT cloud integration
- [ ] Multi-device management
- [ ] Enhanced power management

## 📞 Support

- **Issues**: Use GitHub issues for bug reports
- **Email**: [your-email@domain.com]
- **Documentation**: Check the `docs/` directory

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- STMicroelectronics for STM32WB55 platform
- SEGGER for J-Link tools
- ARM for mbed and CMSIS
- FreeRTOS community

---

**Built with ❤️ for embedded systems development**

*Last updated: 2024-12-19* 