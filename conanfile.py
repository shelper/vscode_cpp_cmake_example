from conans import ConanFile, CMake


class VscodeCppCmakeConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "opencv/4.3.0@conan/stable", "gtest/1.10.0"
    generators = "cmake"

    def configure(self):
        if self.settings.os == "Linux":
            self.options["opencv"].gtk = 3

        if (
            self.settings.compiler in ["gcc", "clang"]
            and self.settings.compiler.libcxx == "libstdc++"
        ):
            # conanfile.py can only modify local package options but not global settings
            # thus you cannot modify settings.compiler.libcxx and have to raise an exception
            raise Exception(
                "This package is only compatible with libstdc++11, try to run `conan profile update settings.compiler.libcxx=libstdc++11 default` to fix it"
            )
