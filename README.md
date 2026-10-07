# Overview

This C Module integrates FreeType, the font rasterizer, in a VEE Port that uses the MicroVG Abstraction Layer to draw vector fonts.

It also includes some features for compatibility with the MicroVG Abstraction Layer:

 * It adds some wrappers to simplify the library compilation.
 * It is fully generic and does not require additional code specific to a GPU.
 * It uses the MicroVG Low Level API, described in [LLVG_FONT: Vector Font](https://docs.microej.com/en/latest/VEEPortingGuide/appendix/llapi.html#llvg-font-vector-font), to create and render the paths of the glyphs.

See [C Module: FreeType](https://docs.microej.com/en/latest/VEEPortingGuide/vgCco.html#section-vg-c-module-freetype) in the MicroEJ documentation.

This C Module is tied to the MicroEJ VG Pack: the versions it is compatible with are listed in the [compatibility](https://docs.microej.com/en/latest/VEEPortingGuide/vgReleaseNotes.html#c-modules-compatibility-version) tables of the documentation.

# Usage

1. Add the sources of this C Module to the BSP of the VEE Port, in either of these two ways:

   - From the MicroEJ repository: install the `.cco` archive of the version the VEE Port needs, as the [installation guide](https://docs.microej.com/en/latest/VEEPortingGuide/appendix/cmodules.html) describes.
     The archive holds the FreeType source, with the patches of this C Module applied, in `bsp/thirdparty/freetype`, and the support files in `bsp/freetype_support`.
   - From GitHub: add the [GitHub repository](https://github.com/MicroEJ/VG-FreeType) to the BSP of the VEE Port as a git submodule, at the tag of the version the VEE Port needs.
     The repository holds the support files only, in `<folder>/src/main/c/freetype_support`, where `<folder>` is the folder of the submodule.
     Get the FreeType source at the tag `VER-2-14-1` in `<folder>/src/main/c/thirdparty/freetype`, the folder the support files expect, then apply the patches of this C Module to it:

     ```sh
     git submodule add https://github.com/MicroEJ/VG-FreeType.git bsp/vee/port/vg/VG-FreeType
     git -C bsp/vee/port/vg/VG-FreeType checkout <version>
     git clone --branch VER-2-14-1 https://gitlab.freedesktop.org/freetype/freetype.git bsp/vee/port/vg/VG-FreeType/src/main/c/thirdparty/freetype
     git -C bsp/vee/port/vg/VG-FreeType/src/main/c/thirdparty/freetype apply ../../freetype_support/options.patch
     git -C bsp/vee/port/vg/VG-FreeType/src/main/c/thirdparty/freetype apply ../../freetype_support/psintrp.c.patch
     ```

     A copy of these sources in the VEE Port repository works as well.

   In the next steps, `<c>` is the folder that holds `freetype_support` and `thirdparty`: `bsp` for the archive, and `<folder>/src/main/c` for the GitHub repository.

2. From `<c>/freetype_support/src/wrappers`, add all c files to the list of compiled files.
3. Add these folders to your include directories list:
	* `<c>/thirdparty/freetype/include`
	* `<c>/thirdparty/freetype/src`
	* `<c>/freetype_support/src`
4. Add `FT_CONFIG_MODULES_H=<freetype/config/ftmodule.h>` define to the project.
5. Add `FT2_BUILD_LIBRARY` define to the project.
6. Build the project.

# Requirements

None.

# Validation

This C Module is tested with the MicroVG Abstraction Layer on the following boards:

- MIMXRT595-EVK.
- STM32U5G9J-DK2.
- Linux.

# MISRA Compliance

The support files, in `freetype_support`, of this C Module are MISRA-compliant (MISRA C:2012) with some noted exceptions.
The FreeType sources are not checked.
They have been verified with Cppcheck v2.19.
Here is the list of deviations from the MISRA standard:

| Deviation  | Category  | Justification |
|:----------:|:---------:|:------------- |
| Rule 5.9   | Advisory  | The same static function name can be used in several C files. |
| Rule 8.4   | Required  | The `FT_DEFINE_RASTER_FUNCS` and `FT_DEFINE_RENDERER` macros of FreeType define objects that FreeType declares. |
| Rule 8.9   | Advisory  | The `FT_DEFINE_OUTLINE_FUNCS` macro of FreeType defines its object at file scope. |
| Rule 10.1  | Required  | The coordinates of FreeType are signed 26.6 fixed-point values, shifted right to get whole pixels, as FreeType does. |
| Rule 11.3  | Required  | The `FT_MODULE_LIBRARY` macro of FreeType casts a renderer to its module structure. |
| Rule 11.4  | Advisory  | The `FT_DEFINE_RASTER_FUNCS` and `FT_DEFINE_RENDERER` macros of FreeType convert between pointers and integers. |
| Rule 17.3  | Mandatory | The implicitly declared functions are the VG Pack's functions. |

# Dependencies

- The MicroVG Abstraction Layer.

# Changelog

The changes of this C Module are listed in the [public changelog of the MicroEJ VG Pack](https://docs.microej.com/en/latest/VEEPortingGuide/vgChangeLog.html), section `C Module FreeType`.

# Source

- `thirdparty/freetype`: the FreeType sources, in the `.cco` archive only.
- `freetype_support/options.patch`, `freetype_support/psintrp.c.patch`: the patches of this C Module to the FreeType sources.
- `freetype_support/src/wrappers`: the wrappers that compile FreeType.
- `freetype_support/src/ftvector`: the FreeType renderer that draws a glyph with the MicroVG Low Level API.
- `freetype_support/src/ftmemory`: the memory functions of FreeType.

# Restrictions

None.

---
_Copyright 2021-2026 MicroEJ Corp. This file has been modified and/or created by MicroEJ Corp._

_This file is part of the FreeType project, and may only be used,_\
_modified, and distributed under the terms of the FreeType project_\
_license, LICENSE.TXT.  By continuing to use, modify, or distribute_\
_this file you indicate that you have read the license and_\
_understand and accept it fully._\
_Build: 7E4D1F7C_
