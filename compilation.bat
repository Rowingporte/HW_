@echo off

if not exist build mkdir build
cd build
cmake ..
cmake --build .

if exist Debug\executable.exe copy Debug\executable.exe ..

pause