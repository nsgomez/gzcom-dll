#pragma once

template<typename T>
class SC4Rect
{
	public:
		SC4Rect()
			: topLeftX(0),
			  topLeftY(0),
			  bottomRightX(0),
			  bottomRightY(0)
		{
		}

		SC4Rect(T topLeftX, T topLeftY, T bottomRightX, T bottomRightY)
			: topLeftX(topLeftX),
			  topLeftY(topLeftY),
			  bottomRightX(bottomRightX),
			  bottomRightY(bottomRightY)
		{
		}

		SC4Rect(SC4Rect const& other)
		{
			this->topLeftX = other.topLeftX;
			this->topLeftY = other.topLeftY;
			this->bottomRightX = other.bottomRightX;
			this->bottomRightY = other.bottomRightY;
		}

		SC4Rect(SC4Rect&& other) noexcept
		{
			this->topLeftX = other.topLeftX;
			this->topLeftY = other.topLeftY;
			this->bottomRightX = other.bottomRightX;
			this->bottomRightY = other.bottomRightY;

			other.topLeftX = 0;
			other.topLeftY = 0;
			other.bottomRightX = 0;
			other.bottomRightY = 0;
		}


		SC4Rect& operator=(SC4Rect const& other)
		{
			this->topLeftX = other.topLeftX;
			this->topLeftY = other.topLeftY;
			this->bottomRightX = other.bottomRightX;
			this->bottomRightY = other.bottomRightY;

			return *this;
		}

		SC4Rect& operator=(SC4Rect&& other) noexcept
		{
			this->topLeftX = other.topLeftX;
			this->topLeftY = other.topLeftY;
			this->bottomRightX = other.bottomRightX;
			this->bottomRightY = other.bottomRightY;

			other.topLeftX = 0;
			other.topLeftY = 0;
			other.bottomRightX = 0;
			other.bottomRightY = 0;

			return *this;
		}

		T topLeftX;
		T topLeftY;
		T bottomRightX;
		T bottomRightY;
};