#pragma once

class cS3DVector2
{
	public:
		cS3DVector2(void) {
			fX = 0.0f;
			fY = 0.0f;
		}

		cS3DVector2(float fValue) {
			fX = fValue;
			fY = fValue;
		}

		cS3DVector2(float fX, float fY) {
			this->fX = fX;
			this->fY = fY;
		}

		float Length(void);
		cS3DVector2* Normalize(void);
		cS3DVector2* SetLength(float fNewLength);

		bool operator!=(cS3DVector2 const& sOther);
		bool operator==(cS3DVector2 const& sOther);

		cS3DVector2& operator/=(float fDivisor);

	public:
		float fX, fY;
};