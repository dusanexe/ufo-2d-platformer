<h2> ufo-2d-platformer </h2>
this game or app is created in C graphics using library graphics.h and it can be compiled for MS-DOS or Windows.

<h3> Compileing tutorial: </h3>
You need to install Code::blocks 16.01 first.
Than download WinBGIm 6.0 library for MingW 5.x.x at this site:
http://winbgim.codecutter.org/
Copy files in your Code::blocks MinGW folder
When u open Code::blocks 16.01 go to Settings>Compiler.. and click on 'Linker settings' tab.
There in 'Link libraries' find and add "libbgia.a" that you coped in MinGW earlier.
At 'Other linker options:' copy this:
-lbgi
-lgdi32
-lcomdlg32
-luuid
-loleaut32
-lole32

thats it, click 'ok'.

Open and compile the file 'UFO2DPlatformer.CPP'

This tutorial will work for Windows systems.

<h2>Screenshots</h2>

![Alt text](https://i.imgur.com/d946CN5.jpg "Optional title")

![Alt text](https://i.imgur.com/gUdqfYC.jpg "Optional title")
