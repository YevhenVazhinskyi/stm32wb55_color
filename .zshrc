export STM32CubeMX_PATH="/Applications/STMicroelectronics/STM32CubeMX.app/Contents/Resources"
export PATH="$HOME/Drivers/arm-gnu-toolchain-14.2.rel1-darwin-arm64-arm-none-eabi/bin:$PATH"

export PATH="$PATH:$HOME/Flutter/flutter/bin"
alias flash="-device STM32WB55CG -if SWD -speed 4000 -CommanderScript flash.jJLinkExe link"



