#pragma once
#include <credentialprovider.h>
#include <ntsecapi.h>
#define SECURITY_WIN32
#include <security.h>
#include <intsafe.h>

#define MAX_ULONG  ((ULONG)(-1))


enum SAMPLE_FIELD_ID 
{
	SFI_TILEIMAGE		= 0,
	SFI_TITLE			= 1,
	SFI_DETAILS			= 2, 
	SFI_MINIDETAILS		= 3,
	SFI_NUM_FIELDS		= 4,
};

struct FIELD_STATE_PAIR
{
	CREDENTIAL_PROVIDER_FIELD_STATE cpfs;
	CREDENTIAL_PROVIDER_FIELD_INTERACTIVE_STATE cpfis;
};

static const FIELD_STATE_PAIR s_rgFieldStatePairs[] = 
{
	{ CPFS_DISPLAY_IN_BOTH,					CPFIS_NONE    }, // SFI_TILEIMAGE
	{ CPFS_DISPLAY_IN_BOTH,					CPFIS_NONE    }, // SFI_TITLE
	{ CPFS_DISPLAY_IN_SELECTED_TILE,		CPFIS_NONE    }, // SFI_DETAILS
	{ CPFS_DISPLAY_IN_DESELECTED_TILE,		CPFIS_NONE    }, // SFI_MINIDETAILS
};

static const CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR s_rgCredProvFieldDescriptors[] =
{
	{ SFI_TILEIMAGE,		CPFT_TILE_IMAGE,	L"Image"		}, // SFI_TILEIMAGE
	{ SFI_TITLE,			CPFT_LARGE_TEXT,	L"Title"		}, // SFI_TITLE
	{ SFI_DETAILS,			CPFT_SMALL_TEXT,	L"Details"		}, // SFI_DETAILS
	{ SFI_MINIDETAILS,		CPFT_SMALL_TEXT,	L"Mini Details"	}, // SFI_MINIDETAILS
};