# How to build

## Prerequisites

- GNU Makefile
- Python Version >=3.11
- Conan Version >=2.16
- Cmake Version >=3.25
- MSVC 2017 (or higher), G++9 (or higher), Clang++9 (or higher)

## Windows

### Installation of prerequisites

- Install Python:
  - `winget install -e --id Python.Python.3.11`
- Install Conan:
  - `pip install --user conan`
- Install Cmake:
  - `winget install -e --id Kitware.CMake`

### Build

From root dir

- Detect conan default profile:
  - `conan profile detect --force`
- Download dependencies:
  - `conan install . -s build_type=Release|Debug --output-folder=build --build=missing`
- Configure Cmake
  - `cmake -S . -B build`
- Build
  - `cmake --build . --config Release|Debug`

## Linux (Debian)
