# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [5.0.5] - 2026-10-08

### Changed

- Fetch the FreeType source of the GitHub repository from its submodule, which the README now initializes instead of cloning FreeType by hand.

## [5.0.4] - 2026-10-07

### Changed

- Describe in the README how to get the FreeType source and apply the patches, for an integration from the GitHub repository.
- List in the README the boards this C Module is tested on and the MISRA deviations of its support files.
- Regenerate `options.patch` against FreeType 2.14.1, so that `git apply` applies it with no fuzz; the patched files do not change.

## [5.0.3] - 2026-10-05

### Added

- Preserve the drawing destination's own error when it refuses a glyph, so a failure is no longer attributed to FreeType.

### Changed

- Require the C Module MicroVG 8.0.3.
- Log the FreeType heap through the log macros of the C Module MicroVG, without an empty line after each log.
- Complete the Doxygen documentation of `ftvector.h`, and align the README with the other MicroEJ C modules.

### Fixed

- Trace the FreeType heap when an allocation in it fails, which failed silently.
- Fix the CPU fault raised when loading a font on a target that requires aligned memory accesses.
- Remove the colored emoji support when `VG_FEATURE_FREETYPE_COLORED_EMOJI` is `0`, as documented.
- Fix the double free that a failed reallocation in the FreeType heap caused.

## [5.0.2] - 2026-09-15

### Changed

- Enable the uncrustify and cppcheck checks on the MicroEJ source files.

## [5.0.1] - 2026-02-02

### Fixed

- Values other than `1` for the `VG_FEATURE_FREETYPE_TTF` and `VG_FEATURE_FREETYPE_OTF` options generated compilation errors.  

## [5.0.0] - 2026-01-23

### Changed 

- Upgrade FreeType from the version 2.13.1 (2024-08-11) to the version 2.14.1 (2025-09-11).
- Make the C module compatible with the new option configuration of MicroVG C module 8.0.0 (requires the include directive VEE Port folder `config`).

## [4.0.0] - 2024-10-18

### Changed

- Upgrade FreeType from the version 2.11.0 (2021-07-18) to the version 2.13.3 (2024-08-11).
- Separate the original FreeType files from MicroEJ's files.
- Use the original FreeType directory layout.
- Add a patch file to override FreeType's memory management without modifying the original file.

### Migration Notes

This C module is compatible with the MicroVG C modules [8.0.1-9.0.0].

- Delete the directory `thirdparty/freetype`.
- Remove `thirdparty/freetype/inc` and `thirdparty/freetype/inc/ftvector` from your include path.
- Add `thirdparty/freetype/include`, `thirdparty/freetype/src` and `freetype_support/src` to your include path.
- Remove `thirdparty/freetype/lib/freetype.a` from your build path.
- Build FreeType and add the library and support files following the instructions in README.md.

## [3.0.0] - 2024-07-19

### Changed

- Depend on the C Module MicroVG 8.0.0.
- Make the Freetype port generic for MicroVG (`ftvector.c` uses `LLVG_PATH_impl.h` API).
- [OTF] Use Freetype heap to allocate big objects instead of allocating them on the current task stack.

## [2.0.2] - 2022-09-09

### Fixed

- Fix license and copyrights.

## [2.0.1] - 2022-09-05

### Fixed

- Fix license file.

## [2.0.0] - 2022-09-02

### Updated

- Rework code organisation to configure the C Module from microvg_configuration.h file.

## [1.0.0] - 2021-12-02

### Added

- C Module creation from Freetype 2.11.0 version.

---
_Copyright 2021-2026 MicroEJ Corp. This file has been modified and/or created by MicroEJ Corp._

_This file is part of the FreeType project, and may only be used,_\
_modified, and distributed under the terms of the FreeType project_\
_license, LICENSE.TXT.  By continuing to use, modify, or distribute_\
_this file you indicate that you have read the license and_\
_understand and accept it fully._\
_Build: 7E4D1F7C_
