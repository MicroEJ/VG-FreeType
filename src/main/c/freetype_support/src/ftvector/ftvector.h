/*
 * C
 *
 * Copyright 2019-2026 MicroEJ Corp. This file has been modified and/or created by MicroEJ Corp.
 *
 * This file is part of the FreeType project, and may only be used,
 * modified, and distributed under the terms of the FreeType project
 * license, LICENSE.TXT.  By continuing to use, modify, or distribute
 * this file you indicate that you have read the license and
 * understand and accept it fully.
 *
 * Build: 7E4D1F7C
 */

/**
 * @file
 * @brief Freetype renderer
 * @author MicroEJ Developer Team
 * @version 5.0.5
 */

#ifndef FTVECTOR_H
#define FTVECTOR_H

#include "vg_configuration.h"

#if defined VG_FEATURE_FONT && (VG_FEATURE_FONT == VG_FEATURE_FONT_FREETYPE_VECTOR)

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------

#include "vg_freetype.h"

// --------------------------------------------------------------------------------
// Defines
// --------------------------------------------------------------------------------

/**
 * @brief The render mode tag that gives the renderer its FTVECTOR_draw_glyph_data_t.
 */
#define FT_PARAM_TAG_DRAWER     FT_MAKE_TAG('d', 'r', 'a', 'w')

// --------------------------------------------------------------------------------
// Typedef
// --------------------------------------------------------------------------------

/**
 * @brief The data of the function VG_FREETYPE_draw_glyph_t
 */
typedef struct {
	VG_FREETYPE_draw_glyph_t drawer; /**< The function that draws each glyph. */
	jfloat *matrix; /**< The deformation to apply on the path of each glyph. */
	uint32_t color; /**< The color to draw the glyphs with. */
	void *user_data; /**< The custom drawer data (may be null). */
	jint destination_error; /**< the drawer's error, or LLVG_SUCCESS while it has accepted every glyph */
} FTVECTOR_draw_glyph_data_t;

#endif // defined VG_FEATURE_FONT && (VG_FEATURE_FONT == VG_FEATURE_FONT_FREETYPE_VECTOR)

#endif // FTVECTOR_H
