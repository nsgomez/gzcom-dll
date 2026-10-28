/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * ilist.h
 *
 * Copyright (C) 2016 Nelson Gomez
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

#pragma once
#include "cGZAllocatorServiceSTLAllocator.h"
#include <list>

// A plugin-side list that allocates through the game's allocator service.
// Its layout is the compiler's std::list, not the STLport list the game was
// built with, so never pass one to a game function. Use SC4List for that.
template<typename T>
using ilist = std::list<T, cGZAllocatorServiceSTLAllocator<T>>;