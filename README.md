# SimCity GZCOM DLL
Like the Extra Cheats DLL, this DLL is intended to be a GZCOM-compatible
library which SimCity 4 loads and provides C++-fluent modders with an
interface to control game functions. These game functions have yet to be
discovered, though the first step would be getting this DLL to work.


# To-Do
As of the last commit, GZDllGetGZCOMDirector is callable by SimCity 4. The COM
director instance is almost entirely functional, and the DLL is able to even
subscribe to hook events like PreFrameWorkInit, PostAppInit, and the rest.

The game ultimately crashes due to an access violation exception which may
have to do with the class layout.

Scaffolding classes have been added for a few Rizzo/Gonzo interfaces in order
for the plugin to work, but cRZDummyString is basically malicious in how it
does so and a lot of these should be avoided for the most part. Comments are
at the top of each class indicating to what degree of screwed they are.


Known Issues
=========
* The DLL crashes.