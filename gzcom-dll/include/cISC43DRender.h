#pragma once
#include "cIGZUnknown.h"

class cIGZBuffer;
class cIGZGDriver;
class cIGZGraphicSystem2;
class cIGZString;
class cIS3DModelInstance;
class cISC4OccupantFilter;
class cISC4ViewObject3D;
class cRZRect;
class cS3DBoundingBox;
class cS3DCamera;
class cS3DVector2;
class cSC4CameraControl;
class cSC4ShakeDescription;
class SC43DGridElement;

class cISC43DRender : public cIGZUnknown
{
	public:
		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual bool SetMapScaleFactor(int32_t) = 0;
		virtual bool SetGraphicSystem(cIGZGraphicSystem2*) = 0;
		virtual bool SetGDriver(cIGZGDriver*) = 0;

		virtual intptr_t GetViewUtilities(void) = 0;
		virtual intptr_t GetLightingManager(void) = 0;
		virtual intptr_t GetDrawContext(void) = 0;
		
		virtual bool GetViewportSize(uint32_t& nX, uint32_t& nZ) = 0;
		virtual bool SetViewportSize(uint32_t nX, uint32_t nZ) = 0;
		virtual bool SetSubpixelImageBias(float, float) = 0;

		virtual cS3DCamera* GetCamera(void) = 0;
		virtual bool SetCamera(cS3DCamera* pCamera) = 0;

		virtual cSC4CameraControl* GetCameraControl(void) = 0;
		virtual bool SetCameraControl(cSC4CameraControl* pControl) = 0;

		virtual intptr_t GetProjectionMatrixEntries(void) = 0;
		virtual intptr_t GetViewMatrixEntities(void) = 0;

		virtual bool ForceFullRedraw(void) = 0;
		virtual bool Draw(void) = 0;

		virtual bool TakeSnapshot(cIGZBuffer**, bool) = 0;
		virtual bool TakeSnapshot(cIGZString&, bool) = 0;

		virtual bool Set3DCameraView(void) = 0;
		virtual bool Set2DCameraView(void) = 0;
		virtual bool SetUICameraView(void) = 0;

		virtual bool IsModelInserted(cIS3DModelInstance* pModel) = 0;
		virtual bool InsertModel(cIS3DModelInstance* pModel) = 0;
		virtual bool RemoveModel(cIS3DModelInstance* pModel) = 0;
		virtual bool MoveModel(cIS3DModelInstance* pModel) = 0;
		virtual bool ChangeModel(cIS3DModelInstance* pModel, int32_t) = 0;

		virtual bool AddViewObject(cISC4ViewObject3D*, int32_t, uint32_t) = 0;
		virtual bool RemoveViewObject(cISC4ViewObject3D*) = 0;
		virtual bool FindViewObject(cISC4ViewObject3D*) = 0;

		virtual bool SetZoom(int32_t nZoomLevel) = 0;
		virtual bool ZoomIn(void) = 0;
		virtual bool ZoomOut(void) = 0;

		virtual bool SetRotation(int32_t nZoomLevel) = 0;
		virtual bool RotateLeft(void) = 0;
		virtual bool RotateRight(void) = 0;

		virtual bool SetZoomAndRotation(int nZoom, int nRotation) = 0;

		virtual bool StartScreenShake(float fIntensityX, float fIntensityZ) = 0;
		virtual bool StartScreenShake(cSC4ShakeDescription const&, cS3DVector2 const*) = 0;
		virtual bool StopScreenShake(uint32_t nFadeTime) = 0;
		virtual bool GetShakeOffsets(float& fX, float& fZ) = 0;

		virtual bool SetViewportClearColor(float const*) = 0;
		virtual bool ClearViewport(bool) = 0;
		virtual bool ClearViewportWithSolidColor(float const*, bool, bool) = 0;
		virtual bool DrawViewportRectangle(cRZRect const&, float const*, bool, bool) = 0;
		virtual bool DrawTexturedViewportRectangle(cRZRect const&, uint32_t, float, bool, bool) = 0;

		virtual bool EnableBackgroundPicture(bool bEnable) = 0;
		virtual uint32_t GetBackgroundPicture(bool* bEnabled) = 0;
		virtual bool SetBackgroundPicture(cIGZBuffer*, bool) = 0;
		virtual bool SetBackgroundPicture(uint32_t, int32_t, int32_t, bool) = 0;
		virtual bool EnableTransparentBackground(bool) = 0;

		virtual bool GetBackingStoreEnabled(void) = 0;
		virtual bool SetBackingStoreEnabled(bool bEnabled) = 0;

		virtual bool BorrowRenderSystem(void) = 0;
		virtual bool ReturnRenderSystem(void) = 0;

		virtual bool PickTerrain(float const*, float const*, float*, bool, bool) = 0;
		virtual bool PickTerrain(int32_t, int32_t, float*, bool, bool) = 0;

		virtual bool PickTerrainAlways(float const*, float const*, float*, bool) = 0;
		virtual bool PickTerrainAlways(int32_t, int32_t, float*, bool) = 0;

		virtual bool Pick(int32_t, int32_t, cISC4OccupantFilter*, cIS3DModelInstance*&) = 0;
		virtual bool Pick(int32_t, int32_t, float const*, float const*, cISC4OccupantFilter*, cIS3DModelInstance*&) = 0;

		virtual bool GetModelsInVolume(cS3DBoundingBox const&, cIS3DModelInstance**, uint32_t&) = 0;
		virtual bool IsModelVisible(cIS3DModelInstance*, int32_t nFrustumType) = 0;
		virtual bool IsModelVisible(SC43DGridElement*, int32_t nFrustumType) = 0;
		
		virtual bool GetViewFogEnabled(void) = 0;
		virtual bool SetViewFogEnabled(bool bEnabled) = 0;

		virtual bool GetLightingEnabled(void) = 0;
		virtual bool SetLightingEnabled(bool bEnabled) = 0;

		virtual bool GetStatsString1(cIGZString& sDataOut) = 0;
		virtual bool GetStatsString2(cIGZString& sDataOut) = 0;
};