#include "cS3DVector2.h"
#include <math.h>

float cS3DVector2::Length(void) {
	float fX2 = fX * fX;
	float fY2 = fY * fY;

	return sqrtf(fX2 + fY2);
}

cS3DVector2* cS3DVector2::Normalize(void) {
	float fLength = Length();
	float fMultiplier = 0.0f;

	if (fLength > 0.0f) {
		fMultiplier = 1 / fLength;
	}

	fX *= fMultiplier;
	fY *= fMultiplier;

	return this;
}

cS3DVector2* cS3DVector2::SetLength(float fNewLength) {
	float fLength = Length();
	if (fLength > 0.0f) {
		float fMultiplier = fNewLength / fLength;

		fX *= fMultiplier;
		fY *= fMultiplier;
	}

	return this;
}

bool cS3DVector2::operator!=(cS3DVector2 const& sOther) {
	return !(operator==(sOther));
}

bool cS3DVector2::operator==(cS3DVector2 const& sOther) {
	float fDiffX = (float)fabs(sOther.fX - fX);
	float fDiffY = (float)fabs(sOther.fY - fY);

	return fDiffX <= 0.0001 && fDiffY <= 0.0001;
}

cS3DVector2& cS3DVector2::operator/=(float fDivisor) {
	float fMultiplier = 1 / fDivisor;
	fX *= fMultiplier;
	fY *= fMultiplier;

	return *this;
}