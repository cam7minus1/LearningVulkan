@echo off

setlocal enabledelayedexpansion

call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"

SET includes=/Isrc ^
            /I"Header Files" ^
            /I%VULKAN_SDK%/include ^
            /I..\externals\GLFW\include ^
            /I..\externals\GLM

SET links=/link ^
    /LIBPATH:%VULKAN_SDK%\Lib ^
    /LIBPATH:..\externals\GLFW\lib-vc2022 ^
    vulkan-1.lib ^
    glfw3.lib ^
    user32.lib ^
    gdi32.lib ^
    shell32.lib

SET defines=/DDEBUG

REM Collect all .cpp files in src folder
set files=
for %%f in (src\*.cpp) do (
    set files=!files! %%f
)

REM Build all collected .cpp files
cl /EHsc /MD %includes% %defines% !files! /out:main.exe %links%

