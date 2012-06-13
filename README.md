# GZCOM-Dll
Like the Extra Cheats DLL, this DLL is intended to be a GZCOM-compatible library which SimCity 4 loads and provides C++-fluent modders with an interface to control game functions. These game functions have yet to be discovered, though the first step would be getting this DLL to work.


# To-Do
As of the last commit, GZDllGetGZCOMDirector is callable by SimCity 4. However, after attempting to get the GZCOM Director from the DLL twice, the DLL is dismounted.


Known Issues
=========
 * **When the DLL is dismounted,** SimCity 4 appears to close out/crash.
  * This is intended functionality while the DLL is being debugged to avoid going through the hassle of having to wait to close SC4. Go into dllmain.cpp and remove the ExitProcess line to avoid this.