# STM32WB55 Flashing Guide

## 🚀 Quick Start with J-Link

1. **Connect your STM32WB55 board** via J-Link
2. **Build the project**:
   ```bash
   make clean && make
   ```
3. **Flash the application**:
   ```bash
   make flash
   ```

## 📋 Prerequisites

### Hardware Requirements
- STM32WB55 development board (Nucleo-WB55RG, P-Nucleo-WB55, etc.)
- **J-Link debugger** (J-Link EDU, J-Link BASE, J-Link PLUS, etc.)
- USB cable

### Software Requirements
**Option 1: J-Link Software (Recommended)**
```bash
# Download from: https://www.segger.com/downloads/jlink/
# macOS: Install J-Link Software and Documentation Pack
# Check installation:
JLinkExe -?
JLinkGDBServer -?
```

**Option 2: STM32CubeProgrammer**
```bash
# Download from: https://www.st.com/en/development-tools/stm32cubeprog.html
# Check installation:
STM32_Programmer_CLI --version
```

**Option 3: OpenOCD**
```bash
# macOS with Homebrew:
brew install openocd

# Ubuntu/Debian:
sudo apt-get install openocd

# Check installation:
openocd --version
```

## 🔥 Flashing Methods

### Method 1: Using Make Targets (Easiest)

```bash
# Show all available flash commands
make flash-help

# Flash application (uses J-Link)
make flash

# Alternative J-Link methods
make flash-jlink        # Dynamic J-Link script
make flash-jlink-bin    # Flash binary with J-Link

# Alternative methods
make flash-cube         # STM32CubeProgrammer
make flash-openocd      # OpenOCD with J-Link

# Erase entire flash
make erase              # J-Link erase
make erase-cube         # STM32CubeProgrammer erase
```

### Method 2: J-Link Commander (Manual)

```bash
# Start J-Link Commander
JLinkExe -device STM32WB55CG -if SWD -speed 4000

# In J-Link Commander prompt:
r                                    # Reset and halt target
loadfile build/stm32wb55_color.hex  # Load hex file
r                                    # Reset target
go                                   # Start execution
exit                                 # Exit J-Link Commander

# Or flash binary at specific address:
loadbin build/stm32wb55_color.bin,0x08000000  # Load binary
```

### Method 3: STM32CubeProgrammer CLI (Alternative)

```bash
# Flash HEX file
STM32_Programmer_CLI -c port=SWD -d build/stm32wb55_color.hex -rst

# Flash ELF file
STM32_Programmer_CLI -c port=SWD -d build/stm32wb55_color.elf -rst

# Flash binary at specific address
STM32_Programmer_CLI -c port=SWD -d build/stm32wb55_color.bin 0x08000000 -rst

# Verify flash
STM32_Programmer_CLI -c port=SWD -d build/stm32wb55_color.hex -v -rst
```

### Method 4: STM32CubeProgrammer GUI

1. Open **STM32CubeProgrammer**
2. Select **ST-LINK** and click **Connect**
3. Click **Open file** → Select `build/stm32wb55_color.hex`
4. Click **Download** to flash
5. Click **Disconnect**

### Method 5: OpenOCD with J-Link

```bash
# Direct OpenOCD command with J-Link
openocd -f interface/jlink.cfg -f target/stm32wbx.cfg \
        -c "program build/stm32wb55_color.hex verify reset exit"

# Using telnet interface
openocd -f interface/jlink.cfg -f target/stm32wbx.cfg &
telnet localhost 4444
> program build/stm32wb55_color.hex verify reset
> exit
```

## 🌐 STM32WB55 Wireless Stack

### **IMPORTANT**: The STM32WB55 requires a wireless stack on CPU2

