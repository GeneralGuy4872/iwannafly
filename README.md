**prealpha stats:**
- 🗹 outline
- 🗹 implementation
- ➤ *syntax fixing*
- ⌛ debugging
- ⌛ alpha release

**build stats:**
- last working build : NULL
	- 0 total
- last segfault build : NULL
	- 0 total
- last failed build : 8 July 2019

Iwannafly
=========
*open world game and game engine written in C useing minimal propagating dependencies*

Requirements
------------

Libraries:

- C Standard Libraries

- OpenGL / Mesa version with matrix stack
- GLX

- X11 Common Library
- X Toolkit
- X Athena Widgets

System:

- Display
- Keyboard
- A 3d graphics card; shader support shouldn't be required
- Ludicrous amounts of ram (current estimates upwards of a GiB)
- Xbox 360-style controler, located at <CODE>/dev/input/js0</CODE>

- Unix-like Operating System
- active X Session
- <CODE>xterm</CODE> or other ANSI-compatible Terminal Emulator
- <CODE>make</CODE>
- C preprocessor with macro forward-calling
- Actual C compiler with full C99, C89, and K&R support
- sane POSIX enviroment

PLANNED PLATFORMS
-----------------

- Debian i686
- Arch32 i686
- Gentoo  x86
- NetBSD i386

Will add other systems if I get better hardware, Arch64 being paramount amoungst them

Right now my dev systems consist of a Netburst Celeron, a K7 with no ethernet (has rj45 and rs232 instead), and an early C2D laptop that only runs P6 kernels; all of which date from between the late 90s and mid 2000s with full compliment of parallel-PCI expansion bus, IDE drives, and "legacy" ports on the towers. (the K7 actually has an EISA slot for the graphics card!)

NEWS AND OTHER NOTES
--------------------

I think I have the use of C89 struct literals and C99 compound literals figured out, but still see no difference between struct types and typedef aliases. after some tests, the aliases may be going away

While Xt+Xaw is considered an archaic library, I consider it the best choice for my application; It does what I need it to, It doesn't do stuff I don't need it to, and it is smaller and faster than anything that came after it, making it the ultimate lightweight graphics library (if you can manage to wrap your brain around it's API). Additionaly, it's avalibility in a system's package manager is practically guarunteed (being a build dependency for many old apps, such as the xtools and nethack), making porting across \*nix-es that much easier. It's age also makes drastic changes to the api highly improbable, decreacsing the risk of code rot due to upstream changes.

Opposite of usual, as currently laid out, the games memory footprint *should* nominally shrink as quests are compleated and the ascossiated event nodes are deallocated. now that I've said this, the opposite will likely be the case.

While I have moved away from <CODE>goto</CODE>s, one side-effect is that I now use too many <CODE>switch</CODE> statements. Also be aware that macros are used heavily.

Note: Motorola Notation is used in game and in documentation, meaning that $n is a hexadecimal number and @n is an octal number (binary numbers would be %, but are not used). latitude and longitude are recorded as d\* m'. the symbol for currency shall be <CODE>\xA4</CODE>, which displays � in a unicode local, or displays ¤ (generic currency symbol) in most others.

LISCENSE?
---------
While I would like to release under LGPL or RevBSD, it likely inherits "GPLv2 or any later version" somewhere. I am not a lawyer (and generally dislike them showing up at my house with stacks of paper...), so I'll need to figure this out before Beta.
