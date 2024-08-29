param (
    [switch]$DEBUG = $false
)


if ($DEBUG) {
    $DEBUGS = "-DMKT_DEBUG"
    $DEBUGG = "-g"
} else {
    $DEBUGS = ""
    $DEBUGG = ""
}

gcc ./client/cleanup.c ./client/input.c ./client/MKTUtil.c ./client/init.c ./client/main.c C:/sdk/glad/src/glad.c $DEBUGS $DEBUGG -L C:/sdk/lib/ -I C:/sdk/freetype-windows-binaries/include -I C:\sdk\glad\include\KHR -I C:\sdk\glad\include -I C:\sdk\glfw-3.3.6\include\ -l opengl32 -l glfw3 -l gdi32 -o ./build/client/main.exe