#### Download Wireless Stack:
1. Go to [STM32CubeWB Downloads](https://www.st.com/en/embedded-software/stm32cubewb.html)
2. Download **STM32CubeWB** package
3. Extract wireless stack from: `STM32Cube_FW_WB_V1.x.x/Projects/STM32WB_Copro_Wireless_Binaries/STM32WB5x/`

#### Flash Wireless Stack:
```bash
# Method 1: J-Link Commander (Recommended)
JLinkExe -device STM32WB55CG -if SWD -speed 4000
# In J-Link Commander:
# loadbin ~/STM32CubeWB/Projects/STM32WB_Copro_Wireless_Binaries/STM32WB5x/stm32wb5x_BLE_Stack_light_fw.bin,0x080CB000
# r
# exit

# Method 2: STM32CubeProgrammer
STM32_Programmer_CLI -c port=SWD \
    -d ~/STM32CubeWB/Projects/STM32WB_Copro_Wireless_Binaries/STM32WB5x/stm32wb5x_BLE_Stack_light_fw.bin \
    0x080CB000

# Or use the make target for instructions
make flash-wireless
```

#### Available Wireless Stacks:
- **BLE Stack Light**: Basic BLE functionality (recommended for this project)
- **BLE Stack Full**: Full BLE features  
- **Thread Stack**: Thread/OpenThread protocol
- **Zigbee Stack**: Zigbee protocol
- **BLE+Thread**: Concurrent BLE and Thread

## 🔧 Memory Layout

### STM32WB55 Flash Memory Map:
```
0x08000000 - 0x080CAFFF: CPU1 Application (824KB)
0x080CB000 - 0x080FEFFF: CPU2 Wireless Stack (208KB)  
0x080FF000 - 0x080FFFFF: System Flash (4KB)
```

### Build Outputs:
- `build/stm32wb55_color.elf`: ELF file with debug symbols
- `build/stm32wb55_color.hex`: Intel HEX format (recommended)
- `build/stm32wb55_color.bin`: Raw binary file
- `build/stm32wb55_color.map`: Memory map file

## 🔍 Debugging with J-Link

### Start Debug Session:
```bash
# Terminal 1: Start J-Link GDB Server
make debug-server

# Terminal 2: Connect with GDB
make debug-gdb

# In GDB:
(gdb) target remote localhost:2331
(gdb) load
(gdb) monitor reset
(gdb) continue
```

### J-Link RTT (Real-Time Terminal):
```bash
# Start RTT Viewer for printf debugging
make debug-rtt

# In your code, use:
# #include "SEGGER_RTT.h"
# SEGGER_RTT_printf(0, "Debug: %d\n", value);
```

### J-Link Commander Debug:
```bash
# Start J-Link Commander
JLinkExe -device STM32WB55CG -if SWD -speed 4000

# Common debug commands:
halt                    # Halt CPU
step                    # Single step
go                      # Continue execution
r                       # Reset
mem 0x20000000,0x100   # Read memory
regs                    # Show registers
```

## 🐛 Troubleshooting

### Connection Issues:
```bash
# Check J-Link connection
JLinkExe -device STM32WB55CG -if SWD -speed 4000 -autoconnect 1

# Check with STM32CubeProgrammer
STM32_Programmer_CLI -l

# Reset and reconnect
STM32_Programmer_CLI -c port=SWD mode=UR -rst

# Under reset connection (if device is stuck)
STM32_Programmer_CLI -c port=SWD mode=UnderReset -rst
```

### Common Problems:

**Problem**: `Error: No ST-LINK detected!`
**Solution**: 
- Check USB cable connection
- Install ST-Link drivers
- Try different USB port

**Problem**: `Error: Target not found`  
**Solution**:
- Check board power
- Try under-reset mode
- Verify correct target (STM32WB55)

**Problem**: `Flash write error`
**Solution**:
- Erase flash first: `make erase`
- Check write protection
- Verify sufficient space

**Problem**: `BLE not working`
**Solution**:
- Flash the wireless stack to CPU2
- Verify correct wireless stack version
- Check IPCC configuration

### Debug Mode:
```bash
# Enable debug output
STM32_Programmer_CLI -c port=SWD -d build/stm32wb55_color.hex -rst -log debug.log

# Check device information  
STM32_Programmer_CLI -c port=SWD -r32 0x1FFF7590 1  # Device ID
STM32_Programmer_CLI -c port=SWD -r32 0x1FFF7594 1  # Revision ID
```

## 📊 Verification

### Check Flash Success:
```bash
# Read back and verify
STM32_Programmer_CLI -c port=SWD -u build/stm32wb55_color.hex

# Check application is running
STM32_Programmer_CLI -c port=SWD -r32 0x08000004 1  # Reset vector
```

### Serial Output:
```bash
# Monitor UART output (if configured)
screen /dev/tty.usbmodem* 115200

# Or use STM32CubeMonitor for real-time debugging
```

## 🎯 Production Flashing

For production environments:
```bash
# Batch flashing script
#!/bin/bash
echo "Production flash script"
make clean && make
STM32_Programmer_CLI -c port=SWD -e all
STM32_Programmer_CLI -c port=SWD -d wireless_stack.bin 0x080CB000
STM32_Programmer_CLI -c port=SWD -d build/stm32wb55_color.hex -rst
echo "Flash complete!"
```

## 📚 Additional Resources

- [STM32WB55 Reference Manual](https://www.st.com/resource/en/reference_manual/dm00434081.pdf)
- [STM32CubeProgrammer User Manual](https://www.st.com/resource/en/user_manual/dm00403500.pdf)
- [STM32WB Wireless Stack Documentation](https://www.st.com/resource/en/application_note/dm00550659.pdf)
- [OpenOCD STM32 Configuration](http://openocd.org/doc-release/html/Flash-Programming.html)

---

**Happy Flashing! 🚀** 