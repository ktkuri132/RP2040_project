# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/ktkuru/Documents/Pico SDK v1.5.1/pico-sdk/tools/pioasm")
  file(MAKE_DIRECTORY "C:/Users/ktkuru/Documents/Pico SDK v1.5.1/pico-sdk/tools/pioasm")
endif()
file(MAKE_DIRECTORY
  "C:/Users/ktkuru/Desktop/RP2040_project/build/pioasm"
  "C:/Users/ktkuru/Desktop/RP2040_project/build/pico-sdk/src/rp2_common/tinyusb/pioasm"
  "C:/Users/ktkuru/Desktop/RP2040_project/build/pico-sdk/src/rp2_common/tinyusb/pioasm/tmp"
  "C:/Users/ktkuru/Desktop/RP2040_project/build/pico-sdk/src/rp2_common/tinyusb/pioasm/src/PioasmBuild-stamp"
  "C:/Users/ktkuru/Desktop/RP2040_project/build/pico-sdk/src/rp2_common/tinyusb/pioasm/src"
  "C:/Users/ktkuru/Desktop/RP2040_project/build/pico-sdk/src/rp2_common/tinyusb/pioasm/src/PioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/ktkuru/Desktop/RP2040_project/build/pico-sdk/src/rp2_common/tinyusb/pioasm/src/PioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/ktkuru/Desktop/RP2040_project/build/pico-sdk/src/rp2_common/tinyusb/pioasm/src/PioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
