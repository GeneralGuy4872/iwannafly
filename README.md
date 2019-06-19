Iwannafly
=========
*open world game and game engine written in C useing minimal propagating dependencies*

Requirements
------------

Libraries:

- C Standard Libraries
- ioctl joystick interface

- OpenGL / Mesa version with matrix stack
- GLX

- X11 Common Library
- X Toolkit
- X Athena Widgets

System:

- Display
- Keyboard
- Mouse
- A 3d graphics card
- Lots of RAM
- Xbox 360 controller (or equivilant device)

- Unix-like Operating System
- Xorg display server or compatible api
- ANSI-compatible Terminal Emulator (such as <CODE>xterm</CODE>)
- POSIX shell
- <CODE>make</CODE>
- C preprocessor with macro forward-calling
- C compiler with the ability to mix C99, C89, and K&R syntax

PLANNED PLATFORMS
-----------------

- Debian i686
- Arch32 i686
- Gentoo  x86
- NetBSD i386

Will add other systems if I get better hardware, Arch being paramount amoungst them

Right now my dev systems consist of a Netburst Celeron, a K7 with no ethernet (has rj45 and rs232 instead), and an early C2D laptop that only runs P6 kernels; all of which date from between the late 90s and mid 2000s with full compliment of parallel-PCI expansion bus, IDE drives, and "legacy" ports on the towers. (the K7 actually has an EISA slot for the graphics card!)

OTHER NOTES
-----------

At time of writing, while the project has not been test-compiled, several of the stranger practices in use have been tested in small programs, particularly the structures and macro functions. All things regarding OpenGL, however, particularly if the formats used to store vectors (struct {float x; float y; float z}) and matrixes (float[4][4]) are correct, are awaiting the first build to determine sink-or-swim, as are the use of const and volatile.

The heavy use of macro functions througout the project's code base stems from two seperate cases that necessitate their use. Firstly, macro functions are a good way to implement a subroutine or procedure (Fortran and Pascal use them extensively). Secondly, macro functions can accept, and in specific cases return, multiple types, where as functions proper can only accept and return as they are defined (think C++ overloading but better). There should be no gotos in the project currently, but I make no promises about the future regarding the use of branch jumps (<CODE>? goto sucess : goto failure</CODE> at the end of a line, derived from snobol) or a loop escape in extraordinary circumstanses; my third use of gotos is exactly duplicated by switch statements, so the latter has been deployed widely in their stead.

I am also in the process of changing <CODE>n = 0; while (n < nmax) {... n++}</CODE> loops to <CODE>for (n=0;n<nmax;n++) {}</CODE> loops, <CODE>if () {} else if () {} else {abort}</CODE> trees to <CODE>switch {... default : abort}</CODE> statements, and I'm playing around with a <CODE>for (n=1;n;n++) {switch n {... default : abort} if (suceed) {n = 0}}</CODE> loop that implements a cleaner if-elseif-else tree

While Xt/Xaw is considered an archaic library, I consider it the best choice for my application; It does what I need it to, It doesn't do stuff I don't need it to, and it is lightweight. Additionaly, it's avalibility in a system's package manager is practically guarunteed (being a build dependency for many old apps, such as the xtools and nethack), making porting across linux distos that much easier. It's age also makes drastic changes to the api highly improbable, decreacsing the risk of code rot due to upstream changes.
