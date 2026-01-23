
# Overview

MicroEJ C Component: `freetype`, a fork of Freetype 2.13.3.

This C module also includes some functionalities to be compatilble with the C module MicroVG:

 * It adds some wrappers to simplify the library compilation.
 * It is fully generic and does not require additional code specific to a GPU.
 * It uses the MicroVG Low-Level API to dynamically create and render the paths of the glyphs.

# Build C Module

These files are updated thanks .patch files:
- /include/freetype/config/ftmodule.h
- /include/freetype/config/ftoption.h
- /src/psaux/psintrp.c

## Instructions for Freetype Patch Management (when updating Freetype)

1. **Verify File Modifications**: Check if the Freetype community has modified these files.
2. **Patch File Usage**: 
   - If there are no modifications, proceed with the patch files (go to step 10).
3. **Assess Version Differences**: 
   - If modifications exist, compare both versions. Attempt to build the CCO locally.
4. **File Comparison**: 
   - Compare the original Freetype files with the generated files located at `target~/ccomponentWorking/bsp/thirdparty/freetype` to confirm if the MicroEJ modifications (patch) are integrated into the CCO.
5. **Patch File Confirmation**: 
   - If the modifications are present, continue using the patch files.
6. **Patch File Removal**: 
   - If the modifications are not present, remove the patch files (refer to `module.ant`) and proceed with the rebuild.
7. **Manual Modifications**: Apply the necessary modifications manually.
8. **Regenerate Patch Files**: Create new patch files to reflect the recent modifications.
9. **Full Build Testing**: Conduct a complete build test.
10. **Update Copyright Year**: Amend the patch files to update the MicroEJ copyright year.

# Usage

Add the following line to your `module.ivy`:

    <dependency org="com.microej.clibrary.thirdparty" name="freetype" rev="5.0.0"/>

1. From `<bsp>/freetype_support/src/wrappers`, add all c files to the list of compiled files.
2. Add these folders to your include directories list:
	* `<bsp>/thirdparty/freetype/include`
	* `<bsp>/thirdparty/freetype/src`
	* `<bsp>/freetype_support/src`
3. Add `FT_CONFIG_MODULES_H=<freetype/config/ftmodule.h>` define to the project.
4. Add `FT2_BUILD_LIBRARY` define to the project.
5. Build the project.

# Requirements

N/A.

# Dependencies

_All dependencies are retrieved transitively by MicroEJ Module Manager_.

# Source

Fork of Freetype 2.13.3.

# Restrictions

None.

---
_Copyright 2021-2026 MicroEJ Corp. This file has been modified and/or created by MicroEJ Corp._

_This file is part of the FreeType project, and may only be used,_\
_modified, and distributed under the terms of the FreeType project_\
_license, LICENSE.TXT.  By continuing to use, modify, or distribute_\
_this file you indicate that you have read the license and_\
_understand and accept it fully._
