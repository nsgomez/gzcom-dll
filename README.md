# SimCity GZCOM DLL
Like the Extra Cheats DLL, this DLL is intended to be a GZCOM-compatible library which SimCity 4 loads and provides C++-fluent modders with an interface to control game functions. These game functions have yet to be discovered, though the first step would be getting this DLL to work.


# To-Do
As of the last commit, GZDllGetGZCOMDirector is callable by SimCity 4. The DLL instance returned is partially functional, and SimCity (somehow) appears to be able to cast the class instance to its own cGZDllCOMDirector type.

However, a call to **cRZCOMDllDirector::AddRef** causes the game to crash to desktop. On top of that, once the DLL becomes fully functional, it has to be tested to make sure the game does not crash from using it and that everything works as intended.

Multiple data types that Maxis defined are currently unknown and being researched, so some functions are using void pointers instead of proper classes, which may be causing the above issue as well.


Known Issues
=========
 * **When the DLL is dismounted,** SimCity 4 appears to close out/crash.
  * This is intended functionality while the DLL is being debugged to avoid going through the hassle of having to wait to close SC4. Go into dllmain.cpp and remove the ExitProcess line to avoid this.