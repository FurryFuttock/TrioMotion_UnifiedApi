git clean -x -d -f
cmake -G "Visual Studio 17 2022" -A Win32 -S . -B ./Build/Windows-x86
cmake -G "Visual Studio 17 2022" -A x64 -S . -B ./Build/Windows-x64

call BuildMe.bat

exit /b 0
