// AtlImage.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "AtlImage.h"
#include "atlimage.h"
// This is an example of an exported function.
ATLIMAGE_API HBITMAP LoadAtlImage(const char * pFileName)
{

	CImage image;
	HRESULT hr=image.Load(pFileName);
	if (SUCCEEDED(hr))
	{
		return image.Detach();
	}
	else
	{
		return NULL;
	}
}
