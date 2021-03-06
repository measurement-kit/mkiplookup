# Measurement Kit IP lookup library

[![GitHub license](https://img.shields.io/github/license/measurement-kit/mkiplookup.svg)](https://raw.githubusercontent.com/measurement-kit/mkiplookup/master/LICENSE) [![Github Releases](https://img.shields.io/github/release/measurement-kit/mkiplookup.svg)](https://github.com/measurement-kit/mkiplookup/releases) [![Build Status](https://img.shields.io/travis/measurement-kit/mkiplookup/master.svg?label=travis)](https://travis-ci.org/measurement-kit/mkiplookup) [![codecov](https://codecov.io/gh/measurement-kit/mkiplookup/branch/master/graph/badge.svg)](https://codecov.io/gh/measurement-kit/mkiplookup) [![Build status](https://img.shields.io/appveyor/ci/bassosimone/mkiplookup/master.svg?label=appveyor)](https://ci.appveyor.com/project/bassosimone/mkiplookup/branch/master)

IP lookup library for Measurement Kit. This is a basic building block whose
main use case is being vendored inside Measurement Kit. As such, we don't
aim for a stable API here, and we'll never release `v1.0.0`.

## Regenerating build files

Possibly edit `MKBuild.yaml`, then run:

```
go get -v github.com/measurement-kit/mkbuild
mkbuild
```

## Building

```
mkdir build
cd build
cmake -GNinja ..
cmake --build .
ctest -a -j8 --output-on-failure
```

## Testing with docker

```
./docker.sh <build-type>
```
