
To run do the following

ctrl shift b (to build)

f5 (to run)

===================================================================
Download https://visualstudio.microsoft.com/visual-cpp-build-tools/

Select Windows application cpp (Top Left)

Do not change check boxes press install

You can view these on Developer command prompt now as you should be able to input commands into it.

After you do this in the directory C:\Program Files (x86)\Microsoft Visual Studio you will find vcvars by searching vcvars

Right click it and open file location

find that same file and right click and copy its path
"C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"

Afterwards we do this in the build.bat

===================================================================

Check if vulkan is installed by doing this in the command prompt
C:\Users\camde>echo %VULKAN_SDK%

Here is my location for the vulkan sdk
C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Vulkan SDK 1.3.296.0

Vulkan download link: https://vulkan.lunarg.com/sdk/home

====================================================================

IF Vulkan not detected by vscode
run %appdata%
goto code/user/settings.json
locate this VVVV
"C_Cpp.default.includePath": [
        "${workspaceFolder}/src", <-- Add this
        "${VULKAN_SDK}/Include",  <-- Add this