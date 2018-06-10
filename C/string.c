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

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string.h"

void InitString(string s) {
	s->data = NULL;
	s->size = 0;
}

char* StringChar(const string s, char c) {
	return strchr(s->data, c);
}

bool CopyString(string dest, const char* source) {
	char* temp = malloc(sizeof(char) * (strlen(source) + 1));
	if(temp == NULL) {
		return false;
	}

	free(dest->data);
	dest->data = temp;
	dest->size = strlen(source);
	strcpy(dest->data, source);

	return true;
}

bool CatString(string dest, const char* source) {
	char* temp = realloc(dest->data, sizeof(char) * (strlen(dest->data) + strlen(source) + 1));
	if(temp == NULL) {
		return false;
	}

	dest->data = temp;
	dest->size = strlen(dest->data) + strlen(source);
	strcat(dest->data, source);

	return true;
}

int StringCompare(const string s1, const string s2) {
	return strcmp(s1->data, s2->data);
}

size_t StringLength(const string s) {
	return s->size;
}

char* StringString(const string s1, const string s2) {
	return strstr(s1->data, s2->data);
}

void FreeString(string s) {
	free(s->data);
	s->data = NULL;
	s->size = 0;
}
