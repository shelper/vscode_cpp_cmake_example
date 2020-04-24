This template has two branches: `master`(also aliased to `conan`) and vcpkg, each should work with its pkg management software.

For vcpkg, you need to add the following settings to your cmake configuration in your .vscode/settings.json
```
"cmake.configureSettings": {
    "CMAKE_TOOLCHAIN_FILE": "${env:vcpkgRoot}/scripts/buildsystems/vcpkg.cmake"
},
```

For conan, you need to make sure the conan config is right for you to use features like c++17, for example:
Configuration for profile default:
```
[settings]
os=Linux
os_build=Linux
arch=x86_64
arch_build=x86_64
compiler=gcc
compiler.version=9
compiler.libcxx=libstdc++11 # default was libstdc++, which does not support c++11 or newer
build_type=Release
[options]
[build_requires]
[env]
```