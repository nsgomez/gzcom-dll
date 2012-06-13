///////////////////////////////////////////////////////////////////////////////
// EmptyPluginCOMDirector.cpp
//
//
// Copyright (c) 2000 Maxis, Inc. -- All Rights Reserved World Wide.
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Include files
//
#ifndef IGZFRAMEWORK_H
   #include <IGZFrameWork.h>
#endif
#ifndef RZCOMDIRECTOR_H
   #include <RZCOMDirector.h>
#endif
#ifndef IGZSYSSER_H
   #include <IGZSysSer.h>
#endif




/////////////////////////////////////////////////////////////////////////////
// Constants
//
static const GZGUID kEmptyPluginCOMDirectorDirectorID = 0x06dcbef1;
static const GZGUID kGZCLSID_cSomeObject              = 0x46dcc1fc;



/////////////////////////////////////////////////////////////////////////////
// cGZEmptyPluginCOMDirector
//
class cGZEmptyPluginCOMDirector : public cRZCOMDllDirector{
public:
	cGZEmptyPluginCOMDirector(){ 
	   //Initialize variables here.

      //Here we demonstrate the code to create an object with this 
      //COM director. Someone makes a call to GZCOM::GetClassObject
      //and we can sarisfy the request if the CLSID they request 
      //matches the one we have here.
      AddCls(kGZCLSID_cSomeObject, CreateSomeObject); 

      //Here we demonstrate adding a class we create as a system
      //service. You don't have to do this, but sometimes people
      //want to do this. All this code is commented out at this 
      //time simplly because we don't really want to add anything.
		//cIGZSystemService* pSomeSystemService = new cSomeSystemService;
		//pSomeSystemService->AddRef();
      //RZGetFramework()->AddSystemService(pRM);
      //pSomeSystemService->Release();
   }

	virtual ~cGZEmptyPluginCOMDirector(){
	   //Possibly do something here. Be careful -- everything but the 
      //operating system itself is dead by the time this code is executed.
   }

	GZGUID GetDirectorID() const{ 
      return kEmptyPluginCOMDirectorDirectorID;
   }

	bool OnStart(cIGZCOM* pCOM){
      //This function gets called automatically by the framework after 
      //loading this dynamic library.
		//Register for callbacks. By calling this function, we tell the 
      //framework that we'll want to have PreFrameWorkInit(), PreAppInit(),
      //and other functions below called.
		RZGetFrameWork()->AddHook(static_cast<cIGZFrameWorkHooks*>(this));
		return true;
	}

   bool PreFrameWorkInit(){
	   //Called prior to any framework and system service initialization. 
      //All dlls have been loaded and have executed OnStart().
		//Possibly do stuff here.
		return true;
   }

   bool PreAppInit(){
	   //Called after framework initialization and prior to application init call.
		//Possibly do stuff here.
		return true;
   }

   bool PostAppInit(){
	   //Called after the app has initialized.
		//Possibly do stuff here.
		return true;
   }

   bool PreAppShutdown(){
	   //Called immediately prior to the applications.
		//Possibly do stuff here.
		return true;
   }

   bool PostAppShutdown(){
	   // Called prior to framework shutdown but after application shutdown
		//Possibly do stuff here.
		return true;
   }

   static cIGZUnknown* CreateSomeObject(){
      cIGZUnknown* pUnknown = NULL;
      //pUnknown = static_cast<cIGZUnknown*>(new cSomeClass); //Commented out because we don't actually have 
      return pUnknown;                                        //any such class at this time. 
   }

protected:
	//Declare variables here.
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// cGZEmptyPluginCOMDirector
//
cRZCOMDllDirector* RZGetCOMDllDirector(){
   static cGZEmptyPluginCOMDirector sDirector;
   return &sDirector;
}