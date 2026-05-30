# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

## [2026-05-30]

### Added
- `loading.png` asset (was referenced in `map1.tmx` but missing from `assets/gfx/`)
- `DST_ElectroRock.mp3` and `DST_Announce.mp3` converted from OGG
- `CHANGELOG.md`

### Fixed
- `GameStateMachine::popState()` called `resume()` on an empty state stack after `pop_back()`, causing a crash
- `SoundManager` was missing `Mix_Init` / `Mix_Quit` calls required by SDL_mixer 2.x; sample rate updated from 22050 to 44100
- `TextureManager::clearFromTextureMap()` did not call `SDL_DestroyTexture` before erasing, leaking GPU memory
- Makefile had a stray `#!/bin/sh` shebang (invalid in a Makefile)
- Makefile had a stray `-isystem` flag with no path argument
- Makefile had `test` target defined twice
- Makefile used old-style `.cpp.o` suffix rule which failed to rebuild object files reliably; replaced with `%.o: %.cpp` pattern rule
- Makefile `clean` rule used `$(shell find . -name "*.o")` which expanded unreliably; replaced with explicit `src/*.o specs/*.o main.o`

## [2023-01-01]

### Changed
- Renamed `tests/` to `specs/` and `data/` to `assets/`
- Improved `DATA_PREFIX` usage throughout
- General code cleanup and refactoring
