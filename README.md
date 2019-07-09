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
- last failed build : 6 July 2019

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

OTHER NOTES
-----------

My progress has recently been derailed by a necisarry API change regarding struct heierarchy that will propagate throughout nearly every aspect of the project. Where I was planning on moving into debugging this month, I might be lucky to get back to the syntax checking stage this month instead.

A major point of confusion at present is proper initialization of structs and pointers to structs. Code is inconsistant between using the <CODE>struct</CODE> keyword and <CODE>typedef</CODE> aliases, and is also inconsistand about using C89 struct literals or C99 compound objects. The latter will be resolved by syntax necessity, with preference for the C89 style, but the former issue may or may not be resolved for some time, as the project has at present

The heavy use of macro functions througout the project's code base stems from two seperate cases that necessitate their use. Firstly, macro functions are a good way to implement a subroutine or procedure (Fortran and Pascal use them extensively). Secondly, macro functions can accept, and in specific cases return, multiple types, where as functions proper can only accept and return as they are defined (think C++ overloading but better). There should be no gotos in the project currently, but I make no promises about the future regarding the use of branch jumps (<CODE>? goto sucess : goto failure</CODE> at the end of a line, derived from snobol) or a loop escape in extraordinary circumstanses; my third use of gotos is exactly duplicated by switch statements, so the latter has been deployed widely in their stead.

While Xt+Xaw is considered an archaic library, I consider it the best choice for my application; It does what I need it to, It doesn't do stuff I don't need it to, and it is smaller and faster than anything that came after it, making it the ultimate lightweight graphics library (if you can manage to wrap your brain around it's API). Additionaly, it's avalibility in a system's package manager is practically guarunteed (being a build dependency for many old apps, such as the xtools and nethack), making porting across \*nix-es that much easier. It's age also makes drastic changes to the api highly improbable, decreacsing the risk of code rot due to upstream changes.

Opposite of usual, as currently laid out, the games memory footprint *should* nominally shrink as quests are compleated and the ascossiated event nodes are deallocated. now that I've said this, the opposite will likely be the case.

Note: Motorola Notation is used in game and in documentation, meaning that $n is a hexadecimal number and @n is an octal number (binary numbers would be %, but are not used). latitude and longitude are recorded as d\* m'. the symbol for currency shall be <CODE>\xA4</CODE>, which *must* display � in a unicode local, and displays ¤ (generic currency symbol) in most others.

LISCENSE?
---------
While I would like to release under LGPL or RevBSD, it likely inherits "GPLv2 or any later version" somewhere. I am not a lawyer (and generally dislike them showing up at my house with stacks of paper...), so I'll need to figure this out before Beta.
