class cSC4ExtraCheatsPluginCOMDirector : public cRZCOMDllDirector{
public:
    GZGUID GetDirectorID() const{
      return kExtraCheatsPluginCOMDirectorDirectorID;
   }

   bool ShouldEnable(){
      // As of October 2006, we have decided to enable this plugin for all uses.

      /*
      bool bReturnValue(false);

      //Do a time check.
      if(cRZDate() < cRZDate(12, 25, 2003))
         bReturnValue = true;

      //Do a network address check.
      if(!bReturnValue){
         cRZINetSocketAddress socketAddress;

         if(cRZINetSocketAddress::GetThisMachinesAddressStatic(socketAddress)){
            cRZString sAddress((RZChar)0, 32);

            if(socketAddress.ConvertAddressToStringDottedDecimal(socketAddress.GetNetworkAddress(), &sAddress[0])){
               if(sAddress.find("10.24.") == 0) //All Maxis IP addresses start with this.
                  bReturnValue = true;
               if(sAddress.find("10.14.") == 0) //All Electronic Arts Redwood shores IP addresses start with this.
                  bReturnValue = true;
            }
         }
      }

      return bReturnValue;
      */
   }

   bool PreAppInit(){
      cIGZFramework* const pFramework = RZGetFrameWork();
      if(pFramework){
         cIGZApp* const pApp = pFramework->Application();
         if(pApp){
            cRZAutoRefCount<cISC4App> pISC4App;
            if(pApp->QueryInterface(kGZIID_cISC4App, pISC4App.AsPPVoidParam()))
               pISC4App->SetDebugFunctionalityEnabled(true);
         }
      }
      return true;
   }

    bool OnStart(cIGZCOM* pCOM){
      if(ShouldEnable()){
         cIGZFramework* const pFramework = RZGetFrameWork();
         if(pFramework){
            if(pFramework->GetState() < cIGZFramework::kStatePreAppInit)
                 pFramework->AddHook(this);
              else
               PreAppInit();
         }
         return true;
      }
      return false;
    }
};