git clean -x -d -f

cmake -G "Visual Studio 17 2022" -A Win32 -DCMAKE_BUILD_TYPE=Release -S . -B ./Build/Windows-x86
cmake --build ./Build/Windows-x86 --config Release -- /p:CharacterSet=Unicode
copy .\Build\Windows-x86\Platform\Port\TCP\Release\TrioMotion_UnifiedApi-TCP-Win32.dll .\Build\Output\.

cmake -G "Visual Studio 17 2022" -A x64 -DCMAKE_BUILD_TYPE=Release -S . -B ./Build/Windows-x64
cmake --build ./Build/Windows-x64 --config Release -- /p:CharacterSet=Unicode
copy .\Build\Windows-x64\Platform\Port\TCP\Release\TrioMotion_UnifiedApi-TCP-x64.dll .\Build\Output\.

exit /b 0
