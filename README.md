# SimCity GZCOM DLL
Like the Extra Cheats DLL, this DLL is intended to be a GZCOM-compatible
library which SimCity 4 loads and provides C++-fluent modders with an
interface to control game functions.


# To-Do
As of the last commit, the DLL is callable by SimCity 4, and the DLL can call
into game functions including enabling debugging functionality (i.e. the extra
cheats DLL). The COM director instance is entirely functional, and is able to
subscribe to hook events like PreFrameWorkInit, PostAppInit, and the rest.

Since most of the core work is done, the rest of the effort is focused on
finding other classes and interfaces to add and fixing poorly documented
methods with unknown parameters.

# License

This project is licensed under the [GNU Lesser General Public License, version 2.1](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.en.html) or (at your option) any later version published by the Free Software Foundation.

You may dynamically link it with proprietary software such as SimCity 4, but changes you make to gzcom-dll must also be shared under the LGPL v2.1 license or later.