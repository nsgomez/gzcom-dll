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


Known Issues
=========
* None so far

# Third Party Components

[EABase](https://github.com/electronicarts/EABase) - BSD 3-Clause License.    
[EASTL](https://github.com/electronicarts/EASTL) - BSD 3-Clause License.    