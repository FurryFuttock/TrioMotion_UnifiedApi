cmake --build ./Build/Windows-x86 --config Release -- /p:CharacterSet=Unicode
>nul robocopy .\Build\Windows-x86\Platform\Port\TCP\Release\. .\Build\Output\. TrioMotion_UnifiedApi-TCP-Win32.dll

cmake --build ./Build/Windows-x64 --config Release -- /p:CharacterSet=Unicode
>nul robocopy .\Build\Windows-x64\Platform\Port\TCP\Release\. .\Build\Output\. TrioMotion_UnifiedApi-TCP-x64.dll

exit /b 0
