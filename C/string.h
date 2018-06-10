// Copyright 2018 Daiki Yoshida
//
// This file is part of HyperLibrariesCollection.
//
// HyperLibrariesCollection is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// HyperLibrariesCollection is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with HyperLibrariesCollection. If not, see <http://www.gnu.org/licenses/>.

#ifndef HYPER_LIBRARIES_COLLECTION_C_STRING_H
#define HYPER_LIBRARIES_COLLECTION_C_STRING_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
	char* data;
	size_t size;
} *string;

void InitString(string s);
char* StringChar(const string s, char c);
bool CopyString(string dest, const char* source);
bool CatString(string dest, const char* source);
int StringCompare(const string s1, const string s2);
size_t StringLength(const string s);
char* StringString(const string s1, const string s2);
void FreeString(string s);

#endif
