# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

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

- Depend on the CCO MicroVG 8.0.0.
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

- Rework code organisation to configure the CCO from microvg_configuration.h file.


## [1.0.0] - 2021-12-02

### Added

- CCO creation from Freetype 2.11.0 version.

---
_Copyright 2021-2024 MicroEJ Corp. This file has been modified and/or created by MicroEJ Corp._

_This file is part of the FreeType project, and may only be used,_\
_modified, and distributed under the terms of the FreeType project_\
_license, LICENSE.TXT.  By continuing to use, modify, or distribute_\
_this file you indicate that you have read the license and_\
_understand and accept it fully._
