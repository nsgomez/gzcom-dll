/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cRZCellMap.cpp
 *
 * Copyright (C) 2024 Nicholas Hayes
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, under
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <https://www.gnu.org/licenses/>.
 */

#include "cRZCellMap.h"

cRZCellMap::cRZCellMap(uint32_t rows, uint32_t columns, bool value)
	: data(nullptr)
{
	this->rows = rows;
	this->columns = columns;
	this->columnIntegerCount = columns / 32;
	if ((columns & 31) != 0)
	{
		// Add another integer to hold the remaining data.
		this->columnIntegerCount++;
	}

	this->data = new uint32_t*[rows];
	for (uint32_t i = 0; i < rows; i++)
	{
		this->data[i] = new uint32_t[this->columnIntegerCount];
	}

	const uint32_t initialValue = value ? 0xffffffff : 0;

	for (uint32_t x = 0; x < rows; x++)
	{
		uint32_t* row = data[x];

		for (uint32_t y = 0; y < columnIntegerCount; y++)
		{
			row[y] = initialValue;
		}
	}
}

cRZCellMap::cRZCellMap(cRZCellMap const& other)
{
	this->rows = other.rows;
	this->columns = other.columns;
	this->columnIntegerCount = other.columnIntegerCount;

	this->data = new uint32_t*[rows];
	for (uint32_t i = 0; i < rows; i++)
	{
		this->data[i] = new uint32_t[this->columnIntegerCount];
	}

	for (uint32_t x = 0; x < rows; x++)
	{
		for (uint32_t y = 0; y < columns; y++)
		{
			SetValue(x, y, other.GetValue(x, y));
		}
	}
}

cRZCellMap::cRZCellMap(cRZCellMap&& other) noexcept
	: rows(0),
	  columns(0),
	  columnIntegerCount(0),
	  data(nullptr)
{
	this->rows = other.rows;
	this->columns = other.columns;
	this->columnIntegerCount = other.columnIntegerCount;
	this->data = other.data;

	other.rows = 0;
	other.columns = 0;
	other.columnIntegerCount = 0;
	other.data = nullptr;
}

cRZCellMap& cRZCellMap::operator=(cRZCellMap const& other)
{
	DestroyData();

	this->rows = other.rows;
	this->columns = other.columns;
	this->columnIntegerCount = other.columnIntegerCount;

	this->data = new uint32_t*[rows];
	for (uint32_t i = 0; i < rows; i++)
	{
		this->data[i] = new uint32_t[this->columnIntegerCount];
	}

	for (uint32_t x = 0; x < rows; x++)
	{
		for (uint32_t y = 0; y < columns; y++)
		{
			SetValue(x, y, other.GetValue(x, y));
		}
	}

	return *this;
}

cRZCellMap& cRZCellMap::operator=(cRZCellMap&& other) noexcept
{
	this->rows = other.rows;
	this->columns = other.columns;
	this->columnIntegerCount = other.columnIntegerCount;
	this->data = other.data;

	other.rows = 0;
	other.columns = 0;
	other.columnIntegerCount = 0;
	other.data = nullptr;

	return *this;
}

cRZCellMap::~cRZCellMap()
{
	DestroyData();
}

bool cRZCellMap::GetValue(uint32_t row, uint32_t column) const
{
	return (this->data[row][column / 32] & (1 << (column & 31))) != 0;
}

void cRZCellMap::SetValue(uint32_t row, uint32_t column, bool value)
{
	if (value)
	{
		this->data[row][column / 32] |= (1 << (column & 31));
	}
	else
	{
		this->data[row][column / 32] &= ~(1 << (column & 31));
	}
}

void cRZCellMap::DestroyData()
{
	if (this->data)
	{
		for (uint32_t i = 0; i < rows; i++)
		{
			delete[] data[i];
		}

		delete[] data;
		data = nullptr;
	}
}
